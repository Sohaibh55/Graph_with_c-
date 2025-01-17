#include "Graph.cpp"
int main() {

    Graph graph(5);
    graph.insert(0,1,3,true);
    graph.insert(0,2,5,true);

    graph.insert(1,2,6,true);
    graph.insert(1,3,8,true);

    graph.insert(2,3,9,true);
    graph.insert(2,4,10,true);

    graph.display();





}