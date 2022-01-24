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

int GCD(int a,int b){
    if(b==0)return a;
    return GCD(b,a%b);
}

int Permutation(int n,int k){
    if(k==0)return 1;
    if(n==k)return factor(n);
    else if(k>n){
        cout<<"Invalid !\n";
        return -1;
    }
    return n*Permutation(n-1,k-1);
}

int Combination(int n,int k){
    if(n==k||k==0)return 1;
    else if(k>n){
        cout<<"Invalid !\n";
        return -1;
    }
    return Combination(n-1,k-1)+Combination(n-1,k);
}

int nHr(int n,int k){
    return Combination(n+k-1,k);
}



int main(){
    
    cout<<factor(5)<<endl; 
    cout<<fib(5)<<endl;    
    cout<<GCD(17,51)<<endl;
    cout<<Permutation(32,5)<<endl;
    cout<<Combination(1231,1228)<<endl;
    cout<<nHr(10,2)<<endl;


    return 0;
}