#include <bits/stdc++.h>

using namespace std;


class MaxHeap;

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
        int GetParent(int index){
            return floor((double)index/2.0);
        }
        int FindPosition(int content);
        void BuildBinaryHeap(vector<int>arr);

    friend class MaxHeap;
};

int BinaryHeap::FindPosition(int content){

    int ret=0;
    for(int i=1;i<heap.size();i++)if(heap[i].element==content)return i;
    return 0;
}

void BinaryHeap::BuildBinaryHeap(vector<int>arr){
    //O(n)
    heap.resize(arr.size()+1);
    for(int i=0;i<arr.size();i++){
        heap[i+1].element='a'+i;
        heap[i+1].key=arr[i];
    }
}

class MaxHeap :public BinaryHeap{
    public:
        void MaxHeapVerify(int index,int range);
        void BuildMaxHeap(vector<int>arr);
        void IncreaseKey(int element,int newKey);
        void MaxHeapInsert(int element,int newKey);
        void showheap();
        int MaxValue(){return heap[1].element;};
        int ExtractMax(); 
        
};


void MaxHeap::MaxHeapVerify(int index,int range){
    int left=2*index,
        right=2*index+1,
        biggest;

    if(left<=range && heap[left].key > heap[index].key)biggest=left;
    else biggest=index;
    
    if(right<=range && heap[right].key > heap[biggest].key)biggest=right;
    
    if(biggest!=index){
        swap(heap[biggest],heap[index]);
        MaxHeapVerify(biggest,range);
    }
}

void MaxHeap::BuildMaxHeap(vector<int>arr){
    //O(nlgn) 但經證明更緊的上界是O(n)
    BuildBinaryHeap(arr);
    for(int i=heap.size()/2;i>=1;i--){
        MaxHeapVerify(i,arr.size());
    }   
}

void MaxHeap::IncreaseKey(int element,int newKey){
    //O(lgn)

    int index=FindPosition(element);//探討複雜度時預設有這個node 
    if(index==0){
        cout<<"The node doesn't exist.\n";
        return ;
    }
    
    if(newKey < heap[index].key){
        cout<<"new key is lower than current key.\n";
        return ;
    }
    
    heap[index].key=newKey;
    
    while(index>1 && heap[GetParent(index)].key < heap[index].key){ //最多lgn次
        swap(heap[GetParent(index)],heap[index]);
        index=GetParent(index);
    }

}

void MaxHeap::MaxHeapInsert(int element,int key){
    //O(lgn) 
    node insert_node(key,element);//新增node時可以把key設成無限小
    heap.push_back(insert_node);
    IncreaseKey(element,key);//設定key並調整至符合MaxHeap
}

void MaxHeap::showheap(){

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

int MaxHeap::ExtractMax(){
    //O(lgn) 因為彈出去要調整MaxHeap
    if(IsHeapEmpty()){
        cout<<"Heap is empty.\n";
        return -1;
    }
    int ret=heap[1].element;
    
    heap[1]=heap[heap.size()-1];
    heap.pop_back();
    MaxHeapVerify(1,heap.size()-1);
    
    return ret;
}


int main(){
    MaxHeap test;
    vector<int>arr={1,2,3,4};
    test.BuildMaxHeap(arr);
    test.showheap();

    cout<<test.heap[test.GetParent(3)].key<<endl;
    cout<<test.heap[test.FindPosition(100)].key<<endl;

    test.IncreaseKey(97,100);
    test.MaxHeapInsert(999,12);
    test.showheap();

    test.ExtractMax();
    test.ExtractMax();
    test.ExtractMax();
    test.ExtractMax();
    test.ExtractMax();
    test.showheap();

    return 0;
}