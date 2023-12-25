#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int eucledian(int a,int b,int &x,int &y){
    int tx,ty;
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int gcd=eucledian(b,a%b,tx,ty);
    x=ty;
    y=tx-(a/b)*ty;
    return gcd;
}

int main(){
    cout<<"Enter the equation of the form (ax+by=c)"<<endl;
    string str;
    cin>>str;
    int a[3],j=0,k=0,t=0;
    for(auto i:str){
        if(!isdigit(i)){
            if(k!=0){
                if(t==1)
                a[j++]=-k;
                else
                a[j++]=k;
                k=0;
            }
            if(i=='-')
            t=1;
            else
            t=0;
            continue;
        }
        k=k*10+i-'0';
    }
    a[j]=(t==0)?k:-k;
    int x,y;
    int gcd=eucledian(abs(a[0]),abs(a[1]),x,y);
    double ax,ay;
    ax=1.0*x/gcd*a[2];
    ay=1.0*y/gcd*a[2];
    if(a[0]<0)
    ax=-ax;
    if(a[1]<0)
    ay=-ay;
    cout<<"x="<<ax<<" y="<<ay<<"\n";
    return 0;
}