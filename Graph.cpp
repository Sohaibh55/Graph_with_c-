#include "Graph.h"

Graph::Graph(int size) : graph(size) {}

void Graph::insert(int u,int v,int distance,bool allow)
{
    assert( u < graph.size() && u >= 0 && v < graph.size() && v >= 0 && "Error : Invalid Index");
   graph[u].push_back(make_pair(v,distance));
   if (allow)
       graph[v].push_back(make_pair(u,distance));
}
void Graph::display() {
    int k = 0;
    for (auto i : graph) {
        cout<<k<<" : ";
        for (pair<int, int> j : i)
                cout<<" ( " <<j.first<<","<< j.second << " ) ";
        k++;
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
        start_index = queue.front();
        cout<<start_index<<" ";
        queue.pop();

        for (auto &neighbor : graph[start_index]) {
            int vertex = neighbor.first;
            if (!visited_index[vertex]) {
                queue.push(vertex);
                visited_index[vertex] = true;
            }
        }
    }
    cout<<endl;
}
void Graph::REC_DFS(vector<bool> &visited_state,int start_index) {

    cout<<start_index<<' ';
    visited_state[start_index] = true;

    for (auto& neighbor : graph[start_index]) {
        int vertex = neighbor.first;
        if (!visited_state[vertex])
            REC_DFS(visited_state,vertex);
    }
}
void Graph::DFS() {

    vector<bool> visited_state (graph.size(),false);
    cout<<" DFS Traversal : ";
    for (int i = 0 ; i < graph.size() ; i++) {
        if (!visited_state[i])
            REC_DFS(visited_state,i);
    }
    cout<<endl;
}
void Graph::dijkstra(int start_index) {
    vector<int> distances(graph.size(), INT_MAX);
    distances[start_index] = 0;


    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // min heap

    pq.push({0, start_index}); // Distance,vertex , Distance Firt --> Pour comparer les distance

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();


        if (dist > distances[node]) {
            continue;
        }


        for (auto &neighbor : graph[node]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;

            // Calculer la nouvelle distance
            if (distances[node] + weight < distances[nextNode]) {
                distances[nextNode] = distances[node] + weight;
                pq.push({distances[nextNode], nextNode});
            }
        }
    }


    cout << "Shortest distances from node " << start_index << ":" << endl;
    for (int i = 0; i < graph.size(); i++) {
        if (distances[i] == INT_MAX) {
            cout << "Node " << i << ": Unreachable" << endl;
        } else {
            cout << "Node " << i << ": " << distances[i] << endl;
        }
    }
}