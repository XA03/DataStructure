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
        int FindPosition(int content);
        int GetParent(int index){return floor(index/2);};
        void BuildBinaryHeap(vector<int>arr);

        friend class MinHeap;
};

int BinaryHeap::FindPosition(int content){
    for(int i=1;i<heap.size();i++){
        if(heap[i].element==content)return i;
    }
    return 0;
}

void BinaryHeap::BuildBinaryHeap(vector<int>arr){
    heap.resize(arr.size()+1);
    for(int i=0;i<arr.size();i++){
        heap[i+1].element=i+22;
        heap[i+1].key=arr[i];
    }

}

class MinHeap : public BinaryHeap{
    public:
        void MinHeapVerify(int index,int range);
        void BuildMinHeap(vector<int>arr);
        void DecreaseKey(int element,int newKey);
        void MinHeapInsert(int element,int newKey);
        void showheap();
        int MinValue(){return heap[1].element;};
        int ExtractMin();
};

void MinHeap::MinHeapVerify(int index,int range){
    int left=2*index,
        right=2*index+1,
        smallest;

    if(left<=range && heap[left].key < heap[index].key)smallest=left;
    else smallest=index;

    if(right<=range && heap[right].key < heap[smallest].key)smallest=right;

    if(smallest!=index){
        swap(heap[smallest],heap[index]);
        MinHeapVerify(smallest,range);
    }
}

void MinHeap::BuildMinHeap(vector<int>arr){
    BuildBinaryHeap(arr);
    for(int i=heap.size()/2;i>=1;i--){
        MinHeapVerify(i,arr.size());
    }
}

void MinHeap::DecreaseKey(int element,int newKey){
    int index=FindPosition(element);

    if(index==0){
        cout<<"the node doesn't exist.\n";
        return ;
    }

    if(newKey > heap[index].key){
        cout<<"new key is larger than current key.\n";
        return ;
    }

    heap[index].key=newKey;

    while(index>1 && heap[GetParent(index)].key > heap[index].key){
        swap(heap[GetParent(index)],heap[index]);
        index=GetParent(index);
    }

}

void MinHeap::MinHeapInsert(int element,int key){
    node insert_node(key,element);
    heap.push_back(insert_node);
    DecreaseKey(element,key);
}

void MinHeap::showheap(){
    if(IsHeapEmpty()){
        cout<<"Heap is empty.\n";
        return ;
    }

    cout<<"key  element\n";
    for(int i=1;i<heap.size();i++){
        printf("%-4d %-4d\n",heap[i].key,heap[i].element);
    }
    cout<<endl;
}

int MinHeap::ExtractMin(){
    if(IsHeapEmpty()){
        cout<<"Heap is empty.\n";
        return -1;
    }
    
    int ret=heap[1].element;

    heap[1]=heap[heap.size()-1];
    heap.pop_back();
    MinHeapVerify(1,heap.size()-1);

    return ret;
}

int main(){

    MinHeap test;
    vector<int>arr={8,2,9,4};
    test.BuildMinHeap(arr);
    test.showheap();

    cout<<test.heap[test.GetParent(3)].key<<endl;
    cout<<test.heap[test.FindPosition(100)].key<<endl;

    test.DecreaseKey(25,1);
    test.MinHeapInsert(999,12);
    test.showheap();

    test.ExtractMin();
    test.ExtractMin();
    test.ExtractMin();
    test.ExtractMin();
    test.ExtractMin();
    test.showheap();

    return 0;
}