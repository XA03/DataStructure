#include <bits/stdc++.h>

// 有參考 http://alrightchiu.github.io/SecondRound/stack-yi-arrayyu-linked-listshi-zuo.html 的文章
// 使用 Array的方式實作Stack


using namespace std;

class ArrayStack{
    private:
        int topindex,capacity;
        int *stack;
        void DoubleCapacity();                  //為甚麼要放private的原因是因為這個Function不會在外部，也不給物件主動呼叫
    public:
        ArrayStack():topindex(-1),capacity(1){
            stack=new int[capacity];
        };
        void Push(int value);
        void Pop();
        int  Top();
        int  getSize();
        bool Isempty();
};

void ArrayStack::Push(int value){
    if(topindex==capacity-1)DoubleCapacity();
    stack[++topindex]=value;
}

void ArrayStack::Pop(){
    if(Isempty())cout<<"Stack is empty!\n";
    stack[topindex]=-999;
    topindex--;
}

int ArrayStack::Top(){
    return stack[topindex];
}

int ArrayStack::getSize(){
    return topindex+1;
}

bool ArrayStack::Isempty(){
    return topindex==-1;
}

void ArrayStack::DoubleCapacity(){
    capacity*=2;
    int *newstack=new int[capacity];
    for(int i=0;i<capacity;i++){
        newstack[i]=stack[i];
    }
    delete []stack;
    stack=newstack;
}

int main(){

    ArrayStack test;
    for(int i=0;i<12;i++)test.Push(i);

    while (!test.Isempty()){
        cout<<"Top = "<<test.Top()<<" Size = "<<test.getSize()<<endl;
        test.Pop();
    }
    test.Pop();

    return 0;
}