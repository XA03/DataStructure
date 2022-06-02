#include <bits/stdc++.h>

#define isfull(ptr) (!(ptr))  //macre 將 isfull(ptr) 判讀成 (!(ptr))
#define maxsize 24

//timecomplexity: O(n)+O(m)+O(m+n)=O(m+n).

typedef struct node* nodepointer;
typedef struct node{
    int data;
    nodepointer next;
};
using namespace std;

int main(){
    int range,i,j;
    short out[maxsize];
    nodepointer seq[maxsize];
    nodepointer x,y,top;

    cin>>range;
    
    for(i=0;i<range;i++){//initialize 
        out[i]=true;
        seq[i]=NULL;    
    }

    cin>>i>>j;

    while(i>=0){
        x=(nodepointer)malloc(sizeof(node));
        if(isfull(x)){
            cout<<"memory 不夠拿\n";
            break;
        }
        x->data=j,x->next=seq[i],seq[i]=x;//產生node(j) 接在seq[i]鏈的頭前面成為新的seq[i]起點。 push_front的概念
        

        //equivalence class有對稱性所以一組pair 產生兩個node

        x=(nodepointer)malloc(sizeof(node));
        if(isfull(x)){
            cout<<"memory 不夠拿\n";
            break;
        }
        x->data=i,x->next=seq[j],seq[j]=x;
        cin>>i>>j;
    }
    
    for(i=0;i<range;i++){
        if(out[i]){//還沒經過的節點
        	cout<<"new class :"<<i<<"  ";
        	out[i]=false;
        	x=seq[i],top=NULL;
            while(true){
            	while(x){//開始走seq[x]的鏈
                	j=x->data;
                	if(out[j]){
                    	cout<<j<<"  ";
                    	out[j]=false;
                    	y=x->next;
                    	x->next=top;
                    	top=x;
                    	x=y;
                	}
                	else x=x->next;
            	}
        	if(!top)break;//走別條鏈，因為transitive
        	x=seq[top->data];
        	top=top->next;
        	}
        	cout<<endl;
    	}
    }

    return 0;
}