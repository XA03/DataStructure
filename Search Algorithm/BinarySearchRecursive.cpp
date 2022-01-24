#include <bits/stdc++.h>

using namespace std;

int  BinarySearchRecursive(vector<int>arr,int left,int right,int target){
    if(left<right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target)return mid;
        else if(arr[mid]<target)return BinarySearchRecursive(arr,mid+1,right,target);
        return BinarySearchRecursive(arr,left,mid,target);
    }
    return -1;
}



int main(){

    vector<int>test={1,2,3,4,5,6,7,8};
    cout<<BinarySearchRecursive(test,0,test.size(),-2);


    return 0;
}