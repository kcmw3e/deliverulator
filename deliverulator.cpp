// ============================================================================================== //
// A delivery simulator/game for 24-780 Engineering Compuation final project at Carnegie Mellon
// University.
//
// Group members:
// 	- Mya Chappell
// 	- Atharva Manohar Mhaskar
// 	- Casey Walker
// 	- Eric Zhao
// 	- Rubin Chen
// ============================================================================================== //

#include <iostream>
#include "map.h"
#include "robot.h"
#include "order.h"
#include "path-planner.h"
#include "ui.h"
#include "fssimplewindow.h"
#include <random>



void printVector(std::vector<float> Vec)
{
    for (int element : Vec)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void randomPathVec(std::vector<float>& path)
{
    // Seed the random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define the range of random numbers
    std::uniform_int_distribution<int> distribution800(0, 800);
    std::uniform_int_distribution<int> distribution600(0, 600);

    for (int i = 0; i < 4; ++i)
    {
        // Generate and print the first random number
        int x = distribution800(gen);
        // Generate and print the second random number
        int y = distribution600(gen);

        path.push_back(x);
        path.push_back(y);
    }
}

int main()
{
    Robot robot[2]; //for now just doing 2 robots

    //create robot ID
    robot[0].ID = 1;
    robot[1].ID = 2;


    //this is placeholder for path planner
    randomPathVec(robot[0].path);
    //printVector(robot[0].path);
    randomPathVec(robot[1].path);

    FsOpenWindow(0, 0, 800, 600, 1);

    while (FSKEY_NULL == FsInkey())
    {
        FsPollDevice();

        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        //draw a robot
        robot[0].drawRobot();
        robot[1].drawRobot();

        //robot tick
        robot[0].updatePos();
        robot[1].updatePos();

        //this is placeholder for path planner
        if (robot[0].path.empty())
        {
            randomPathVec(robot[0].path);
            //printVector(robot[0].path);
        }
        if (robot[1].path.empty())
        {
            randomPathVec(robot[1].path);
        }

        FsSwapBuffers();

        FsSleep(10);
    }
    
    
    return 0;
}
