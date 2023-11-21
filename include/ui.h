// ============================================================================================== //
// Primary author: Rubin Chen and Casey Walker
//
// The UI takes care of user interaction handling and generating, assigning, and completing orders.
// It is essentially the main logical structure in the delivery simulator.
// ============================================================================================== //

#if !defined(UI_H)
#define UI_H

#include "map.h"
#include "path-planner.h"
#include "order.h"
#include "robot.h"

#include "fssimplefixes.h"

namespace FSSF = FSSimple_Fixes;

class UI {
private:
    FSSF::Window win = FSSF::Window(800, 600);
    FSSF::Key kill = FSSF::Key(FSKEY_ESC);
    FSSF::Mouse mouse = FSSF::Mouse();
    bool is_running = false;

    Robot robots[5];
    std::vector<Order*> orders;
    int next_order_id = 0;

    void init();
    void tick();
    void handle_input();
    void draw_border(double x, double y, double w, double h) const;
    void draw_robot_table(double x, double y, const Robot& robot) const;
    void draw_order_table(double x, double y, const Order& order) const;
    void draw() const;
    void generate_order();
public:
    UI();
    void run();
};

#endif // !defined(UI_H)
