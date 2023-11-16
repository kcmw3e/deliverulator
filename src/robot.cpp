// ============================================================================================== //
// Primary author: Mya Chappell
// ============================================================================================== //

#include "robot.h"
#include "fssimplewindow.h"
#include <iostream>
#include <cmath>


const double YsPi = 3.1415927;


void Robot::drawRobot(void)
{

	float width = 50; //150
	float height = width / 5;

	/***********************************************************/
	//back right leg
	float legX = x + width / 1.4;

	glColor3ub(0, 0, 0);
	int rad5 = width / 22;
	double sx5 = legX - width / 3;
	double sy5 = y - height / 7;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 64; i++)
	{
		double angle = (double)i * YsPi / 32.0;
		double cx = (double)sx5 + cos(angle) * (double)rad5;
		double cy = (double)sy5 + sin(angle) * (double)rad5;
		glVertex2d(cx, cy);
	}
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(legX - width / 3 - width / 21.4, y - height / 7);
	glVertex2f(legX - width / 3 - width / 5, y - height / 7 + width / 4.3);
	glVertex2f(legX - width / 3 - width / 7.5, y - height / 7 + width / 4.3);
	glVertex2f(legX - width / 3 + width / 21.4, y - height / 7);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(legX - width / 3 - width / 5, y - height / 7 + width / 4.3);
	glVertex2f(legX - width / 3 - width / 7.5, y - height / 7 + width / 4.3);
	glVertex2f(legX - width / 3 + width / 21.4 - width / 30, y - height / 7 + width / 2.5);
	glVertex2f(legX - width / 3 - width / 21.4 - width / 30, y - height / 7 + width / 2.5);
	glEnd();

	glColor3ub(0, 0, 0);
	int rad6 = width / 20;
	double sx6 = legX - width / 3 - width / 35; //- width / 30;
	double sy6 = y - height / 7 + width / 2.5;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 64; i++)
	{
		double angle = (double)i * YsPi / 32.0;
		double cx = (double)sx6 + cos(angle) * (double)rad6;
		double cy = (double)sy6 + sin(angle) * (double)rad6;
		glVertex2d(cx, cy);
	}
	glEnd();


	/***********************************************************/
	//back left leg
	legX = x + width / 10;

	glColor3ub(0, 0, 0);
	int rad7 = width / 22;
	double sx7 = legX - width / 3;
	double sy7 = y - height / 7;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 64; i++)
	{
		double angle = (double)i * YsPi / 32.0;
		double cx = (double)sx7 + cos(angle) * (double)rad7;
		double cy = (double)sy7 + sin(angle) * (double)rad7;
		glVertex2d(cx, cy);
	}
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(legX - width / 3 - width / 21.4, y - height / 7);
	glVertex2f(legX - width / 3 - width / 5, y - height / 7 + width / 4.3);
	glVertex2f(legX - width / 3 - width / 7.5, y - height / 7 + width / 4.3);
	glVertex2f(legX - width / 3 + width / 21.4, y - height / 7);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(legX - width / 3 - width / 5, y - height / 7 + width / 4.3);
	glVertex2f(legX - width / 3 - width / 7.5, y - height / 7 + width / 4.3);
	glVertex2f(legX - width / 3 + width / 21.4 - width / 30, y - height / 7 + width / 2.5);
	glVertex2f(legX - width / 3 - width / 21.4 - width / 30, y - height / 7 + width / 2.5);
	glEnd();

	glColor3ub(0, 0, 0);
	int rad8 = width / 20;
	double sx8 = legX - width / 3 - width / 35; //- width / 30;
	double sy8 = y - height / 7 + width / 2.5;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 64; i++)
	{
		double angle = (double)i * YsPi / 32.0;
		double cx = (double)sx8 + cos(angle) * (double)rad8;
		double cy = (double)sy8 + sin(angle) * (double)rad8;
		glVertex2d(cx, cy);
	}
	glEnd();

	/***********************************************************/
	//body
	glColor3ub(255, 220, 0);
	glBegin(GL_POLYGON);
	glVertex2f(x - width / 2, y - height / 2);
	glVertex2f(x + width / 2, y - height / 2);
	glVertex2f(x + width / 2 - (width / 10), y + height / 2);
	glVertex2f(x - width / 2 + (width / 20), y + height / 2);
	glEnd();

	/***********************************************************/
	//left leg
	glColor3ub(0, 0, 0);
	int rad1 = width / 22;
	double sx = x - width / 3;
	double sy = y - height / 7;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 64; i++)
	{
		double angle = (double)i * YsPi / 32.0;
		double cx = (double)sx + cos(angle) * (double)rad1;
		double cy = (double)sy + sin(angle) * (double)rad1;
		glVertex2d(cx, cy);
	}
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(x - width / 3 - width / 21.4, y - height / 7);
	glVertex2f(x - width / 3 - width / 5, y - height / 7 + width / 4.3);
	glVertex2f(x - width / 3 - width / 7.5, y - height / 7 + width / 4.3);
	glVertex2f(x - width / 3 + width / 21.4, y - height / 7);
	glEnd();

	//glColor3ub(255, 220, 0);
	//glBegin(GL_POLYGON);
	//glVertex2f(x - width / 3 - width / 21.4+0.5, y - height / 7);
	//glVertex2f(x - width / 3 - width / 5+0.5, y - height / 7 + width / 4.3); 
	//glVertex2f(x - width / 3 - width / 7.5, y - height / 7 + width / 4.3); 
	//glEnd();

	glColor3ub(255, 220, 0);
	glBegin(GL_POLYGON);
	glVertex2f(x - width / 3 - width / 5, y - height / 7 + width / 4.3);
	glVertex2f(x - width / 3 - width / 7.5, y - height / 7 + width / 4.3);
	glVertex2f(x - width / 3 + width / 21.4 - width / 30, y - height / 7 + width / 2.5);
	glVertex2f(x - width / 3 - width / 21.4 - width / 30, y - height / 7 + width / 2.5);
	glEnd();

	glColor3ub(0, 0, 0);
	int rad2 = width / 20;
	double sx2 = x - width / 3 - width / 35; //- width / 30;
	double sy2 = y - height / 7 + width / 2.5;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 64; i++)
	{
		double angle = (double)i * YsPi / 32.0;
		double cx = (double)sx2 + cos(angle) * (double)rad2;
		double cy = (double)sy2 + sin(angle) * (double)rad2;
		glVertex2d(cx, cy);
	}
	glEnd();

	/***********************************************************/
	//right leg
	legX = x + width / 1.667;

	glColor3ub(0, 0, 0);
	int rad4 = width / 22;
	double sx4 = legX - width / 3;
	double sy4 = y - height / 7;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 64; i++)
	{
		double angle = (double)i * YsPi / 32.0;
		double cx = (double)sx4 + cos(angle) * (double)rad4;
		double cy = (double)sy4 + sin(angle) * (double)rad4;
		glVertex2d(cx, cy);
	}
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(legX - width / 3 - width / 21.4, y - height / 7);
	glVertex2f(legX - width / 3 - width / 5, y - height / 7 + width / 4.3);
	glVertex2f(legX - width / 3 - width / 7.5, y - height / 7 + width / 4.3);
	glVertex2f(legX - width / 3 + width / 21.4, y - height / 7);
	glEnd();

	//glColor3ub(255, 220, 0);
	//glBegin(GL_POLYGON);
	//glVertex2f(legX - width / 3 - width / 21.4 + 0.5, y - height / 7);
	//glVertex2f(legX - width / 3 - width / 5 + 0.5, y - height / 7 + width / 4.3);
	//glVertex2f(legX - width / 3 - width / 7.5, y - height / 7 + width / 4.3);
	//glEnd();

	glColor3ub(255, 220, 0);
	glBegin(GL_POLYGON);
	glVertex2f(legX - width / 3 - width / 5, y - height / 7 + width / 4.3);
	glVertex2f(legX - width / 3 - width / 7.5, y - height / 7 + width / 4.3);
	glVertex2f(legX - width / 3 + width / 21.4 - width / 30, y - height / 7 + width / 2.5);
	glVertex2f(legX - width / 3 - width / 21.4 - width / 30, y - height / 7 + width / 2.5);
	glEnd();

	glColor3ub(0, 0, 0);
	int rad3 = width / 20;
	double sx3 = legX - width / 3 - width / 35; //- width / 30;
	double sy3 = y - height / 7 + width / 2.5;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 64; i++)
	{
		double angle = (double)i * YsPi / 32.0;
		double cx = (double)sx3 + cos(angle) * (double)rad3;
		double cy = (double)sy3 + sin(angle) * (double)rad3;
		glVertex2d(cx, cy);
	}
	glEnd();


}


int Robot::updatePos(void)
{

	if (path.empty())
	{
		return 1;
	}

	//x and y of next node
	float nodeX = path[0];
	float nodeY = path[1];

	if (nodeX == std::round(x) && nodeY == std::round(y))
	{
		path.erase(path.begin(), path.begin() + 2);
	}

	//find travel direction
	float dirX = nodeX - x;
	float dirY = nodeY - y;

	// Calculate the distance from the cloud to the target
	float distance = sqrt(dirX * dirX + dirY * dirY);

	// Normalize the direction vector
	if (distance > 0)
	{
		dirX /= distance;
		dirY /= distance;
	}

	// Update the cloud's position by moving it in the direction of the target
	x += speed * dirX;
	y += speed * dirY;

	return 0;

}

