#include <bits/stdc++.h> 
#include <iostream>
#include<vector>
#include<chrono>
#include <cstdlib>
#include <ctime>
#include<iomanip>
using namespace std; 
using namespace std::chrono;
void print(vector<float> arr, int size){
    for (int i= 0; i<size; i++){
        cout << arr[i]<<" ";
        
    }
    cout <<endl;
}


void quick_sort(vector<float> arr, int first, int last){
    if ((last- first)>1){
        int pivot = arr[last-1];
        int i = first-1;
        
        int temp;
        for(int j=first ;j<last-1;j++){
            if (arr[j]< pivot ){
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                //print(arr,5 );
            }
            
        }
        i++;
        arr[last-1] = arr[i];
        arr[i] = pivot;
        
        quick_sort(arr, first, i);
        quick_sort(arr, i+1, last);
    }
     
}

int main(){
    int size ;
    cout <<"enter the size: ";
    cin >>size;
    if (size >0){
        float *arr = new float[size];
        float number;
    cout <<"Enter the elements in white spaces";
    for  (int i=0; i<size; i++ ){
        cin >> number;
        arr[i] = number;
    } 
    vector<float> result ;
    float median;
    for (int j = 0; j<size; j++){
        result.push_back(arr[j]);
        
        int size2 = result.size();
        print(result, size2);
        cout <<endl;
        quick_sort(result, 0,size2 );
        if (result.size()%2 ==1){
            median = float(result[(size2-1)/2]);
            

        }
        else{
            median = float((arr[size2/2]+arr[(size2/2)-1])/2);
        }
        cout << median;
        cout <<endl;

    }
    


    }
    
    
    return 0;
}