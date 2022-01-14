#include <bits/stdc++.h>

using namespace std;

//本篇實作有參考 http://alrightchiu.github.io/SecondRound/stack-neng-gou-zai-o1qu-de-zui-xiao-zhi-de-minstack.html 的文章

//MinStack是可以在時間複雜度O(1)取得Stack中最小元素的Stack 反之取得最大元素的是MaxStack
//嘗試使用三個stack來製作可以在O(1)取得最大最小元素的Stack，Google了一下發現這好像比較接近MinMaxStack
//但本人覺得MinMax會讓人以為是像Min-Max Heap那種類型的前綴詞(雖然有學過的同學們一定都知道根本不一樣)
//所以還是起名AllStack 有更好的名字再把他修正

class AllStack{
    private:
        stack<int>data;
        stack<int>minvalue;
        stack<int>maxvalue;
    public:
        AllStack(){};
        void Push(int value);
        void Pop();
        bool Isempty();
        int  Top();
        int  getSize();
        int  getMin();
        int  getMax();
};

void AllStack::Push(int value){
    data.push(value);
    if(minvalue.empty()||value<minvalue.top())minvalue.push(value);
    else minvalue.push(minvalue.top());
    if(maxvalue.empty()||value>maxvalue.top())maxvalue.push(value);
    else maxvalue.push(maxvalue.top());
}

void AllStack::Pop(){
    if(Isempty())cout<<"AllStack is empty!\n";
    else{
        data.pop();
        minvalue.pop();
        maxvalue.pop();
    }
}

bool AllStack::Isempty(){
    return data.empty();
}

int AllStack::Top(){
    if(data.empty()){
        cout<<"AllStack is empyty!\n";
        return -1;
    }
    return data.top();
}

int AllStack::getSize(){
    if(data.empty()){
        cout<<"AllStack is empty!\n";
        return -1;
    }
    return data.size();
}

int AllStack::getMin(){
    if(data.empty()){
        cout<<"AllStack is empty!\n";
        return -1;
    }
    return minvalue.top();
}

int AllStack::getMax(){
    if(data.empty()){
        cout<<"AllStack is empty!\n";
        return -1;
    }
    return maxvalue.top();
}

int main(){

    AllStack test;

    for(int i=0;i<12;i++){
        test.Push(i%10);
    }
    cout<<"Top Min Max\n";
    while(!test.Isempty()){
        cout<<test.Top()<<"   "<<test.getMin()<<"   "<<test.getMax()<<endl;
        test.Pop();
    }


    return 0;
}