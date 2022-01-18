#include <bits/stdc++.h>

using namespace std;

//參考文章 http://notepad.yehyeh.net/Content/Algorithm/Sort/Sort.php
//        https://wangwilly.github.io/willywangkaa/2018/08/28/Algorithm-Time-Complexity/

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




int main(){





    return 0;
}