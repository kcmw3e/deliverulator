// ============================================================================================== //
// Primary author: Atharva Manohar Mhaskar
//
// The path planner can take two nodes from the map and identify a path between them as a series of
// nodes to follow.
// ============================================================================================== //

#if !defined(PATH_PLANNER_H)
#define PATH_PLANNER_H

#include "map.h"

using Path = std::vector<const Map::Node*>;

Path path_planner(const Map::Node* start, const Map::Node* src, const Map::Node* dest);

#endif // !defined(PATH_PLANNER_H)
