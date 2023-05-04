#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
  int left = root*2 +1;
  int right  = root*2 +2;
  int largest = root;
  if(left < n){
    if(arr[left]> arr[largest]){
        largest = left;
    }
  }
  if(right < n){
    if(arr[right]> arr[largest]){
        largest = right;
    }
  }
  if(largest != root){
    int temp = arr[largest];
    arr[largest] = arr[root];
    arr[root] = temp;
    heapify(arr,n, largest);
  }

   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for(int i = (n-2)/2; i>=0; i--){
        heapify(arr, n, i);
    }
   
  
   // extracting elements from heap one by one
   for(int j = n -1; j>=0; j--){
        int temp = arr[j];
        arr[j] = arr[0];
        arr[0] = temp;
        heapify(arr, j,0);
    }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{  
   //int heap_arr[] = {4,17,3,12,9,6};
   cout << "Enter the size of the array"<<endl;
   
   int n ;
   cin>> n;
   int* heap_arr = new int[n];
   cout <<"Enter values"<< endl;
   for (int i = 0; i < n; i++){
    cin >> heap_arr[i];
   }
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}