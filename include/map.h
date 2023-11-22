// ============================================================================================== //
// Primary author: Eric Zhao
//
// CMU's campus map is represented as a series of connected nodes (e.g. a graph). Every intersection
// and building is considered a node as might be expected, but for the sake of simplicity in terms
// of moving a robot along the screen, there are also nodes for the turns in a path. This way a
// robot only needs to know the path it is on between two nodes, and it can follow along the screen
// by simply drawing itself somewhere on the line between these paths, and it can follow turns by
// adjusting the nodes it is between.
//
// There is no real distinction between buildings/points of interest and general nodes (e.g. a node
// at an intersection or curve) besides the static member within the Map class that identifies them.
// ============================================================================================== //

#if !defined(MAP_H)
#define MAP_H

#include <vector>
#include <string>

namespace Map {
    struct Node {
        static constexpr double rad = 1.0;

        const double x;
        const double y;
        const std::string name;
        const std::vector<const Node*> neighbors;
    };

    static const Node nodes[] = {
        Node{0.1, 2.3, "foo", {nodes + 0, nodes + 1, nodes + 2}},
        Node{4.5, 6.7, "bar", {nodes + 2}},
        Node{8.9, 0.1, "baz", {nodes + 2}},
    };
    static const size_t nodes_len = std::size(nodes);

    static const Node* buildings[] = {
        nodes + 0,
        nodes + 2,
    };
    static const size_t buildings_len = std::size(buildings);

    static const double w = 700;
    static const double h = 700;

    static const std::string map_filename = "resrc/map.png";

    void draw();
};

#endif // !defined(MAP_H)
