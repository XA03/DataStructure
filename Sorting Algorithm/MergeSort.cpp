#include <bits/stdc++.h>

using namespace std;

void showlist(vector<int>arr){
    for(int i=0;i<arr.size();i++)cout<<arr[i]<<" ";
    cout<<endl;
}

void Merge(vector<int>&arr,int left,int mid,int right){
    vector<int>leftsub(arr.begin()+left,arr.begin()+mid+1),
               rightsub(arr.begin()+mid+1,arr.begin()+right+1);
    //把最大值放在後面如果其中一方到底了，就會自動排入剩下的一方的元素
    leftsub.push_back(INT_MAX);
    rightsub.push_back(INT_MAX);
    
    int leftindex=0,rightindex=0;

    for(int i=left;i<=right;i++){
        if(leftsub[leftindex]<rightsub[rightindex]){
            arr[i]=leftsub[leftindex];
            leftindex++;
        }
        else{
            arr[i]=rightsub[rightindex];
            rightindex++;
        }
    }
    showlist(arr);
}

void MergeSort(vector<int>&arr,int left,int right){
    //流程說明：把陣列分成兩半，重複這個行為直到子陣列剩一個元素再開始將子陣列依照元素大小將其倆倆合併 最後得出排序陣列
    //假設子陣列長度：A=m,B=n 合併兩個陣列的Merge  最長時間複雜度為m+n-1 最短為n 其中將m設為n的話 最長為2n-1 得O(n)
    //接著計算有幾次合併，n次長度每次對半分則有logn次Recursive，所以得出 O(nlogn)
    //Best Case: O(nlogn)
    //Average Case: O(nlogn)
    //Worst Case: O(nlogn)
    //SC: O(n) 
    
    if(left<right){
        int mid=left+(right-left)/2;
        MergeSort(arr,left,mid);
        MergeSort(arr,mid+1,right);
        Merge(arr,left,mid,right);
    }
}

int main(){

    vector<int>test={8,7,2,1,5,3,4,0};
    MergeSort(test,0,test.size()-1);

    return 0;
}