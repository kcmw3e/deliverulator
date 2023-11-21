// ============================================================================================== //
// Primary author: Mya Chappel
//
// Robots can be assigned paths and orders to accomplish. They are the main interactable/controllabe
// object in the delivery system. They will automatically follow the path assigned to them and
// attempt to complete the order they have been given.
// ============================================================================================== //

#if !defined(ROBOT_H)
#define ROBOT_H

#include "path-planner.h"
#include "order.h"
#include "map.h"

class Robot {
    static constexpr double speed = 0.0;

    double x;
    double y;
    Order* order;
    Path path;
    Map::Node* last_dest;
public:
    void draw();
    void tick();
    void assign_order(Order* order);
};

#endif // !defined(ROBOT_H)
