#include <iostream>
#include<list>
using namespace std;

struct Node{
    int label;
    list<int> neighbours;
};

struct Graph{
    int n=9;
    Node * nodes = new Node[n];

    void initialize_nodes(){
        for(int i=1;i<n;i++){
            nodes[i].label=i;
        }
    }

    void add_edge(int u, int v){
        nodes[u].neighbours.push_back(v);
        nodes[v].neighbours.push_back(u);
    }

    void print(){
        for(int i=0; i<n; i++){
            cout << "Node " << nodes[i].label << " neighbours: ";
            for(auto j : nodes[i].neighbours){
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph * g = new Graph;
    g->initialize_nodes();
    
    // Adding edges to the graph
    g->add_edge(1, 2);
    g->add_edge(1, 3);
    g->add_edge(1, 4);
    g->add_edge(1, 5);
    g->add_edge(2, 3);
    g->add_edge(2, 6);
    g->add_edge(4, 6);
    g->add_edge(4, 7);
    g->add_edge(4, 8);
    g->add_edge(5, 6);
    g->add_edge(5, 7);
    g->add_edge(5, 8);
    
    g->print(); // printing the adjacency list of the graph
    
    return 0;
}
