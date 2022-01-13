#include <bits/stdc++.h>

//使用SinglyLinkList實作Stack


using namespace std;

class LinkedStack;

class node
{ 
    private:
        int value;  
        node *next; 
    public:
        node() : value(0), next(NULL){};
        node(int input) : value(input), next(NULL){}; 
        friend class LinkedStack;                 
};

class LinkedStack{
    private:
        int size=0;
        node* top;
    public:
        LinkedStack():size(0),top(NULL){};
        void Push(int value);       //把元素放在stack的最上面
        void Pop();                 //把stack最上面的元素移除
        int Top();                  //輸出stack最上面的元素的值
        int Size();                 //輸出stack現在內部的元素總數
        bool Isempty();             //判斷stack是否為空的
};

void LinkedStack::Push(int value){
    node *newnode=new node(value);
    newnode->next=top;
    top=newnode;
    size++;
}

void LinkedStack::Pop(){
    node *popnode=top;
    if(top==NULL){
        cout<<"Stack is empty!\n";
        return;
    }
    top=top->next;
    delete(popnode);
    size--;
}

int LinkedStack::Top(){
   return top->value; 
}

int LinkedStack::Size(){
    return size;
}

bool LinkedStack::Isempty(){
    return size==0;
}


int main(){

    LinkedStack test;
    for(int i=0;i<12;i++)test.Push(i);
    
    while(!test.Isempty()){
        cout<<test.Top()<<endl;
        test.Pop();
    }


    return 0;
}

