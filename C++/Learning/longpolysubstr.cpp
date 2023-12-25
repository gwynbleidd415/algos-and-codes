#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter the string"<<endl;
    string str;
    cin>>str;
    int l=str.length();
    vector<vector<int>> v(l,vector<int>(l));
    for(int i=0;i<l-1;++i){
        v[i][i]=1;
        if(str[i]==str[i+1])
        v[i][i+1]=2;
        else
        v[i][i+1]=1;
    }
    v[l-1][l-1]=1;
    for(int i=l-3;i>=0;--i){
        for(int j=i+2;j<l;++j){
            if(str[i]==str[j]){
                if(v[i+1][j-1]==j-i-1)
                v[i][j]=2+v[i+1][j-1];
                else
                v[i][j]=max(v[i+1][j],v[i][j-1]);
            }
            else
            v[i][j]=max(v[i+1][j],v[i][j-1]);
        }
    }
    cout<<"The max substring is="<<v[0][l-1];
    return 0;
}