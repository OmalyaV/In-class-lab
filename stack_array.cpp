#include <bits/stdc++.h> 
#include <iostream>
#include<vector>
#include<chrono>
#include <cstdlib>
#include <ctime>
using namespace std; 
using namespace std::chrono;

class Stack{
    private:
    int  top;
    int size =20;
    int *stack;

    public :
    Stack(){
        top = -1;
        //size = size;
        stack = new int[size];
    }
    void push( int val){
    top = top+1;
    if(top >size){
        cout<<"Error:Stack Overflow"<<endl;
    }
    else{
        stack[top] = val;
    }

    
}
int pop(){
    if(top <0){
        cout <<"Error StackUnderflow"<<endl;
    
    }
    else{
        top = top -1;
        return stack[top+1];
    }
}

bool is_empty(){
    return top ==-1;
}
bool is_full ()
{
    return top == size;
}

void display(){
    for (int i= 0; i<top+1; i++){
        cout << stack[i] <<" ";
        
    }
    cout <<endl;
}
};

int main(){
    srand(time(0));
    auto start = high_resolution_clock::now();
    
    Stack S;
    S.push(8);
    S.push(9);
    S.push(10);
    S.push(6);
    S.push(4);
    S.push(3);
    S.push(2);
    S.push(1);
    S.push(7);
    S.push(12);
    S.display();
    for(int i=0; i<5;i++){
        S.pop();
    }
    S.display();
    S.push(5);
    S.push(30);
    S.push(20);
    S.display();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    double time = duration.count();
    cout << "time taken for the recursive algorithm: " << time << " micro seconds" << endl;

    return 0;
}