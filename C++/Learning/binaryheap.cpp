#include <bits/stdc++.h>
using namespace std;

int minm(int a,int b,int x,int ,int y){
    return (a<b)?x:y;
}

int main(){
    vector<int> arr;
    int t=1;
    while(t){
        cout<<"Choose one option...\n1.Insertion  2.Extraction  3.Display  4.End"<<endl;
        int wish;
        cin>>wish;
        switch(wish){
            case 1:{
                cout<<"Enter data to enter\n";
                int data;
                cin>>data;
                arr.push_back(data);
                int n=arr.size()-1;
                while(n>=0&&arr[(n-1)/2]>arr[n]){
                    swap(arr[(n-1)/2],arr[n]);
                    n=(n-1)/2;
                }
            }
            break;
            case 2:{
                cout<<"The min element="<<arr[0]<<endl;
                int n=arr.size()-1;
                if((!(n&1))&&arr[n]<arr[n-1])
                swap(arr[n],arr[n-1]);
                swap(arr[0],arr[n]);
                arr.pop_back();--n;
                int i=0;
                while(1){
                    if(2*i+2<=n&&min(arr[2*i+1],arr[2*i+2])<arr[i]){
                        if(arr[2*i+1]<arr[2*i+2]){
                            swap(arr[2*i+1],arr[i]);
                            i=2*i+1;
                        }
                        else{
                            swap(arr[2*i+2],arr[i]);
                            i=2*i+2;
                        }
                        continue;
                    }
                    else if(2*i+1<=n&&arr[i]>arr[2*i+1]){
                        swap(arr[2*i+1],arr[i]);
                        i=2*i+1;
                        continue;
                    }
                    break;
                }
            }
            break;
            case 3:{
                vector<int>::iterator i;
                for(i=arr.begin();i<arr.end();++i){
                    cout<<*i<<" ";
                }
                cout<<endl;
            }
            break;
            default:{
                t=0;
            }
        }
    }
    return 0;
}