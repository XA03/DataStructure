#include <bits/stdc++.h>

using namespace std;

//用Array實作Queue的方式之一，較浪費記憶體的Sequential Queue.

class SequentialArrayQueue{
    private:
        int front,rear,capacity;
        int *Arrqueue;
        void Doublecapacity();
    public:
        SequentialArrayQueue():capacity(1),front(-1),rear(-1){ //front，rear一開始用-1當index原因是因為 實際存儲的index 0~capacity-1
            Arrqueue=new int[capacity];                        //如果用0當起點的話 不知道0這個位置到底是有資料還是沒資料 變相浪費一個空間
        };
        void Push(int value);
        void Pop();
        int  getFront();
        int  getBack();
        int  getSize();
        bool Isempty();
};
//因為我們front，rear使用-1當作起點，所以做push、pop操作時也要先++在賦值


void SequentialArrayQueue::Doublecapacity(){
    capacity*=2;
    int newrear=-1;
    int* newArrqueue=new int[capacity];
    for(int i=front+1;i<=rear;i++){
        newrear++;
        newArrqueue[newrear]=Arrqueue[i];
    }
    front=-1;
    rear=newrear;
    delete []Arrqueue;
    Arrqueue=newArrqueue;
}

void SequentialArrayQueue::Push(int value){
    if(rear+1==capacity)Doublecapacity();
    Arrqueue[++rear]=value;
}

void SequentialArrayQueue::Pop(){
    if(Isempty()){
        cout<<"Queue is empty!\n";
        return;
    }
    front++;
}

bool SequentialArrayQueue::Isempty(){
    return (front==rear);
}

int SequentialArrayQueue::getBack(){
    if(Isempty()){
        cout<<"Queue is empty!\n";
        return -1;
    }
    return Arrqueue[rear];
}

int SequentialArrayQueue::getFront(){
    if(Isempty()){
        cout<<"Queue is empty!\n";
        return -1;
    }
    return Arrqueue[front+1];
}

int SequentialArrayQueue::getSize(){
    return (rear-front);
}


int main(){

    SequentialArrayQueue test;

    cout<<"Front   Back\n";
    for(int i=1;i<=12;i++){
        test.Push(i);
        cout<<test.getFront()<<"      "<<test.getBack()<<endl;
    }
    cout<<"\n\n";
    cout<<"Front  Back\n";
    while(!test.Isempty()){
        cout<<test.getFront()<<"      "<<test.getBack()<<endl;
        test.Pop();
    }



    return 0;
}