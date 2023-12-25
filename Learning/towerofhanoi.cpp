#include <bits/stdc++.h>
using namespace std;

void toh(int num,char a,char b,char c){
    if(num==1){
        if(a==c)
        return;
        else{
            cout<<"move disk 1 from "<<a<<" to "<<c<<"\n";
            toh(1,c,b,c);
        }
    }
    else{
        toh(num-1,a,c,b);
        cout<<"move disk "<<num<<" from "<<a<<" to "<<c<<"\n";
        toh(num-1,b,a,c);
    }
}

int main()
{
    int num;
    char a,b,c;
    cout<<"Enter the number of disks\n";
    cin>>num;
    cout<<"Enter the starting position followed by spare & then ending position in characters\n";
    cin>>a>>b>>c;
    toh(num,a,b,c);
    return 0;
}