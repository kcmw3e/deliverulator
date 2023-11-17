// ============================================================================================== //
// Primary author: Rubin Chen and Casey Walker
// ============================================================================================== //

#include "ui.h"

UI::UI() { }

void UI::tick() {
    FsPollDevice();
    this->win.update();
    this->win.update_viewport();
    this->mouse.update();
    FSSF::Key::update();
}

void UI::handle_input() {
    if (this->kill.is_pressed()) {
        this->is_running = false;
        return;
    }
}

void UI::draw() const {
    for (auto robot: this->robots)
        robot.draw();
}

void UI::init() {
    this->win.open();
    this->is_running = true;
}

void UI::run() {
    this->init();

    while (this->is_running) {
        this->tick();
        this->handle_input();
        this->draw();
    }
}
