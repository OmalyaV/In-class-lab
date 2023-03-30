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

void quick_sort(int *arr, int first, int last){
    if ((last- first)>1){
        int pivot = *(arr +last-1);
        int i = first-1;
        
        int temp;
        for(int j=first ;j<last-1;j++){
            if (*(arr+j)< pivot ){
                i++;
                temp = *(arr+i);
                *(arr+i) = *(arr+j);
                *(arr+j) = temp;
                //print(arr,5 );
            }
            
        }
        i++;
        *(arr+last-1) = *(arr+i);
        *(arr+i) = pivot;
        
        quick_sort(&arr[0], first, i);
        quick_sort(&arr[0], i+1, last);
    }
     
}


int main(){
    auto start = high_resolution_clock::now();

    // Initialize random number generator
    srand(time(0));

    // Get array size from user
    int size =1000;

    // Allocate memory for the array
    int* arr = new int[size];

    // Fill array with random numbers between 1 and 100
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 20000;
    }
    /*cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;*/
    //print(arr, size);
    quick_sort(arr,0,size);

//    cout << "Sorted array: ";
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    double time = duration.count();
    cout << "time taken is: " << time << "micro seconds" << endl;
    return 0;
}
