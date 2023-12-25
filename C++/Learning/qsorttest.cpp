#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int randomize()
{
    return (rand() % 1000000);
}

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
    //cout<<"Enter the numebr of elements of the array\n";
    //int n;
    //cin>>n;
    //cout<<"Enter the elements of the array\n";
    int n=900000;
    srand(time(0));
    int arr[n];
    //for(int i=0;i<n;++i)
    //cin>>arr[i];
    generate_n(arr, n, randomize);
    auto start = chrono::high_resolution_clock::now();
    quicksort(arr,0,n-1);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    //for(int i=0;i<n;++i)
    //cout<<arr[i]<<" ";
    //cout<<"\n";
    cout<<duration.count()<<" "<<n<<"\n";
    return 0;
}