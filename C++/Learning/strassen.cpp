#include <bits/stdc++.h>
using namespace std;

vector<vector <int>> matrixadd(vector<vector<int>> &a,vector<int> &b,vector<int> v,int n){
    //
}

vector<vector<int>> matrixmult(vector<vector<int>> &a,vector<vector<int>> &b,vector<int> v,int n){
    if(n==2){
        int a1=a[v[0]][v[1]]*b[v[2]][v[3]];
        int a2=a[v[0]][v[1]]*b[v[2]][v[3]];
        int a3=a[v[0]][v[1]]*b[v[2]][v[3]];
        int a4=a[v[0]][v[1]]*b[v[2]][v[3]];
    }
}

int main(){
    cout<<"Enter the order of the matrix\n";
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(n,0));
    vector<vector<int>> b(n,vector<int>(n,0));
    vector<vector<int>> c(n,vector<int>(n,0));
    cout<<"Enter the components of vector a\n";
    for(int i=0;i<n;++i){
        cout<<"Enter the elements of row "<<(i+1)<<"\n";
        for(int j=0;j<n;++j)
        cin>>a[i][j];
    }
    cout<<"Enter the components of vector b\n";
    for(int i=0;i<n;++i){
        cout<<"Enter the elements of row "<<(i+1)<<"\n";
        for(int j=0;j<n;++j)
        cin>>b[i][j];
    }
    vector<int> v={0,0,0,0};
    c=matrixmult(a,b,c,n,v);
    return 0;
}