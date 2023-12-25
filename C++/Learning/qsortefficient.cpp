#include <bits/stdc++.h>
using namespace std;

pair<int,int> partition(int arr[],int s,int e){
    srand(time(0));
    int p=arr[rand()%(e-s+1)+s];
    int y=s-1,i=s-1;
    for(int j=s;j<=e;++j){
        if(arr[j]<p){
            swap(arr[++i],arr[j]);
            if(i!=++y)
            swap(arr[y],arr[j]);
        }
        else if(arr[j]==p)
        swap(arr[++y],arr[j]);
    }
    return {i,y};
}

void quicksort(int arr[],int s,int e){
    if(e<=s)
    return;
    pair <int,int> p=partition(arr,s,e);
    quicksort(arr,s,p.first);
    quicksort(arr,p.second+1,e);
}

int main(){
    cout<<"Enter the numeber of elements of the array\n";
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