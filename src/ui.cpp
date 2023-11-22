// ============================================================================================== //
// Primary author: Rubin Chen and Casey Walker
// ============================================================================================== //

#include "ysglfontdata.h"

#include "ui.h"
#include "primitives.h"
#include "rgba.h"

namespace Prims = Primitives;

void UI::init() {
    this->win.open();
    this->is_running = true;
}

void UI::tick() {
    FsPollDevice();
    this->win.update();
    this->win.update_viewport();
    this->mouse.update();
    FSSF::Key::update();

    for (auto& robot: this->robots)
        robot.tick();

    if (orders.size() < 10)
        this->generate_order();

}

void UI::handle_input() {
    if (this->kill.is_pressed()) {
        this->is_running = false;
        return;
    }
}

void UI::draw_table() const {
    double cell_w = 200.0;
    double cell_h = 40.0;
    double border_w = 2.0;

    double x = this->map_img.w;
    double y = this->map_img.h - cell_h;

    Prims::table_cell(x, y, cell_w, cell_h, border_w, Colors::red, "Robots", Colors::white);

    for (size_t i = 0; i < std::size(this->robots); i++)
        Prims::table_cell(
                x, y - (i + 1)*cell_h, cell_w, cell_h, border_w, Colors::red,
                robots[i].id, Colors::white
        );

    x += cell_w;

    Prims::table_cell(x, y, cell_w, cell_h, border_w, Colors::red, "Orders", Colors::white);
    for (size_t i = 0; i < orders.size(); i++)
        Prims::table_cell(
            x, y - (i + 1)*cell_h, cell_w, cell_h, border_w, Colors::red,
            std::to_string(orders[i]->id), Colors::white
        );

    for (auto robot: this->robots)
        robot.draw();

}

void UI::draw() const {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, this->win.viewport.w, 0, this->win.viewport.h, -1.0, 1.0);

    Colors::black.set_as_gl_clear_color();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    this->map_img.draw();
    this->draw_table();

    FsSwapBuffers();
}

void UI::generate_order() {
    int l = Map::buildings_len; //get from map
    int n1 = rand() % l;
    int n2 = rand() % l;

    while (n1 == n2) {
        n2 = rand() % l;
    }

    Order* order = new Order{
        *Map::buildings[n1], *Map::buildings[n2], this->next_order_id
    };

    next_order_id += 1;
    orders.push_back(order);
}

UI::UI()
: map_img(YSSF::Raw_rgba_img::from_file(Map::map_filename)) { }

void UI::run() {
    this->init();

    while (this->is_running) {
        this->tick();
        this->handle_input();
        this->draw();
    }
}
