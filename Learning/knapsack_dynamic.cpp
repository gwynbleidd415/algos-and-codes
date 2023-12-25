#include <bits/stdc++.h>
using namespace std;

template <class T>
class knapsack{
    public:
    T cap,num,(*arr)[2],*knap,min=1000000000,i=0;
    knapsack(T cap,T num,T (*arr)[2]){
        this->cap=cap;
        this->num=num;
        this->arr=arr;
        knap=new T[cap+1];
        for(i=0;i<cap+1;++i)
        knap[i]=0;
        for(i=0;i<num;++i){
            if(min>arr[i][0])
            min=arr[i][0];
        }
    }
    T knapf(T tcap){
        if(knap[tcap]!=0||tcap<min)
        return knap[tcap];
        T maxval=0,xx,yy,j;
        for(j=0;j<num;++j){
            if((xx=tcap-arr[j][0])>=0)
                if((yy=arr[j][1]+knapf(xx))>maxval){
                    maxval=yy;
                }
        }
        knap[tcap]=maxval;
        return maxval;
    }
};

int main(){
    cout<<"Enter the number of items\n";
    int num;
    cin>>num;
    cout<<"Enter the size followed by value\n";
    int arr[num][2];
    for(int i=0;i<num;++i)
        cin>>arr[i][0]>>arr[i][1];
    cout<<"Enter the capacity of the knapsack\n";
    int cap;
    cin>>cap;
    knapsack<int> ks(cap,num,arr);
    cout<<ks.knapf(cap)<<"\n";
    return 0;
}