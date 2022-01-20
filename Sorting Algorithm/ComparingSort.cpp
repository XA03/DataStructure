#include <bits/stdc++.h>

using namespace std;

//參考文章 http://notepad.yehyeh.net/Content/Algorithm/Sort/Sort.php
//        https://wangwilly.github.io/willywangkaa/2018/08/28/Algorithm-Time-Complexity/
//        http://alrightchiu.github.io/SecondRound/comparison-sort-insertion-sortcha-ru-pai-xu-fa.html

//Sorting，排序。需要排序不是因為資料排整齊比較好看，是排序後的資料才能做有效率的搜尋。在滿坑滿谷的資料中搜尋我們需要的才是現實需要的功能。
//以資料量區分成內部和外部排序兩種，內部因為量少的關係可以塞進記憶體內，外部則是透過儲存裝置分次載入一部分並針對載入的部分做內部排序
//一般Sorting指的都是內部排序，接下來我們以相同值間的相對位置會不會改變分成穩定和不穩定排序
// 例如：3,2,2* 排序完後 2,2*,3是穩定  2*,2,3是不穩定 但從單一值上無法得知這兩個位置是否有交換
// In-Place 指的是在原本的容器內進行排序，不使用另外的記憶體空間暫存
// 排序演算法不一定要實際把兩個元素拿來做比較，也可以使用其他方法來做排序

//基於比較的排序演算法我們可以透過 夾擠定理或是單純的邏輯推論出 TC=nlogn
//先說明以單純的邏輯是怎麼推論的，首先我們有n個相異元素 所以可以有n!種不同的排列方式
//那我們比較的邏輯是抓出兩個元素 比較他們的大小 只會有兩種情況：A>B 或 B>A
//那我們每次比較完後就可以剔除不符合大小關係的一半排列了，我們假設m次後排序完成
//得出 n!/2^m<=1  得log(n!)<=m  也就是說 我們至少需要log(n!)次 才能排序完成 而log(n!)=O(nlogn)
//另外證明 log(n!)=O(nlogn) 首先 我們對數皆以二為底，真數相乘=對數相加 所以可以將log(n!)=log(n)+log(n+1)+.....+log1 (共n項)
//nlogn=n項*logn 所以在C=1 N0=1的情況下得 log(n!)<=1*nlogn for n>=n0 於是 log(n!)=O(nlogn).
//我們現在有了log(n!)的upper bound了，現在我們來看看為甚麼只要是比較的排序演算法，他的最佳時間複雜度一定是nlogn

//計算lower bound，首先log(n!)=log(n)+log(n-1)+....+log1 >= log(n/2)+log((n/2)-1)+....log(1) >= (n/2)*log(n/2)
//(n/2)*log(n/2)=(n/2)*(logn-log2) 真數相除=對數相減 ~= (n/2)*log(n)
// 在C=1/2 n0=1 n>=n0 的情況下得 log(n!)>=(1/2)*n*log(n)  log(n!)=Omega(nlogn)

//驚奇的發現 log(n!)居然上下界相同欸 ， 所以 log(n!)=Theta(nlogn) ，於是得證 只要是基於比較的排序演算法，其最佳的時間複雜度必然是nlogn
//接下來開始介紹 各種基於比較的演算法

void showlist(vector<int>arr){
    for(int i=0;i<arr.size();i++)cout<<arr[i]<<" ";
    cout<<endl;
}

void BubbleSort(vector<int>arr){

    //流程說明：首先我們將容器分為未排序和已排序的部分，如果前一筆>後一筆則交換，只要還有未排序的部分，就繼續執行下去直到容器尾巴
    //優化：只要在未排序的部分中比對都沒有交換位置→代表 未排序的部分本身已有序 + 已排序的部分 整體排序完成 →退出loop
    //時間複雜度 (Time Complexity)Best Case
    //Best Case:O(n) 只需要跑一輪就退出，表示本來就是排序好的 (n-1)次比較 所以次數=O(n)
    //Worst Case:O(n^2) 因為每次都要交換直到最後一輪的最後一次才會完成 所以次數=(n-1)+(n-2)+.....+1=n*(n-1)/2=O(n^2)
    //Average Case:O(n^2) 但Average Case的證明我們之後再補上 Average不是邊界狀況，我們需要模擬平均的狀況才能證明
    //Space Complexity : 只需要一個變數用來暫存交換時的變數值
    //Stable Sort，理由是等於時不會交換

    bool end=false;//用來提前退出的條件
    for(int i=0;i<arr.size()-1&&!end;i++){
        end=true;
        for(int j=0;j<arr.size()-1-i;j++){//因為是兩兩比較，所以不需要跑到最後一個元素(沒有下一個可以比了)，-i表示前面已經有排序好的元素了，不需要多檢查。
            if(arr[j]>arr[j+1]){//用來控制由小到大或是由大到小的排序方式，但一般來說，bubble就是小的會往上浮 所以還是由小排到大較合適 (個人觀念)
                swap(arr[j],arr[j+1]);
                end=false;//只有有產生交換就表示這一輪還不能退出
            }
        }
        //每一輪都會檢查未排序的部分，若檢查完發現未排序的部分都已經排好了，會提前退出。
    }
    showlist(arr);
}

int SelectionSort(vector<int>arr){
    
    //流程說明，將資料分成已排序和未排序，從未排序的部分取出 最大值 或是 最小值加入到已排序的尾巴
    //Best Case: O(n^2)     就算排好也得(n-1)+(n-2)+....+1次=n*(n-1)/2 =O(n^2)
    //Average Case: O(n^2)  
    //Worst Case: O(n^2)
    //SC :一樣只需要一個變數來暫存交換時的變數值
    //Unstable Sort，舉個例子說明  {2*,3,1,4,2}的流程是→{1,3,2*,4,2}→{1,2*,3,4,2}→{1,2*,2,3,4} 由此可知2*,2明明值相同但是位置卻交換了ㄋ
    int index;

    for(int i=0;i<arr.size()-1;i++){
        index=i;//紀錄已排序的尾巴
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[index])index=j;
        }
        if(i!=index)swap(arr[i],arr[index]);//如果有符合條件的值要被交換過去
    }
    showlist(arr);
}

void InsertionSort(vector<int>arr){
    
}


int main(){

    vector<int>test={7,8,2,1,5,4,3,0};



    return 0;
}