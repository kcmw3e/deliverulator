// ============================================================================================== //
// Primary author: Atharva Manohar Mhaskar
// ============================================================================================== //

#include "path-planner.h"

// Path path_planner(Map::Node& start, Map::Node& src, Map::Node& dest) { }

#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
// #include "ysglfontdata.h"
// #include "fssimplewindow.h"
#include <iostream>
#include <limits>
#include <cmath>

using namespace Map;

float getEdgeCost(const Node& fNode, const Node& sNode){
    float curDist = sqrt((sNode.y - fNode.y)*(sNode.y - fNode.y) + (sNode.x - fNode.x)*(sNode.x - fNode.x));
    return curDist;
}

struct PathInfo {
    const Node* prev;
    float distance;
    bool visited;

    PathInfo(){
        prev = NULL;
        distance = std::numeric_limits<float>::infinity();
        visited = false;
    }
};


struct NodeFloatPair {
    const Node* node;
    float dist;

    NodeFloatPair(const Node* nodePtr, float newDist){
        node = nodePtr;
        dist = newDist;
    }
    NodeFloatPair(){}
};

struct NodeFloatPairComparator{
bool operator()(const NodeFloatPair& lhs, const NodeFloatPair& rhs) const {
    return lhs.dist > rhs.dist; 
}
};


std::vector<const Node*> dijkstra(const Node& startNode, const Node& endNode){
    std::vector<const Node*> path;
    std::unordered_map<const Node*,PathInfo> traveledNodes;
    std::priority_queue<NodeFloatPair, std::vector<NodeFloatPair>,NodeFloatPairComparator> pq;
    NodeFloatPair curNode;
    float curDist;
    const Node* curPrev = &endNode;

    pq.push(NodeFloatPair(&startNode,0));
    while(!pq.empty()){
        curNode = pq.top();
        pq.pop();


        if (traveledNodes.find(curNode.node) == traveledNodes.end()){
            traveledNodes[curNode.node] = PathInfo();
        }

        if ((curNode.dist > traveledNodes[curNode.node].distance) || (traveledNodes[curNode.node].visited == true)){
            continue;
        }
        else{
            traveledNodes[curNode.node].distance = curNode.dist;
        }
        traveledNodes[curNode.node].visited = true;

        for (auto neighbor : curNode.node->neighbors){
        if (traveledNodes.find(neighbor) == traveledNodes.end()){
            traveledNodes[neighbor] = PathInfo();
        }   
        
        curDist = getEdgeCost(*curNode.node,*neighbor) + traveledNodes[curNode.node].distance; 
        if (curDist < traveledNodes[neighbor].distance){
            traveledNodes[neighbor].distance = curDist;
            if (traveledNodes[curNode.node].prev != neighbor){
                traveledNodes[neighbor].prev = curNode.node;
            }
            pq.push(NodeFloatPair(neighbor,curDist));
        }
        }
        

        if (curNode.node == &endNode){
            break;
        }
    }


    do{
        path.insert(path.begin(),curPrev);
        curPrev = traveledNodes[curPrev].prev;
    }while(curPrev != NULL);
    return path;
}



std::vector<const Node*> pathPlanner(const Node& lastNode, const Node& orderStartNode, const Node& orderEndNode){
    std::vector<const Node*> finalPath;
    std::vector<const Node*> path1 = dijkstra(lastNode, orderStartNode);
    std::vector<const Node*> path2 = dijkstra(orderStartNode, orderEndNode);

    finalPath.insert(finalPath.end(),path1.begin(),path1.end());
    finalPath.insert(finalPath.end(),path2.begin(),path2.end());
    return finalPath;
}
