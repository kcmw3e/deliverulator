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
#include "yssimplefixes.h"

namespace FSSF = FSSimple_Fixes;
namespace YSSF = YSSimple_Fixes;

class UI {
private:
    enum Sel_mode {
        ORDER, ROBOT
    };

    Robot robots[5];
    std::vector<Order*> orders;
    int next_order_id = 0;
    size_t order_sel = 0;
    size_t robot_sel = 0;
    UI::Sel_mode sel_mode = ROBOT;
    YSSF::Raw_rgba_img map_img;

    FSSF::Window win;
    FSSF::Key kill = FSSF::Key(FSKEY_ESC);
    FSSF::Key nav_up = FSSF::Key(FSKEY_UP);
    FSSF::Key nav_down = FSSF::Key(FSKEY_DOWN);
    FSSF::Key nav_sel_mode = FSSF::Key(FSKEY_TAB);
    FSSF::Key assign = FSSF::Key(FSKEY_ENTER);
    FSSF::Mouse mouse = FSSF::Mouse();
    bool is_running = false;


    void init();
    void tick();
    void handle_input();
    void draw_table() const;
    void draw() const;
    void generate_order();
    void assign_order();
public:
    UI();
    void run();
};

#endif // !defined(UI_H)
