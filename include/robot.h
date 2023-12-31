// ============================================================================================== //
// Primary author: Mya Chappel
//
// Robots can be assigned paths and orders to accomplish. They are the main interactable/controllabe
// object in the delivery system. They will automatically follow the path assigned to them and
// attempt to complete the order they have been given.
// ============================================================================================== //

#if !defined(ROBOT_H)
#define ROBOT_H

#include <string>

#include "path-planner.h"
#include "order.h"
#include "map.h"

class Robot {
    static constexpr double speed = 1;

    double x;
    double y;
    const Order* order;
    Path path;
    const Map::Node* last_dest;
public:
    const std::string id;

    Robot(std::string id, const Map::Node* start);
    void draw() const;
    void tick();
    void assign_order(Order* order);
    bool is_busy() const;
};

#endif // !defined(ROBOT_H)
