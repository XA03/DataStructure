#include <bits/stdc++.h>

using namespace std;

//  Set 是一種無序但是有根的資料結構，這裡使用Array來實現Set

void showlist(int *arr){
    for(int i=0;i<6;i++)cout<<arr[i]<<" ";
    cout<<endl;
}


int FindSetCollapsing(int *subset,int i){   //讓FindSet的時間複雜度降低成O(1)
    int root;
    for(root=i;subset[root]>=0;root=subset[root]); // subset[i]開始一直找到subset[root]<0為止 (也就是root)

    while(i!=root){             
        int parent=subset[i]; //subset[i]在ArraySet意義就是指該元素的父節點 
        subset[i]=root;       //把i的父節點改成root
        i=parent;             //移動到原本的父節點
    }

    /*
      上方的while會把所有查詢路徑上的node的根節點都直接變成root，原因是若這Set的樹結構最後退化成Linked List時查詢操作會到O(n)
      但做了這個loop後，可以變成O(1) 這叫 Path Compression，縮減了Set Tree的高度
    */
    return root;
}

/*int* FindSetHeight(int *subset,int i,int size){  
    int root,height=1;
    for(root=i;subset[root]>=0;root=subset[root]); 

    while(i!=root){
        i=subset[i];
        height++;
    }

    return height;
}*/


void UnionSetByRank(int *subset,int a,int b){ //把a節點跟b節點兩點各自所在的set聯集，聯集方式以節點數決定
    int aroot=FindSetCollapsing(subset,a),
        broot=FindSetCollapsing(subset,b);
    
    //if(aroot==broot)return;


    if(abs(subset[aroot])>=abs(subset[broot])){
        subset[aroot]+=subset[broot];
        subset[broot]=aroot;
    }
    else{
        subset[broot]+=subset[aroot];
        subset[aroot]=broot;
    }
}
/*
void UnionSetByHeight(int *subset,int a,int b){//聯集方式用Set Tree的高度決定
    int aheight=FindSetHeight(subset,a),
        bheight=FindSetHeight(subset,b),
        aroot=FindSetCollapsing(subset,a),
        broot=FindSetCollapsing(subset,b);
        
    if(aheight>=bheight){
        subset[aroot]+=subset[broot];
        subset[broot]=aroot;
    }
    else{
        subset[broot]+=subset[aroot];
        subset[aroot]=broot;
    }
}
*/
int main(){

    int test[6]={-4,0,-2,1,2,3};
    //int testheight[6];
    cout<<FindSetCollapsing(test,4)<<endl;
    UnionSetByRank(test,0,2);
    showlist(test);
    return 0;
}

// FindSetHeight 目前沒有一個特別好的想法可以在O(n)得出Set Tree Height方法 因為本身追蹤Tree的方式是Bottom Up但我如果想在任一節點直接得出Set
// Tree的高度是不可行的 (因為我從root沒辦法往下找)，所以我一定要跑全部節點的Height才可以得到Tree Height 還要同步更新Set Height的最大值，只要
// 是屬於同一個Set的Node 於是把Union By Height和Find Height先註解掉，有好的想法再修改