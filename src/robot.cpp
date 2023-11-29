// ============================================================================================== //
// Primary author: Mya Chappell
// ============================================================================================== //

#include "robot.h"
#include "fssimplewindow.h"
#include <iostream>
#include <cmath>

const double YsPi = 3.1415927;

Robot::Robot(std::string id, const Map::Node* start)
: x(start->x),
  y(start->y),
  order(nullptr),
  last_dest(start),
  id(id) {

}

void drawRobotLeg(double legX, double y, double width, double height, bool color)
{
    glColor3ub(0, 0, 0);
    int rad5 = width / 22;
    double sx5 = legX - width / 3;
    double sy5 = y + height / 7;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 64; i++)
    {
        double angle = (double)i * YsPi / 32.0;
        double cx = (double)sx5 + cos(angle) * (double)rad5;
        double cy = (double)sy5 + sin(angle) * (double)rad5;
        glVertex2d(cx, cy);
    }
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(legX - width / 3 - width / 21.4, y + height / 7);
    glVertex2f(legX - width / 3 - width / 5, y + height / 7 - width / 4.3);
    glVertex2f(legX - width / 3 - width / 7.5, y + height / 7 - width / 4.3);
    glVertex2f(legX - width / 3 + width / 21.4, y + height / 7);
    glEnd();

    if (color == true)
    {
        glColor3ub(255, 220, 0);
    }
    else
    {
        glColor3ub(0, 0, 0);
    }

    glBegin(GL_POLYGON);
    glVertex2f(legX - width / 3 - width / 5, y + height / 7 - width / 4.3);
    glVertex2f(legX - width / 3 - width / 7.5, y + height / 7 - width / 4.3);
    glVertex2f(legX - width / 3 + width / 21.4 - width / 30, y + height / 7 - width / 2.5);
    glVertex2f(legX - width / 3 - width / 21.4 - width / 30, y + height / 7 - width / 2.5);
    glEnd();

    glColor3ub(0, 0, 0);
    int rad6 = width / 20;
    double sx6 = legX - width / 3 - width / 35; //- width / 30;
    double sy6 = y + height / 7 - width / 2.5;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 64; i++)
    {
        double angle = (double)i * YsPi / 32.0;
        double cx = (double)sx6 + cos(angle) * (double)rad6;
        double cy = (double)sy6 + sin(angle) * (double)rad6;
        glVertex2d(cx, cy);
    }
    glEnd();
}

void Robot::draw() const {
    double width = 40; //150
    double height = width / 5;

    drawRobotLeg(x + width / 1.4, y, width, height, false); //back right leg
    drawRobotLeg(x + width / 10, y, width, height, false); //back left leg

    //body
    glColor3ub(255, 220, 0);
    glBegin(GL_POLYGON);
    glVertex2f(x - width / 2, y + height / 2);
    glVertex2f(x + width / 2, y + height / 2);
    glVertex2f(x + width / 2 - (width / 10), y - height / 2);
    glVertex2f(x - width / 2 + (width / 20), y - height / 2);
    glEnd();

    drawRobotLeg(x, y, width, height, true); //front left leg
    drawRobotLeg(x + width / 1.667, y, width, height, true); //front right leg

}

void Robot::tick() {
    if (path.empty())
    {
        this->order = nullptr;
        return;
    }

    //x and y of next node
    float nodeX = path[0]->x;
    float nodeY = path[0]->y;

    if (nodeX == std::round(x) && nodeY == std::round(y))
        path.erase(path.begin());

    //find travel direction
    float dirX = nodeX - x;
    float dirY = nodeY - y;

    // Calculate the distance from the cloud to the target
    float distance = sqrt(dirX * dirX + dirY * dirY);

    // Normalize the direction vector
    if (distance > 0) {
        dirX /= distance;
        dirY /= distance;
    }

    // Update the cloud's position by moving it in the direction of the target
    x += speed * dirX;
    y += speed * dirY;
}

void Robot::assign_order(Order* order) {
    this->order = order;
    this->path = path_planner(*this->last_dest, order->src, order->dest);
}

bool Robot::is_busy() const {
    return this->order != nullptr;
}
