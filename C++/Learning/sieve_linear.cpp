#include <bits/stdc++.h>
using namespace std;
#define m 100000

int main(){
    int arr[m];
    vector<int> pr;
    for(int i=2;i<m;++i){
        if(arr[i]==0){
            pr.push_back(i);
            arr[i]=i;
        }
        for(int j=0;pr[j]<=arr[i]&&j<pr.size()&&i*pr[j]<m;++j){
            arr[i*pr[j]]=pr[j];
        }
    }
    cout<<"Enter the number of terms\n";
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    cout<<pr[i]<<" ";
    return 0;
}