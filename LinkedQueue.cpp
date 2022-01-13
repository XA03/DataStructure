#include <bits/stdc++.h>

using namespace std;

class LinkedQueue;

class node{
    private:
        int value;
        node* next;
    public:
        node():value(0),next(NULL){};
        node(int x):value(x),next(NULL){};
};

class LinkedQueue{
    private:
        node* front;
        node* rear;
    public:
        void Push(int value);
        void Pop();
};


int main(){

    return 0;
}