// ============================================================================================== //
// Primary author: Mya Chappel
// ============================================================================================== //

#include "robot.h"

void Robot::draw() const { }

void Robot::tick() { }

void Robot::assign_order(Order* order) { }

bool Robot::is_busy() const {
    return this->order == nullptr;
}
