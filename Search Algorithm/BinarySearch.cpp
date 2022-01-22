#include <bits/stdc++.h>

using namespace std;

//BinarySearch 二元搜尋法，非常具代表性的一種搜尋法，這個搜尋法需要容器內的元素是已經排序好的。每次我們都從中間抓一個元素
//比較它和我們的搜尋目標。大於代表要往後半部找，小於表示往前半部找，等於表示找到了。好處是範圍減少得很快

// Best Case:O(1)元素在正中間
// Average Case:O(logn)
// Worst Case:O(logn)

//BinarySearch有很多用途，用來搜尋目標元素只是最簡單的用途，它還可以找第一個大於目標元素的位置(等同於告訴你整個元素中有多少個元素比它大)，或是各式各樣的題目都會用到
//以下會嘗試展示出它的全部用途。
//BinarySearch有遞迴和迭代兩種版本

//首先從最簡單的搜尋指定目標元素開始吧

//光是left,right的設定 和 迴圈的loop condition設定就有不少細節呢.....

int BinarySearchNE(vector<int>arr,int left,int right,int target){
    int ret=-1,mid;
    // left<right 表示 區間為[left,right) 所以這裡right要用的是Size本身(因為0-indexed) 不然在縮減範圍的時候會有邊界元素被吃掉
    while(left<right){
        mid=left+(right-left)/2;  // 這樣做的意義在於 mid本來就是 (left+right)/2 可是left+right是有可能overflow的
        if(arr[mid]<target)left=mid+1;
        else if(arr[mid]>target)right=mid;  //這樣就可以避免區間-1的問題
        else{
            ret=mid;
            return mid;
        }
    }
    return ret;
}

int BinarySearchE(vector<int>arr,int left,int right,int target){
    int ret=-1,mid;
    // left<=right → [left,right)
    while(left<=right){
        mid=left+(right-left)/2;  
        if(arr[mid]<target)left=mid+1;  //為了避免 right-left=1這種情況 left和right必須都可以移動
        else if(arr[mid]>target)right=mid-1;
        else{
            ret=mid;
            return mid;
        }
    }
    return ret;
}

//上面列出的兩種BinarySearch是最簡單的搜尋指定目標 有就有沒有就沒有，但需要注意邊界的問題和loop的條件
//接下來討論Binary Search除了找指定元素外還可以做甚麼

//1.搜尋第一個在容器中>=target的值
//ge:greater and equal >=
//因為是找出來位置，不需要等於的條件(就算等於我們也要找出第一個或是最後一個)
int First_BSgeTargetNE(vector<int>arr,int left,int right,int target){
    while(left<right){
        int mid=left+(right-left)/2;
        if(arr[mid]<target)left=mid+1;
        else right=mid;//=target時縮right是因為要找第一個
    }
    return right;//這裡return right或left沒差別，因為你停止的條件是left==right
}

int First_BSgeTargetE(vector<int>arr,int left,int right,int target){
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]<target)left=mid+1;
        else right=mid-1;//right會一直縮小直到(arr[mid]<target)，又因為mid-1所以最後必然是left=right+1
    }
    return left;//或是right+1
}
//稍加變形可以變成找出第一個比目標元素大的位置也就是2.

//2.搜尋第一個在容器中>target的值

int First_BSgTargetNE(vector<int>arr,int left,int right,int target){
    while(left<right){
        int mid=left+(right-left)/2;
        if(arr[mid]<=target)left=mid+1;//變成=target時不斷增加mid
        else right=mid;
    }
    return left;
}

int First_BSgTargetE(vector<int>arr,int left,int right,int target){
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]<=target)left=mid+1;
        else right=mid-1;
    }
    return left;
}
//我們整理一下全部的搜尋關係 1.=target 2.第一個>=target 3.第一個>target (最後一個>=target位置+1) 4.第一個<=target 5.第一<target
//6.最後一個<=target 7.最後一個<target 
//整理以上關係可得出：4.沒意義，因為<=2.的答案的位置全部都是 (另一種問法是<target的元素有幾個) 不需要特別做一個新的Function 用2.就好
//5.跟4一樣只是變成<2.而已  6.跟7.很像4跟5 只是從一個區間變成2.一個或是2.前一個位置而已
//能夠問的問題不外乎就是 位置或是個數再不然就是值 基本上有位置都可以推出其他答案 
//當然，二元搜尋法的用途還有很多種。個人理解是一種區間決定的演算法，而我們的問題答案是區間的 頂點、長度這樣


int main(){

    vector<int>test={1,2,3,4,5,6,7,8,9,10},
               ge={1,2,3,3,3,4,4,4,4,7};
    //cout<<BinarySearchNE(test,0,10,10)<<endl;   //找不到 因為第一次結束後5已經變成邊界了且不包含5
    //cout<<BinarySearchE(test,0,9,10)<<endl;
    cout<<First_BSgeTargetNE(ge,0,ge.size(),3)<<endl;
    cout<<First_BSgeTargetE(ge,0,ge.size()-1,3)<<endl;
    cout<<First_BSgTargetNE(ge,0,ge.size(),3)<<endl;
    cout<<First_BSgTargetE(ge,0,ge.size()-1,3)<<endl;
    return 0;
}