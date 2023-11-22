// ============================================================================================== //
// A delivery simulator/game for 24-780 Engineering Compuation final project at Carnegie Mellon
// University.
//
// Group members:
//      - Mya Chappell
//      - Atharva Manohar Mhaskar
//      - Casey Walker
//      - Eric Zhao
//      - Rubin Chen
// ============================================================================================== //

#include "fssimplewindow.h"

#include "map.h"
#include "robot.h"
#include "order.h"
#include "path-planner.h"
#include "ui.h"
#include "fssimplewindow.h"
#include <random>

int main() {
    FsChangeToProgramDir();

    UI ui;

    ui.run();

    return 0;
}
