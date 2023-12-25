#include <bits/stdc++.h>
using namespace std;

template <class T>
class Heapsort{
    vector<T> v;
    int n=0;
public:
    void push(T data){
        v.push_back(data);++n;
        int x=n-1;
        while(x>0&&v[(x-1)/2]<v[x]){
            swap(v[x],v[(x-1)/2]);
            x=(x-1)/2;
        }
    }
    T top(){
        return v[0];
    }
    void pop(){
        swap(v[0],v[n-1]);
        v.pop_back();--n;
        int x=0;
        while(x<(n-1)/2&&(v[x]<v[2*x+1]||v[x]<v[2*x+2])){
            if(2*x+2<n&&v[2*x+2]>v[2*x+1]){
                swap(v[x],v[2*x+2]);
                x=2*x+2;
            }
            else{
                swap(v[x],v[2*x+1]);
                x=2*x+1;
            }
        }
    }
    void display(){
        for(auto itr:v){
            cout<<itr<<" ";
        }
        cout<<"\n";
    }
};

int main(){
    int t=1;
    Heapsort<int> hs;
    while(t){
        cout<<"Enter one option...\n1.Push 2.Pop 3.Top 4.Display 5.Exit\n";
        int wish;
        cin>>wish;
        switch (wish)
        {
        case 1:
            cout<<"Enter the data\n";
            int data;
            cin>>data;
            hs.push(data);
            break;
        case 2:
            hs.pop();
            break;
        case 3:
            cout<<hs.top()<<"\n";
            break;
        case 4:
            hs.display();
            break;
        default:
            t=0;
        }
    }
    return 0;
}