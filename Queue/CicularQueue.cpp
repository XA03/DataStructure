#include <bits/stdc++.h>

using namespace std;

//Sequential Array Queue 會浪費一些Queue的空間，造成不斷需要增加Capacity的情況，於是另使用Cicular的手法來節省Queue不必要的空間浪費

class CircularQueue{
    public:
        int front,rear,capacity;
        int *Arrqueue;
        void Doublecapacity();
    public:
        CircularQueue():front(0),rear(0),capacity(2){ //capacity 不能為1原因是因為mod的關係在capacity=1時empty判定會恆成立，所以會造成其中某些函式的錯誤
            Arrqueue=new int[capacity];
        };
        void Push(int value);
        void Pop();
        bool Isempty();
        int  getFront();
        int  getBack();
        int  getSize();
};

void CircularQueue::Doublecapacity(){
    int *newArrquque=new int[capacity*2]; //這裡不要直接像Sequential Array Queue一樣把public capacity乘2
    int newrear=front,size=getSize();
    
    /*
        或是可以這樣寫
        for(int i=1;i<=size;i++){
            newArrqueue[i]=Arrqueue[++front%capacity];
        }

        差在哪？ 差在如果你去亂動front的值 會造成gerSize()的長度被更動進而產生錯誤
        這也算是一種需要loop counter固定的原因之一 因為你用物件size或是一個計算後的結果去當長度
        當你今天有使用到計算長度的運算元的時候就會這樣
        
        或是你也可以不要像我一樣手賤去故意寫的跟人家寫的code不一樣 我只是想看看這樣思路對不對 ㄏ

    */

    for(int i=1;i<=getSize();i++){
        newArrquque[i]=Arrqueue[++newrear%capacity];//把舊queue裡的元素複製到新的queue裡，因為是Circular所以需要mod來讓front可以回到Array開頭處
                                                    //那裡是有可能會有新Push的元素的，因此開頭的capacity不能夠像Sequential一樣直接乘二
    }
    front=0;
    rear=size;
    capacity*=2;
    delete []Arrqueue;
    Arrqueue=newArrquque;
};

void CircularQueue::Push(int value){
    if((rear+1)%capacity==front)Doublecapacity(); //當rear碰到front的時候代表Array裝不下了
    rear=(rear+1)%capacity;
    Arrqueue[rear]=value;
}

void CircularQueue::Pop(){
    if(Isempty()){
        cout<<"Queue is empty!\n";
        return;
    }
    front=(front+1)%capacity;
}

bool CircularQueue::Isempty(){
    return (front==rear);
}

int CircularQueue::getFront(){
    if(Isempty()){
        cout<<"Queue is empty!\n";
        return -1;
    }
    return Arrqueue[(front+1)%capacity];//front本身不會有東西，所有front的元素都是從front+1才有
}

int CircularQueue::getBack(){
    if(Isempty()){
        cout<<"Queue is empty!\n";
        return -1;
    }
    return Arrqueue[rear];
}

int CircularQueue::getSize(){
    if(front>=rear)return capacity-front+rear;
    else return rear-front;
}

int main(){

    CircularQueue test;
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