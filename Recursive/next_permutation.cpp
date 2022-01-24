#include <bits/stdc++.h>

using namespace std;

void next_perm(string in,int start,int size){
    if(start==size)cout<<in<<endl;
    else{
        for(int i=start;i<size;i++){    
            swap(in[start],in[i]);      
            next_perm(in,start+1,size); 
            swap(in[start],in[i]);      
        }
    }
}


int main(){

    string str="abc";
    next_perm(str,0,str.size());

    return 0;
}