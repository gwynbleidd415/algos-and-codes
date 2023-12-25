#include <bits/stdc++.h>
using namespace std;
#define bitsize 1000001

int main(){
    bitset<bitsize> bs;
    for(int i=2;i<bitsize;++i){
        if(bs[i]==0){
            int j=i*2;
            while(j<bitsize){
                bs[j]=1;
                j+=i;
            }
        }
    }
    return 0;
}