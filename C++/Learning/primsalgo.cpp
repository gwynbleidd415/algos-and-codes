#include <bits/stdc++.h>
using namespace std;

class minHeap{
    int n,size;
    vector<pair<int,int>> wt;
    vector<int> par;
    vector<int> pos;
public:
    minHeap(int n){
        this->n=n;
        size=n-1;
        par.resize(n,0);
        for(int i=0;i<n;++i){
            wt.push_back(make_pair(INT_MAX,i));
            pos.push_back(i);
        }
        wt[0].first=0;
    }
    int top(){
        return wt[0].second;
    }
    bool empty(){
        return (size==-1);
    }
    void pop(){
        swap(pos[wt[0].second],pos[wt[size].second]);
        swap(wt[0],wt[size--]);
        //swap(pos[wt[0].second],pos[wt[size--].second]);
        int i=0;
        while(1){
            int ind=2*i+1;
            if((ind+1<=size)&&(wt[i].first>wt[ind].first||wt[i].first>wt[ind+1].first)){
                if(wt[ind].first<wt[ind+1].first){
                    swap(pos[wt[i].second],pos[wt[ind].second]);
                    swap(wt[i],wt[ind]);
                    //swap(pos[i],pos[ind]);
                    i=ind;
                }
                else{
                    swap(pos[wt[i].second],pos[wt[ind+1].second]);
                    swap(wt[i],wt[ind+1]);
                    //swap(pos[i],pos[ind+1]);
                    i=ind+1;
                }
            }
            else if(ind==size&&wt[i].first>wt[ind].first){
                swap(pos[wt[i].second],pos[wt[ind].second]);
                swap(wt[i],wt[ind]);
                //swap(pos[wt[i].second],pos[wt[ind].second]);
                i=ind;
            }
            else
            break;
        }
    }
    void update(int v1,int v2,int weight){
        if(weight<wt[pos[v1]].first&&pos[v1]<=size){
            int i=pos[v1];
            par[v1]=v2;
            wt[i].first=weight;
            int ind=(i-1)/2;
            while(ind>=0){
                if(wt[i].first<wt[ind].first){
                    swap(wt[i],wt[ind]);
                    swap(pos[wt[i].second],pos[wt[ind].second]);
                    i=ind;
                    ind=(i-1)/2;
                }
                else
                break;
            }
        }
    }
    void display(){
        for(int i=0;i<n;++i)
        cout<<wt[n-1-i].second<<" "<<wt[n-1-i].first<<" "<<par[wt[n-1-i].second]<<"\n";
    }
};

class graph{
    int n;
    vector<vector<int>> *edge;
public:
    graph(int n){
        this->n=n;
        edge=new vector<vector<int>>[n];
    }
    void addEdge(int v1,int v2,int wt){
        edge[v1].push_back(vector<int>{v2,wt});
        edge[v2].push_back(vector<int>{v1,wt});
    }
    void display(){
        for(int i=0;i<n;++i){
            cout<<i<<"===>";
            for(auto itr:edge[i])
            cout<<itr[0]<<" "<<itr[1]<<"-->";
            cout<<"\n";
        }
    }
    void prims(){
        minHeap mst(n);
        while(!mst.empty()){
            int v=mst.top();
            mst.pop();
            for(auto itr:edge[v])
            mst.update(itr[0],v,itr[1]);
        }
        mst.display();
    }
};

int main(){
    cout<<"Enter the number of vertices\n";
    int n;int t=1;
    cin>>n;
    graph g(n);
    while(t){
        cout<<"Choose one option...\n 1.Add edge  2.prims's mst  3.Exit\n";
        int wish;
        cin>>wish;
        switch(wish){
            case 1:{
                cout<<"Enter the vertices followed by weight\n";
                int v1,v2,wt;
                cin>>v1>>v2>>wt;
                g.addEdge(v1,v2,wt);
            }break;
            case 2:{
                g.prims();
            }break;
            default:{
                t=0;
            }
        }
    }
    return 0;
}