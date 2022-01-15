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

int BinarySearch(vector<int>arr,int left,int right,int target){
    int ret=-1,mid;

    while(left<=right){
        mid=left+(right-left)/2;  // 這樣做的意義在於 mid本來就是 (left+right)/2 可是left+right是有可能overflow的 (而且部分題目很喜歡這樣搞)
        if(arr[mid]<target)left=mid+1;
        else if(arr[mid]>target)right=mid-1;
        else{
            ret=mid;
            return mid;
        }
    }


    return ret;
}


int main(){

    vector<int>test={1,2,3,4,5,6,7,8,9,10};
    cout<<BinarySearch(test,0,10,4);






    return 0;
}