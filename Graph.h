//
// Created by sohai on 1/16/2025.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <assert.h>
#include <queue>
#include <stack>
using namespace std;
class Graph
{
  private:
     vector<vector<pair<int,int>>> graph;
  public:
    Graph(int size);
    void insert(int u,int v,int distance,bool allow);
    void display();
    void BFS(int start_index); // Breadth First Search
    void DFS();
    void REC_DFS(vector<bool>& visited_state,int start_index);
    int min_index(vector<int>& Distance,vector<bool>& visited_state);
    void print(vector<int>& Distance);
    void dijkstra(int start_index);

};





#endif //GRAPH_H
