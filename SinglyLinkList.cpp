#include <bits/stdc++.h>

using namespace std;

// Coding 有參考 http://alrightchiu.github.io/SecondRound/linked-list-xin-zeng-zi-liao-shan-chu-zi-liao-fan-zhuan.html 之文章

//SinglyLinkList 單向鏈結串列 (單向鏈表)

//這份文件有教學和自我複習的性質，所以註解可能會有點囉嗦
//在進入程式前，先在這裡解釋一下個人對SinglyLinkList的看法，這是一個不循序的資料結構，也就是說各個節點(承載data的單位)間的記憶體位址不連續。
//我們利用指標去指向各個節點的記憶體位址，再將其有順序的連接在一起，形成一條單向的鏈 所以稱為 單向鏈結串列、單向鏈表
//其中指標是可以沒指到東西的(NULL)，也就是說只宣告指標而不給予其節點是沒辦法利用節點中通往下一個節點的指標變數(*next)，所以會連不起來。
//另外注意：MemberFunction中的操作可以直接影響DataMember，所以在使用上要記得用Temp來取代直接使用DataMebmer

class SinglyLinkList; //因為需要freind 所以得先宣告在這裡

class node
{ // SinglyLinkList 中的單位節點
private:
      int value;  //節點本身的值
      node *next; //指向下一個節點的指標
public:
      node() : value(0), next(NULL){};
      node(int input) : value(input), next(NULL){}; //constructor後的冒號是給 class data member assign的方法 如果是const data member更適合這種assignment(賦值、=)
      friend class SinglyLinkList;                  //表示class SinglyLinkList中可以access class node裡的 所有東西
};

class SinglyLinkList
{ // SinglyLinkList 單向鏈節串列 (單向鏈表)
private:
      int length; //SinglyLinkList長度
      node *head; //SinglyLinkList的起點
public:
      SinglyLinkList() : length(0), head(NULL){};
      int Length();                            //給出串列長度
      node *Position(int index);               //回傳從頭開始第index個的節點
      void Shownode(int index);                //印出從頭開始第index個的節點
      void ShowList();                         //印出整個串列
      void Front_insert(int value, int index); //把值為value節點插在第index個節點的前面
      void Back_insert(int value, int index);  //把值為value節點插在第index個節點的後面
      void Delete_node(int index);             //刪除第index個節點
      void Clear();                            //清空整個串列
      void Inverse();                          //將串列的方向調換，原本的起點變成尾巴
};

int SinglyLinkList::Length(){
      return length;                                  //回傳長度
}

node* SinglyLinkList::Position(int index){
      node* temp=head;                                //暫用指標避免直接使用head

      if(index<1||index>length||!temp)return NULL;    //如果index超出範圍或是串列本身為空，回傳一個指向NULL的指標(空指標)

      int i=1;                                      
      while(index!=i){                              
            temp=temp->next;                          
            i++;
      }
      return temp;
}

//順道一提，(*void)不是指向空的指標，而是這個指標可以是任何指標類型
//沒初始化的指標不代表他的值一定不會等於一個有指到物件的指標，因為未初始化的指標有可能指向一些未知的記憶體位址
//那些位址可能會有值，所以你沒辦法說一個未初始化的指標一定不會和一個已經賦值的指標不一樣
//所以當今天需要一個一定不會和有賦值的東西一樣的變數時我們會給NULL表示這個指標沒有指向任何物件
//去區分 有指到東西的指標 跟 沒指到東西的指標
//比喻： A是一個裝著未知物品的箱子 B是一個裝著水的箱子  你不會說A一定跟B不一樣 因為A裡面的未知物品可能是水 只是當下你不知道
//但是換成 A是一個空箱子 B是一個裝著水的箱子 你就可以說 A跟B一定是不一樣的箱子 因為A根本沒裝東西
//NULL的意思就是指這個箱子(指標)裡面沒裝東西(物件)的意思

//this指標說明：待補



void SinglyLinkList::Shownode(int index){
      node* target=this->Position(index);
      if(!target)cout<<"Target is out of List range!\n";
      else cout<<target->value<<endl;
}

void SinglyLinkList::ShowList(){ 
      
      node* temp=head;                                //避免使用head造成串列位置不對

      if(!temp)cout<<"SinglyLinkList is empty!\n";
      else{
            while (temp){
                  cout<<temp->value<<" ";
                  temp=temp->next;
            }
            cout<<endl;
      }
}

void SinglyLinkList::Front_insert(int value,int index=1){
      node* newnode=new node(value);                 

      if(index==1||!head){                                             
            newnode->next=head;
            head=newnode;
            length++;
      }
      else{
            if(index<1||index>length)cout<<"You can't insert in this position!\n";
            else{
                  node* target=this->Position(index-1);
                  newnode->next=target->next;
                  target->next=newnode;
                  length++;
            }
      } 
}

void SinglyLinkList::Back_insert(int value,int index=1){
      node* newnode=new node(value);                         

      if(!head){
          head=newnode;
          length++;  
      }
      else{
            if(index<1||index>length)cout<<"You can't insert in this position!\n";
            else{
                  node* target=this->Position(index);
                  if(index==length){
                        target->next=newnode;
                        length++;
                  }
                  else{
                        newnode->next=target->next;
                        target->next=newnode;
                        length++;
                  }
            }
      }
}

void SinglyLinkList::Delete_node(int index){
      if(!head)cout<<"No any node can be deleted!\n";
      else if(index<1||index>length)cout<<"You can't delete the node out of List range!\n";
      else{
            if(index==1){
                  node* dnode=head;
                  head=head->next;
                  delete(dnode);
                  length--;
            }
            else{
                  node *previous=this->Position(index-1),*dnode=this->Position(index);
                  previous->next=dnode->next;
                  delete (dnode);
                  length--;
            }
      }
}

void SinglyLinkList::Clear(){
      while(head){
            node* temp=head;
            head=head->next;
            delete(temp);
      }
}

void SinglyLinkList::Inverse(){
      
      if(length==0||length==1)return ;
      node *trail=NULL,*mid=NULL;

      while(head){
            trail=mid;                                
            mid=head;                                 
            head=head->next;                          
            mid->next=trail;                         
      }
      head=mid;
}

int main(){

      SinglyLinkList test;

      test.Back_insert(0);
      for(int i=1;i<11;i++){
            test.Back_insert(i,i);
      }
      test.ShowList();
      test.Front_insert(12);
      test.ShowList();
      test.Delete_node(1);
      test.ShowList();
      test.Inverse();
      test.ShowList();
      test.Clear();
      test.ShowList();

      return 0;
}