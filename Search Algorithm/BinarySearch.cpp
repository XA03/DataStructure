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

int BSgeNum(vector<int>arr,int left,int right,int target){
    
}



int main(){

    vector<int>test={1,2,3,4,5,6,7,8,9,10};
    cout<<BinarySearchNE(test,0,10,10)<<endl;   //找不到 因為第一次結束後5已經變成邊界了且不包含5
    cout<<BinarySearchE(test,0,9,10)<<endl;


    return 0;
}