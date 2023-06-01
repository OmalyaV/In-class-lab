//
// Created by user on 6/1/2023.
//
#include <iostream>
#include<list>
#include<vector>
#include <queue>
using namespace std;



void dijkstras_algorithm(int source, int graph[6][6]){
    vector<int> distance(6, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<>> priority_q; //this is to catch the next visiting city after the current
    distance[source] = 0;
    vector<bool> visited(6, false); // to track if visited
    priority_q.emplace(0,source);

    while (!priority_q.empty()){
        int city_u = priority_q.top().second;
        visited[city_u] = true;
        priority_q.pop();
        int weight_v;
        for(int city_v=0;city_v<6;city_v++){
            if(graph[city_u][city_v] !=0 && (!visited[city_v])){ // travelling to neighbours if they aren't visited
                weight_v= graph[city_u][city_v];
                if(distance[city_u] != INT_MAX && distance[city_u]+weight_v<distance[city_v]) // condition to change the distance value of the visiting cities
                    distance[city_v] = distance[city_u]+weight_v;
                    priority_q.emplace(distance[city_v], city_v);
                }
            }


        }

    //printing the shortest distances
    cout << "from city "<< source <<" shortest distances to each city"<<endl;
    for(int k=0; k< 6; k++){
        if(k != source){
            cout<< k<< ": "<<distance[k]<<endl;
        }

    }
    cout<<endl;

}



int main() {
    int rows = 6;
    int columns = 6;
    int adj_matrix[6][6] = {
            {0,  10, 0,  0,  15, 5},
            {10, 0,  10, 30, 0,  0},
            {0,  10, 0,  12, 5,  0},
            {0,  30, 12, 0,  0,  20},
            {15, 0,  5,  0,  0,  0},
            {5,  0,  0,  20, 0,  0}
    };
    dijkstras_algorithm(0,adj_matrix);
    dijkstras_algorithm(1,adj_matrix);
    dijkstras_algorithm(2,adj_matrix);
    dijkstras_algorithm(3,adj_matrix);
    dijkstras_algorithm(4,adj_matrix);
    dijkstras_algorithm(5,adj_matrix);

}