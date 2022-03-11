#include <bits/stdc++.h>

using namespace std;


class MinHeap;


struct node{
    int key;
    int element;
    node():key(0),element(0){};
    node(int key,int element):key(key),element(element){};
};

class BinaryHeap{
    public:
        vector<node>heap;
        
        BinaryHeap(){heap.resize(1);};
        BinaryHeap(int n){heap.resize(n+1);};
        
        bool IsHeapEmpty(){return heap.size()<=1;};
        int FindPosition(int index);
        int GetParent(int index){return floor(index/2);};

        void BuildBinaryHeap(vector<int>arr);

        friend class MinHeap;
};


class MinHeap{
    public:
        void MinHeapVerify(int index,int range);
        void BuildMaxHeap()

};


int main(){


    return 0;
}