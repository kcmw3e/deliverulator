// ============================================================================================== //
// Primary author: Mya Chappel
//
// Robots can be assigned paths and orders to accomplish. They are the main interactable/controllabe
// object in the delivery system. They will automatically follow the path assigned to them and
// attempt to complete the order they have been given.
// ============================================================================================== //

#if !defined(ROBOT_H)
#define ROBOT_H

#include "order.h"
#include <iostream>
#include <vector>

//not sending anything anywhere
//receiving from Path Planner and UI

/*
Class Robot
	x,y coordinates
	ID
	path (list of nodes to follow)
	order ID
	draw robot

	movement speed
		function tick (update)
*/

/* Questions:
	What data type for ID?

*/

class Robot
{
protected:
	float x = 400, y = 300;
	float speed = 1;

public:
	int ID;

	std::vector<float> path; //this will come from path planner

	int order_ID; //this will come from UI

	void drawRobot(void);
	int updatePos(void);

};

#endif // !defined(ROBOT_H)
