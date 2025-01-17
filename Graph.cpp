//
// Created by sohai on 1/16/2025.
//

#include "Graph.h"


Graph::Graph(int size) : graph(size,vector<int>(size,0)) {}

void Graph::insert(int u,int v,int distance,bool allow)
{
    assert( u < graph.size() && u >= 0 && v < graph.size() && v >= 0 && "Error : Invalid Index");
   graph[u][v] = distance;
   if (allow)
     graph[v][u] = distance;
}
void Graph::display() {
    for (int i = 0 ; i < graph.size() ; i++) {
        cout<<i<<" : ";
        for (int j = 0 ; j < graph.size() ; j++) {
            if (graph[i][j] != 0)
                cout<<" ( " <<j<<","<< graph[i][j] << " ) ";
        }
        cout<<endl;
    }
}
