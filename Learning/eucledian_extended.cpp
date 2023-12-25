#include <bits/stdc++.h>
using namespace std;

template <typename T>
T gcd(T a,T b,T *x,T *y){
    if(b==0){
        *x=1;*y=0;
        return a;
    }
    T x1,y1;
    T temp=gcd(b,a%b,&x1,&y1);
    *x=y1;
    *y=x1-(a/b)*y1;
    return temp;
}

int main(){
    cout<<"Enter Two numbers\n";
    long long int a,b,x,y;
    cin>>a>>b;
    cout<<gcd<long long int>(a,b,&x,&y)<<'\n';
    x=(x%b+b)%b;
    y=(y%a+a)%a;
    cout<<"Modulo multiplicative inverse of a is "<<x<<" and b is "<<y<<"\n";
    return 0;
}