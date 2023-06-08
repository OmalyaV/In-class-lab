//
// Created by user on 6/8/2023.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

//typedef pair<int, int> pair ;//(weight, vertex)
int find_min(vector<int> key, vector<bool> visited, int V){
    int min = INT_MAX, min_index;
    for(int i=0; i<V ;i++){
        if(!visited[i] && key[i] < min){
            min = key[i];
            min_index = i;
        }
    }

    return min_index;

}
void printMST(vector<int> parent, vector<vector<int>> graph,int V){
    cout <<"parent"<<"   "<<"node"<< " weight"<<endl;
    for (int i = 1; i < V; i++)
        cout << parent[i] << "      - " << i << " \t"
             << graph[i][parent[i]] << endl;
}

vector<vector<int>> PrimsAlgorithm(vector<vector<int>> graph, int V){

    vector<int> parent(V);
    vector<int> key(V, INT_MAX);
    vector<bool> visited(V, false);

    key[0] = 0;
    parent[0] = -1;
    for(int i= 0; i<V-1; i++){
        int  x = find_min(key,visited,V );
        visited[x] = true;
        for(int y= 0; y<V; y++){
            if(graph[x][y] && !visited[y] && graph[x][y] < key[y]){
                parent[y] = x;
                key[y] = graph[x][y];

            }
        }
    }
    printMST(parent,graph, V);
}
int main()
{
    vector<vector<int>> Adjacent_matrix ={
            {0,3,0,0,0,1},
            {3,0,2,1,10,0},
            {0,2,0,3,0,5},
            {0,1,3,0,5,0},
            {0,10,0,5,0,4},
            {1,0,5,0,4,0}
    };

    PrimsAlgorithm(Adjacent_matrix, 6);
    return 0;

}