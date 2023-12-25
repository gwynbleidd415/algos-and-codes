#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int randomize()
{
    return (rand() % 1000000);
}

pair<int,int> partition(int arr[],int s,int e){
    srand(time(0));
    swap(arr[rand()%(e-s+1)+s],arr[e]);
    int p=arr[e];
    int x=s-1,y=e,i=s-1,j=e;
    while(1){
        while(arr[++i]<p);
        while(arr[--j]>p)
        if(j==s)
        break;
        if(i>=j) break;
        swap(arr[i],arr[j]);
        if(arr[i]==p)
        swap(arr[++x],arr[i]);
        if(arr[j]==p)
        swap(arr[--y],arr[j]);
    }
    swap(arr[i],arr[e]);
    int temp;
    for(temp=i-1;temp>=i-1-x+s;--temp)
    swap(arr[temp],arr[i-1-temp]);
    for(temp=i+1;temp<i+1+e-y;++temp)
    swap(arr[temp],arr[e-(i+1)-temp-1]);
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
    //cout<<"Enter the numeber of elements of the array\n";
    srand(time(0));
    //int n=rand()%1000000;
    int n=900000;
    //cin>>n;
    //cout<<"Enter the elements of the array\n";
    int arr[n];
    generate_n(arr, n, randomize);
    //for(int i=0;i<n;++i)
    //cin>>arr[i];
    auto start = chrono::high_resolution_clock::now();
    quicksort(arr,0,n-1);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    //for(int i=0;i<n;++i)
    cout<<duration.count()<<" "<<n<<"\n";
    //cout<<"\n";
    return 0;
}