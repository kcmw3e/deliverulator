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

class Node;

class Map;

#endif // !defined(MAP_H)
