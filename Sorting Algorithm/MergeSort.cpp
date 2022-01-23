#include <bits/stdc++.h>

using namespace std;

void showlist(vector<int>arr){
    for(int i=0;i<arr.size();i++)cout<<arr[i]<<" ";
    cout<<endl;
}

void Merge(vector<int>&arr,int left,int mid,int right){
    vector<int>leftsub(arr.begin()+left,arr.begin()+mid+1),
               rightsub(arr.begin()+mid+1,arr.begin()+right+1);
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
}

void MergeSort(vector<int>&arr,int left,int right){
    //流程說明：把陣列分成兩半，重複這個行為直到剩一個元素(分不了)然後在根據
    
    
    if(left<right){
        int mid=left+(right-left)/2;
        MergeSort(arr,left,mid);
        MergeSort(arr,mid+1,right);
        Merge(arr,left,mid,right);
    }
}



int main(){

    vector<int>test={7,8,2,1,5,3,4,0};
    MergeSort(test,0,test.size()-1);
    showlist(test);
    
    



    return 0;
}