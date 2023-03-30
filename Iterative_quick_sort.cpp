#include <bits/stdc++.h> 
#include <iostream>
#include<vector>
#include<chrono>
#include <cstdlib>
#include <ctime>
using namespace std; 
using namespace std::chrono;
void print(int *arr, int size){
    for (int i= 0; i<size; i++){
        cout << *(arr+i) <<" ";
        
    }
    cout <<endl;
}



void iterative_quick_sort(int *arr, int size) {
    stack<int> list ;
    list.push(0);
    list.push(size-1);
    int temp ;
    while(! list.empty()){
        int last = list.top();
        list.pop();
        int first = list.top();
        list.pop();

        int pivot = arr[last];
        int i = first -1;
        for (int j = first; j< last; j++ ){
            if (*(arr+j)<pivot){
                i++;
                temp = *(arr+i);
                *(arr+i) = *(arr+j);
                *(arr+j) = temp;
            }
        }
        i++;
        *(arr+last) = *(arr+i);
        *(arr+i) = pivot;
        if (i-first >0){
            list.push(first);
            list.push(i-1);
        }
        if (last -(i+1) >0){
            list.push(i+1);
            list.push(last);
        }

    }
}

int main(){
    

    // Initialize random number generator
    srand(time(0));

    // Get array size from user
    int size =20000;

    // Allocate memory for the array
    int* arr = new int[size];

    // Fill array with random numbers between 1 and 100
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 2000000;
    }
    auto start = high_resolution_clock::now();
    //calling the function
    iterative_quick_sort(&arr[0], size);
    //print(&arr[0], size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    double time = duration.count();
    cout << "time taken for the recursive algorithm: " << time << " micro seconds" << endl;

    



    
    return 0;
}
