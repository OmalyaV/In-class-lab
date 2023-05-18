#include <iostream>
#include<list>
using namespace std;

struct Node{
    int label;
    list<int> neighbours;
    // A node will 2 entities
    //1. data type int called label
    //2. a int type list called neighbours

};

struct Graph{
    //graph will have an array of type "node" with length specified by n
    int n=9;
    Node * nodes = new Node[n];

    void intializenodes(){
        //iterate through the nodes and assign labels
        for(int i=1;i<n+1;i++){
            nodes[i].label=i;
        }
    }

    void addedge(int u, int v){
        nodes[u].neighbours.push_back(nodes[v].label);
        nodes[v].neighbours.push_back(nodes[u].label);
        //select node u and push v into u's neighbour

        //select node v and push u into v's neighbour
    }

    void print(){
        for(int i=1 ;i<n;i++){
            cout<< nodes[i].label<<"-> ";
            for(int & neighbour: nodes[i].neighbours){
                cout<< neighbour<<" ";
            }
            cout<<endl;
        }

        //lets iterate through each node and print its neighbours

    }
};

int main() {
    Graph * g = new Graph;
    g->intializenodes();
    //add edges for the graphs here.
    g->addedge(1,2);
    g->addedge(1,3);
    g->addedge(1,4);
    g->addedge(1,5);
    g->addedge(2,3);
    g->addedge(2,6);
    g->addedge(4,6);
    g->addedge(4,7);
    g->addedge(4,8);
    g->addedge(5,6);
    g->addedge(5,7);
    g->addedge(5,8);


    g->print();

    //print the graph adjaceny list
   
}
