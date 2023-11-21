// ============================================================================================== //
// Primary author: Rubin Chen and Casey Walker
//
// An order consists of a source node and destination node from the map as well as an order ID to
// distincly identify itself.
// ============================================================================================== //

#if !defined(ORDER_H)
#define ORDER_H

#include <cstddef>

#include "map.h"

struct Order {
    const Map::Node& src;
    const Map::Node& dest;
    const int id;
};

#endif // !defined(ORDER_H)
