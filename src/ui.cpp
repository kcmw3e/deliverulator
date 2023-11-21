// ============================================================================================== //
// Primary author: Rubin Chen and Casey Walker
// ============================================================================================== //

#include "ysglfontdata.h"

#include "ui.h"

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

void UI::draw_border(double x, double y, double w, double h) const {
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(x, y);
    glVertex2d(x + w, y);
    glVertex2d(x + w, y + h);
    glVertex2d(x, y + h);
    glEnd();
}

void UI::draw_robot_table(double x, double y, const Robot& robot) const {
    if (robot.is_busy())
        glColor3f(0.0, 0.0, 0.0);
    else
        glColor3f(1.0, 0.0, 0.0);

    double text_y = y + 30;
    std::string s = "Robot ID: " + robot.id;
    glRasterPos2i(x + 40, text_y);
    YsGlDrawFontBitmap12x16(s.c_str());
}

void UI::draw_order_table(double x, double y, const Order& order) const {
    glColor3f(0.0, 0.0, 0.0);
    double text_y = y + 30;
    std::string s = "Order No." + std::to_string(order.id) + "    - " + order.src.name + "to" + order.dest.name;
    glRasterPos2i(x + 40, text_y);
    YsGlDrawFontBitmap12x16(s.c_str());
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

    for (size_t i = 0; i < std::size(this->robots); i++) {
        this->draw_border(ref_x, table_y + i*spacing, robot_w, spacing);
        this->draw_robot_table(ref_x, table_y + i*spacing, robots[i]);
    }

    for (size_t i = 0; i < orders.size(); i++) {
        this->draw_border(order_x, table_y + i*spacing, order_w, spacing);
        this->draw_order_table(order_x, table_y + i*spacing, *orders[i]);
    }

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
