#include <bits/stdc++.h> 
#include <iostream>
#include<vector>
#include<chrono>
#include <cstdlib>
#include <ctime>
using namespace std; 
using namespace std::chrono;

class Node {
public:
    int val;
    Node* next;
    Node(int value) {
        val = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;
public:
    Stack() {
        top = nullptr;
    }
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }
    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    bool  is_empty() {
        return(top== nullptr);
    }
    void display(){
        Node *current = top;
        while(current != nullptr){
            cout<< current ->val<< " ";
            current = current->next;
        }
        cout <<endl;
    }
    
};

int main() {
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

}
