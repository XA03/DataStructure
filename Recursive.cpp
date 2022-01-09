#include <bits/stdc++.h>

using namespace std;

int factor(int n){
    if(n==0||n==1)return 1;//0!=1 1!=1
    return n*factor(n-1);//一路向下乘
}

int fib(int n){
    if(n==1||n==0)return 1; //fib[0]=1 fib[1]=1 
    return fib(n-2)+fib(n-1);//fib[n]=fib[n-1]+fib[n-2]
}

int binomial(int n,int k){
    if(n==0)return 0;  // (x+y)^n 的 n次方項係數 0的話沒有x,y
    else if(k==0)return 1; // x^n y^n係數必為1                                              
    return binomial(n-1,k-1)+binomial(n-1,k);
}

int PermutationN(int n,int k){
    if(n==0)return 1;
    else if(n==k||k==0)return 1;
    return n*PermutationN(n-1,k-1);
}


int nHr(int n,int k){
    return binomial(n+k-1,k-1);
}

int GCD(int a,int b){
    if(b>a){
        return GCD(b,a);
    }
    else if(a==b||b==0)return a;
    return GCD(a%b,b);
}



int main(){


    return 0;
}