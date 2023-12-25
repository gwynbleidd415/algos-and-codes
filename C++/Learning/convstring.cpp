#include <bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter the main string followed by the one to convert"<<endl;
    string str1,str2;
    cin>>str1>>str2;
    int l1=str1.length();
    int l2=str2.length();
    vector<vector<int>> v(l1+1,vector<int>(l2+1));
    for(int i=0;i<=l1;++i)
    v[i][l2]=l1-i;
    for(int i=0;i<=l2;++i)
    v[l1][i]=l2-i;
    for(int i=l1-1;i>=0;--i){
        for(int j=l2-1;j>=0;--j){
            if(str1[i]==str2[j])
            v[i][j]=v[i+1][j+1];
            else{
                v[i][j]=1+min(v[i+1][j+1],min(v[i][j+1],v[i+1][j]));
            }
        }
    }
    cout<<"The min num of steps="<<v[0][0];
    return 0;
}