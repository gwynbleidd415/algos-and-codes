#include <bits/stdc++.h>
using namespace std;

//aaabbababbabbababaabbaa

int main(){
    cout<<"Enter the main string followed by the one to find"<<endl;
    string str,fnd;
    cin>>str>>fnd;
    int a=str.length();
    int b=fnd.length();
    vector<int> ind(b);int k=0;
    for(int i=1;i<b;++i){
        if(fnd[i]==fnd[k])
        ind[i]=++k;
        else{
            if(fnd[i]==fnd[0])
            k=1,ind[i]=1;
            else
            k=0;
        }
    }k=0;
    for(int i=0;i<a;++i){
        if(fnd[k]==str[i])
        ++k;
        else if(k!=0)
        k=ind[k-1],--i;
        if(k==b){
            cout<<"Pattern found at index "<<i-b+1<<"\n";
            k=ind[k-1];
        }
    }
    return 0;
}