#include <bits/stdc++.h>

using namespace std;

// Coding 有參考 http://alrightchiu.github.io/SecondRound/linked-list-xin-zeng-zi-liao-shan-chu-zi-liao-fan-zhuan.html 之文章

//SinglyLinkList 單向鏈結串列 (單向鏈表)

class SinglyLinkList;//因為需要freind 所以得先宣告在這裡

class node{ // SinglyLinkList 中的單位節點
      private:
            int value;  //節點本身的值
            node* next; //指向下一個節點的指標
      public:
            node():value(0),next(NULL){};//constructor後的冒號是給 class data member assign的方法 如果是const data member更適合這種assignment(賦值、=)
            node(int input):value(input),next(NULL){};
  
      friend class SinglyLinkList; //表示class SinglyLinkList中可以access class node裡的 所有東西
};

class SinglyLinkList{
      private:
            int length;//SinglyLinkList長度
            node* head;//SinglyLinkList的起點
      public:
            SinglyLinkList():head(NULL){};//沒給預設值的起點是NULL
            void ShowList();//印出整個串列
            void Front_insert(int value);
            void Back_insert(int value);
            void Delete_node(int value);
            void Clear();
            void Inverse();
};

void SinglyLinkList::ShowList(){
      if(!head)cout<<"SinglyLinkList is empty!\n";
      else{
            while (head){
                  cout << head->value;
                  head = head->next;
            }
      }
}



int main(){
      SinglyLinkList test;
      test.ShowList();
    



    return 0;
}