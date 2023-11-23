// ============================================================================================== //
// Primary author: Eric Zhao
// ============================================================================================== //

#include "fssimplewindow.h" // includes OpenGL, takes care of different OS locations

#include "config.h"

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

        Config::Colors::node.set_as_gl_color();

        glPointSize(Node::rad);
        glBegin(GL_POINTS);
        for (const auto& node : Map::nodes)
            glVertex2i(node.x, node.y);
        glEnd();

        // draw connections between nodes
        glBegin(GL_LINES);
        for (const auto& node : Map::nodes) {
            for (const auto& neighbor : node.neighbors) {
                glVertex2i(node.x, node.y);
                glVertex2i(neighbor->x, neighbor->y);
            }
        }
        glEnd();
    }

    const Node* find_node(std::string name) {
        for (auto& node : nodes)
            if (node.name == name)
                return &node;

        return nullptr;
    }
}

