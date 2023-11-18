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

using size_t = std::size_t;

struct Order {
    const Node& src;
    const Node& dest;
    const size_t id;
};

#endif // !defined(ORDER_H)
