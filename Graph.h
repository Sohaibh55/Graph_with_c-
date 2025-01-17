//
// Created by sohai on 1/16/2025.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <assert.h>
#include <cassert>
using namespace std;
class Graph
{
  private:
     vector<vector<int>> graph;
public:
    Graph(int size);
    void insert(int u,int v,int distance,bool allow);
    void display();
};





#endif //GRAPH_H
