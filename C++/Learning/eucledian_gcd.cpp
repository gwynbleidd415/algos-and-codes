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
    cout<<"Enter two numbers\n";
    int a,b;
    cin>>a>>b;
    int x,y;
    int gcd=eucledian(a,b,x,y);
    cout<<"GCD="<<gcd<<" x="<<x<<" y="<<y<<" HCF="<<(a*b)/gcd<<"\n";
    return 0;
}