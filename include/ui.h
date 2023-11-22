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
    FSSF::Window win = FSSF::Window(1500, 700);
    FSSF::Key kill = FSSF::Key(FSKEY_ESC);
    FSSF::Mouse mouse = FSSF::Mouse();
    bool is_running = false;

    Robot robots[5];
    std::vector<Order*> orders;
    int next_order_id = 0;
    YSSF::Raw_rgba_img map_img;

    void init();
    void tick();
    void handle_input();
    void draw_table() const;
    void draw() const;
    void generate_order();
public:
    UI();
    void run();
};

#endif // !defined(UI_H)
