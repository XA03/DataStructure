#include <bits/stdc++.h>

using namespace std;

// 使用LinkList來實作Queue資料結構


class LinkedQueue;

class node{
    private:
        int value;
        node* next;
    public:
        node():value(0),next(NULL){};
        node(int x):value(x),next(NULL){};
        friend class LinkedQueue;
};

class LinkedQueue{
    private:
        int   size;
        node  *front;
        node  *rear;
    public:
        LinkedQueue():size(0),front(NULL),rear(NULL){};
        void Push(int value);
        void Pop();
        int  getFront();
        int  getBack();
        bool Isempty();
        int  getSize();
};

void LinkedQueue::Push(int value){
    if(Isempty()){
        front=new node(value);
        rear=front;
        size++;
    }
    else{
        rear->next=new node(value);
        rear=rear->next;
        size++;
    }
}

void LinkedQueue::Pop(){
    if(Isempty()){
        cout<<"Queue is empty!\n";
    }
    else{
        node *popnode=front;
        front=front->next;
        delete(popnode);
        size--;
    }
}

int LinkedQueue::getFront(){
    if(Isempty()){
        cout<<"Queue is empty!\n";
        return -1;
    }
    else{
        return front->value;
    }
}

int LinkedQueue::getBack(){
    if(Isempty()){
        cout<<"Queue is empty!\n";
        return -1;
    }
    else{
        return rear->value;
    }
}

bool LinkedQueue::Isempty(){
    return ((front&&rear)==0);
}

int LinkedQueue::getSize(){
    return size;
}

int main(){

    LinkedQueue test;
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