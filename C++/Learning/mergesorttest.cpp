#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int randomize()
{
    return (rand() % 1000000);
}

void merge(int arr[],int s1,int e1,int e2){
    int s2=e1+1;
    int i=s1,j=s2,k=0;
    int temp[e2-s1+1];
    while(1){
        if(arr[i]<arr[j])
        temp[k++]=arr[i++];
        else
        temp[k++]=arr[j++];
        if(i>e1){
            while(j<=e2)
            temp[k++]=arr[j++];
            break;
        }
        else if(j>e2){
            while(i<=e1)
            temp[k++]=arr[i++];
            break;
        }
    }
    int sz=e2-s1+1;
    for(int a=0;a<sz;++a)
    arr[s1++]=temp[a];
}

void mergesort(int arr[],int s,int e){
    if(s==e)
    return;
    int m=(e+s)/2;
    mergesort(arr,s,m);
    mergesort(arr,m+1,e);
    merge(arr,s,m,e);
}

int main(){
    //cout<<"Enter the numebr of elements of the array\n";
    int n=900000;
    srand(time(0));
    //cin>>n;
    //cout<<"Enter the elements of the array\n";
    int arr[n];
    //for(int i=0;i<n;++i)
    //cin>>arr[i];
    generate_n(arr, n, randomize);
    auto start = chrono::high_resolution_clock::now();
    mergesort(arr,0,n-1);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    //for(int i=0;i<n;++i)
    //cout<<arr[i]<<" ";
    cout<<duration.count()<<" "<<n<<"\n";
    return 0;
}