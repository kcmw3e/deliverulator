#if !defined(UI_H)
#define UI_H

#include "map.h"
#include "order.h"
#include "robot.h"
#include <vector>


class UI
{
private:

	//std::vector<Order*> orders;
	int next_order_id = 1;
public:
	Robot robots[3];
	std::vector<Order*> orders;
	void generateOrder(void);
	void tick(void);
	void draw(void);
	void assignOrder(Robot r, Order* o);
};

#endif //
