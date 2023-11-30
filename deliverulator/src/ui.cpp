// ============================================================================================== //
// Primary author: Rubin Chen and Casey Walker
// ============================================================================================== //

#include "ysglfontdata.h"

#include "ui.h"
#include "primitives.h"
#include "rgba.h"
#include "config.h"

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

    if (this->nav_sel_mode.has_changed_to_pressed()) {
        if (this->sel_mode == UI::Sel_mode::ROBOT)
            this->sel_mode = UI::Sel_mode::ORDER;
        else
            this->sel_mode = UI::Sel_mode::ROBOT;
    }

    size_t* sel = &this->robot_sel;
    size_t sel_max = std::size(this->robots);

    if (this->sel_mode == UI::Sel_mode::ORDER)
        sel = &this->order_sel, sel_max = this->orders.size();

    if (this->nav_up.has_changed_to_pressed()) {
        if (*sel == 0)
            *sel = sel_max - 1;
        else
            (*sel)--;
    }

    if (this->nav_down.has_changed_to_pressed()) {
        (*sel)++;
        if (*sel == sel_max)
            *sel = 0;
    }

    if (this->assign.has_changed_to_pressed())
        this->assign_order();
}

void UI::draw_table() const {
    double cell_w = Config::Table::cell_w;
    double cell_h = Config::Table::cell_h;
    double cell_bw = Config::Table::cell_bw;
    auto text_color = Config::Colors::text;
    auto text_active_color = Config::Colors::text_active;
    auto cell_border_color = Config::Colors::cell_border;
    auto sel_order_color = Config::Colors::sel;
    auto sel_robot_color = Config::Colors::sel;

    if (this->sel_mode == UI::Sel_mode::ROBOT)
        sel_order_color = Config::Colors::sel_alt;
    else
        sel_robot_color = Config::Colors::sel_alt;

    double x = this->map_img.w;
    double y = this->map_img.h - cell_h;

    Prims::table_cell(x, y, cell_w, cell_h, cell_bw, cell_border_color, "Robots", text_color);

    for (size_t i = 0; i < std::size(this->robots); i++) {
        if (this->robot_sel == i)
            Prims::rect(x, y - (i + 1)*cell_h, cell_w, cell_h, sel_robot_color);

        Prims::table_cell(
                x, y - (i + 1)*cell_h, cell_w, cell_h, cell_bw, cell_border_color,
                robots[i].id, robots[i].is_busy() ? text_active_color : text_color
        );
    }

    x += cell_w;

    Prims::table_cell(x, y, cell_w, cell_h, cell_bw, cell_border_color, "Orders", text_color);
    for (size_t i = 0; i < orders.size(); i++) {
        if (this->order_sel == i)
            Prims::rect(x, y - (i + 1)*cell_h, cell_w, cell_h, sel_order_color);

        std::string str = "[" + std::to_string(orders[i]->id) + "]"
                        + " (" + orders[i]->src.name + "->" + orders[i]->dest.name + ")";
        Prims::table_cell(
            x, y - (i + 1)*cell_h, cell_w, cell_h, cell_bw, cell_border_color, str, text_color
        );
    }

    for (auto robot: this->robots)
        robot.draw();
}

void UI::draw() const {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, this->win.viewport.w, 0, this->win.viewport.h, -1.0, 1.0);

    Config::Colors::bg.set_as_gl_clear_color();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    this->map_img.draw();
    this->draw_table();
    Map::draw();

    FsSwapBuffers();
}

void UI::generate_order() {
    int l = Map::buildings.size(); //get from map
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

void UI::assign_order() {
    auto& robot = this->robots[this->robot_sel];

    if (!robot.is_busy() && !this->orders.empty()) {
        auto order = this->orders[this->order_sel];
        this->orders.erase(this->orders.begin() + this->order_sel);
        robot.assign_order(order);
    }
}

UI::UI()
: map_img(YSSF::Raw_rgba_img::from_file(Map::map_filename)),
  win(map_img.w + Config::Table::cell_w*2, map_img.h) { }

void UI::run() {
    this->init();
    int currentTime = time(NULL);
    srand(currentTime);
    while (this->is_running) {
        this->tick();
        this->handle_input();
        this->draw();
    }
}
