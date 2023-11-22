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

void UI::draw() const {
    double ref_x = Map::w;
    double order_x = ref_x + 200;
    double table_y = 50;
    double spacing = 40;
    double order_w = 300;
    double robot_w = 200;

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2d(ref_x, 0);
    glVertex2d(ref_x, Map::h);
    glVertex2d(ref_x + robot_w, 0);
    glVertex2d(ref_x + robot_w, Map::h);
    glVertex2d(ref_x, table_y);
    glVertex2d(ref_x + 500, table_y);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(ref_x + 40, 40);
    YsGlDrawFontBitmap20x28("Robots");

    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(ref_x + 280, 40);
    YsGlDrawFontBitmap20x28("Orders");

    for (size_t i = 0; i < std::size(this->robots); i++)
        Prims::table_cell(
                ref_x, table_y + i*spacing, robot_w, spacing, 1.0, Colors::red,
                robots[i].id, Colors::white
        );

    for (size_t i = 0; i < orders.size(); i++)
        Prims::table_cell(
            order_x, table_y + i*spacing, order_w, spacing, 1.0, Colors::red,
            std::to_string(orders[i]->id), Colors::white
        );

    for (auto robot: this->robots)
        robot.draw();
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

UI::UI() { }

void UI::run() {
    this->init();

    while (this->is_running) {
        this->tick();
        this->handle_input();
        this->draw();
    }
}
