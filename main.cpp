#include "Graph.cpp"
int main() {

    Graph graph(5);
    graph.insert(0,1,3,true);
    graph.insert(0,2,5,true);


    graph.insert(1,3,8,true);

    graph.insert(2,3,9,true);

    graph.insert(4,1,10,true);
    graph.insert(4,3,15,true);

    graph.display();
    graph.BFS(3);
    graph.DFS();





}