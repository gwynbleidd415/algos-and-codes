#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

double operate(double a,double b,int sg){
    switch(sg){
        case 0:
        return a+b;
        case 1:
        return a-b;
        case 2:
        return a*b;
        case 3:
        return a/b;
    }
    return 0;
}

void display(vector<vector<double>> &vec){
    int n=vec.size();
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
        cout<<setw(3)<<vec[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}

int main(){
    cout<<"Enter the expression without paranthesis using (+,-,*,/) only"<<endl;
    string str;
    cin>>str;
    int l=str.length();
    vector<int> ind;
    for(int i=0;i<l;++i)
    if(str[i]=='+'||str[i]=='-'||str[i]=='/'||str[i]=='*')
    ind.push_back(i);
    ind.push_back(l);
    int n=ind.size();
    vector<vector<double>> mi(n,vector<double>(n,0)),ma(n,vector<double>(n,0));
    unordered_map<char,int> sg;
    sg['+']=0,sg['-']=1,sg['*']=2,sg['/']=3;int jj=0,kk=0;
    for(int i=0;i<=l;++i){
        if(i==l||(!isdigit(str[i]))){
            mi[kk][kk]=stod(str.substr(jj,i-jj));
            ma[kk][kk]=mi[kk][kk];
            ++kk;jj=i+1;
        }
    }
    for(int k=1;k<n;++k){
        for(int i=0;i<n-k;++i){
            int j=i+k;
            int l=1;
            double mx,mn;
            int w=operate(ma[i][i],ma[i+1][j],sg[str[ind[i]]]);
            int x=operate(ma[i][i],mi[i+1][j],sg[str[ind[i]]]);
            int y=operate(mi[i][i],ma[i+1][j],sg[str[ind[i]]]);
            int z=operate(mi[i][i],mi[i+1][j],sg[str[ind[i]]]);
            mx=max(max(max(w,x),y),z);
            mn=min(min(min(w,x),y),z);
            while(l<k){
                w=operate(ma[i][i+l],ma[i+l+1][j],sg[str[ind[i+l]]]);
                x=operate(ma[i][i+l],mi[i+l+1][j],sg[str[ind[i+l]]]);
                y=operate(mi[i][i+l],ma[i+l+1][j],sg[str[ind[i+l]]]);
                z=operate(mi[i][i+l],mi[i+l+1][j],sg[str[ind[i+l]]]);
                int temp=max(max(max(w,x),y),z);
                if(temp>mx)
                mx=temp;
                temp=min(min(min(w,x),y),z);
                if(temp<mn)
                mn=temp;
                ++l;
            }
            mi[i][j]=mn,ma[i][j]=mx;
            display(ma);
        }
    }
    cout<<"Max="<<ma[0][n-1]<<"\n";
    cout<<"Min="<<mi[0][n-1]<<"\n";
    return 0;
}