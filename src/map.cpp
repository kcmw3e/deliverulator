// ============================================================================================== //
// Primary author: Eric Zhao
// ============================================================================================== //

#include "fssimplewindow.h" // includes OpenGL, takes care of different OS locations

#include "map.h"

namespace Map {
    Node::Node(double x, double y, std::string name)
    : x(x),
      y(y),
      name(name) { }

    Node::Node(const Node& node, std::vector<const Node*> neighbors)
    : x(node.x),
      y(node.y),
      name(node.name),
      neighbors(neighbors) { }

    void draw() {
        glPointSize(8);
        glColor3ub(0, 0, 0);
        glBegin(GL_POINTS);
        for (const auto& node : Map::nodes)
            glVertex2i(node.x, node.y);
        glEnd();

        // draw connections between nodes
        glColor3ub(0, 0, 0);
        glBegin(GL_LINES);
        for (const auto& node : Map::nodes) {
            for (const auto& neighbor : node.neighbors) {
                glVertex2i(node.x, node.y);
                glVertex2i(neighbor->x, neighbor->y);
            }
        }
        glEnd();
    }
}
