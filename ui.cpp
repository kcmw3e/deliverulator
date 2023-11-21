#include "ui.h"
#include "map.h"
#include "order.h"
#include "robot.h"
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <vector>
#include "fssimplewindow.h"
#include "ysglfontdata.h"

void UI::generateOrder(void)
{
	Order* o = new Order;

	int l = Map::buildings_len; //get from map
	int n1 = rand() % l;
	int n2 = rand() % l;
	while (n1 == n2) {
		n2 = rand() % l;
	}
	o->source = Map::buildings[n1];
	o->destination = Map::buildings[n2];
	o->orderNum = next_order_id;
	next_order_id += 1;
	orders.push_back(o);
}

void UI::tick()
{
	for (Robot r : robots) {
		r.tick();
	}
	if (orders.size() < 10) {
		generateOrder();
	}
}

void UI::assignOrder(Robot rob, Order* ord)
{
	if (rob.ord == NULL)
	{
		rob.assign_order(ord);
	}
}

void drawBorder(double x, double y, double w, double h)
{
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2d(x, y);
	glVertex2d(x + w, y);
	glVertex2d(x + w, y + h);
	glVertex2d(x, y + h);
	glEnd();
}

void drawOrderTable(double borderX, double borderY, double w, double h, Order o)
{
	drawBorder(borderX, borderY, w, h);
	glColor3f(0, 0, 0);
	double textY = borderY + 30;
	std::string s1 = "Order No." + std::to_string(o.orderNum) + "\t- " + o.source->name + " to " + o.destination->name;
	glRasterPos2i(borderX + 40, textY);
	YsGlDrawFontBitmap12x16(s1.c_str());
}

void drawRobotTable(double borderX, double borderY, double w, double h, Robot r)
{
	drawBorder(borderX, borderY, w, h);
	if (r.ord == NULL) {
		glColor3f(0, 0, 0);
	}
	else { // busy robots are listed in red
		glColor3f(1, 0, 0);
	}

	double textY = borderY + 30;
	std::string s1 = "Robot ID: " + std::to_string(r.id);
	glRasterPos2i(borderX + 40, textY);
	YsGlDrawFontBitmap12x16(s1.c_str());
}

void UI::draw() {
	double H = Map::h;
	double refX = Map::w;
	double orderX = refX + 200;
	double tableY = 50;

	double spacing = 40;
	double orderW = 300;
	double robotW = 200;

	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2d(refX, 0);
	glVertex2d(refX, H);
	glVertex2d(refX + robotW, 0);
	glVertex2d(refX + robotW, H);
	glVertex2d(refX, tableY);
	glVertex2d(refX + 500, tableY);
	glEnd();

	glColor3f(0, 0, 0);
	glRasterPos2i(refX + 40, 40);
	YsGlDrawFontBitmap20x28("Robots");

	glColor3f(0, 0, 0);
	glRasterPos2i(refX + 280, 40);
	YsGlDrawFontBitmap20x28("Orders");

	for (int i = 0; i < std::size(robots); i++)
	{
		drawRobotTable(refX, tableY + i * spacing, robotW, spacing, robots[i]);
	}

	for (int i = 0; i < orders.size(); i++)
	{
		drawOrderTable(orderX, tableY + i * spacing, orderW, spacing, *orders[i]);
	}
}