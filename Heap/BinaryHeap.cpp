#include <bits/stdc++.h>

using namespace std;


struct node{
    int key;
    string element;
    node():key(0),element(""){};
    node(int key,string element):key(key),element(element){};
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
};

void BinaryHeap::BuildBinaryHeap(vector<int>arr){
    heap.resize(arr.size()+1);
    for(int i=0;i<arr.size();i++){
        heap[i+1].element='a'+i;
        heap[i+1].key=arr[i];
    }
}


int main(){

    BinaryHeap test;
    vector<int>arr={1,2,3,4};
    test.BuildBinaryHeap(arr);


    for(int i=1;i<=arr.size();i++){
        cout<<test.heap[i].element<<" "<<test.heap[i].key<<endl;
    }

    return 0;
}