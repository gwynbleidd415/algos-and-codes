#include <bits/stdc++.h>
using namespace std;

void quicksort(int arr[],int s,int e){
    if(e<=s)
    return;
    int p=arr[e];
    int i=s-1;
    for(int k=s;k<=e;++k){
        if(arr[k]<=p)
        swap(arr[++i],arr[k]);
    }
    quicksort(arr,s,i-1);
    quicksort(arr,i+1,e);
}

int main(){
    cout<<"Enter the numebr of elements of the array\n";
    int n;
    cin>>n;
    cout<<"Enter the elements of the array\n";
    int arr[n];
    for(int i=0;i<n;++i)
    cin>>arr[i];
    quicksort(arr,0,n-1);
    for(int i=0;i<n;++i)
    cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}