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
void Graph::BFS(int start_index) {

    vector<bool> visited_index(graph.size(),false);
    queue<int> queue;
    queue.push(start_index);
    visited_index[start_index] = true;
    cout << "BFS traversal starting from node " << start_index << ": ";

    while ( !queue.empty() ) {

        cout<<queue.front()<<" ";
        start_index = queue.front();
        queue.pop();

      for (int i = 0 ; i <graph.size() ; i++) {
          if ( !visited_index[i] && graph[start_index][i] != 0)
          {
              queue.push(i);
              visited_index[i] = true;
          }
      }
    }
}
