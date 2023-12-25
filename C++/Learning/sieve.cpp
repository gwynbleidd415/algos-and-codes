#include <bits/stdc++.h>
using namespace std;
#define m 10000001
#define mm 20000000

int main(){
    bitset<m> np;
    long long int i,j,t,k;
    for(i=2;i<m;i++){
        t=2*i-1;
        if(t*t>mm)
        break;
        if(np[i]==0){
            for(j=t*t;j<mm;j+=2*t)
            {
                k=(j+1)/2;
                np[k]=1;
            }
        }
    }
    cout<<"Enter the n\n";
    int n;
    cin>>n;
    if(n>=2)
    cout<<1<<" "<<2;
    else if(n==1)
    cout<<1;
    int nn=(n+1)/2;
    for(i=2;i<=nn;++i)
    if(!np[i])
    cout<<" "<<i*2-1;
    cout<<"\n";
    return 0;
}