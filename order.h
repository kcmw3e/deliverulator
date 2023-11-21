#if !defined(ORDER_H)
#define ORDER_H

#include "map.h"

struct Order {
	const Map::Node* source;
	const Map::Node* destination;
	int orderNum;
};

#endif // !defined(ORDER_H)

