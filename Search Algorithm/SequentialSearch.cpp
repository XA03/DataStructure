#include <bits/stdc++.h>

using namespace std;



//Sequential Search 是最基本的搜尋方法，從一個容器的頭找到尾 有的話想辦法輸出位置，或是符合條件的值。找不到通常回傳-1;
// Best Case:O(1) 元素在開頭
// Average Case:O(n) 應該是n/2表示在中間不過TC是不管常數的所以是n
// Worst Case:O(n) 跑完整個容器共n個 

// Space Complexity(空間複雜度):O(1) 表示不需要另外的空間來執行
// Sequential Search沒有遞迴法 就直接找就好了

int Search(vector<int>arr,int target){
    for(int i=0;i<arr.size();i++)if(arr[i]==target)return i;
    return -1;
}


int main(){

    vector<int>test={1,2,3,4,5,6,7};
    
    cout<<Search(test,8)<<endl;
    cout<<Search(test,4)<<endl;

    return 0;
}