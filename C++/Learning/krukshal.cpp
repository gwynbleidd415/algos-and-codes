#include <bits/stdc++.h>
using namespace std;

int cmpFunc(vector<int> v1,vector<int> v2){
    return (v1[2]<v2[2]);
}

class disjointSets{
    int n;
    vector<int> parent;
    vector<int> rank;
public:
    disjointSets(int n){
        this->n=n;
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;++i)
        parent[i]=i;
    }
    int find(int v){
        while(parent[v]!=v){
            parent[v]=parent[parent[v]];
            v=parent[v];
        }
        return v;
    }
    void unite(int v1,int v2){
        int a=find(v1);
        int b=find(v2);
        if(rank[a]>rank[b]){
            parent[b]=a;
        }
        else if(rank[b]>rank[a]){
            parent[a]=b;
        }
        else{
            ++rank[b];
            parent[a]=b;
        }
    }
};

class graph{
    //vector<vector<int>> edge;
public:
    vector<vector<int>> edge;
    void addEdge(int v1,int v2,int wt){
        edge.push_back(vector<int>(3));
        edge.back()[0]=v1;
        edge.back()[1]=v2;
        edge.back()[2]=wt;
    }
    void sorting(){
        sort(edge.begin(),edge.end(),cmpFunc);
    }
    void display(){
        for(auto i:edge){
            cout<<i[0]<<" "<<i[2]<<" "<<i[1]<<"\n";
        }
    }
};

void krukshal(graph& edges, int n){
    edges.sorting();
    disjointSets group(n);
    graph g2;
    vector<vector<int>>::iterator i;
    for(i=edges.edge.begin();i<edges.edge.end();++i){
        if(group.find((*i)[0])!=group.find((*i)[1])){
            g2.addEdge((*i)[0],(*i)[1],(*i)[2]);
            group.unite((*i)[0],(*i)[1]);
        }
    }
    g2.display();
}

int main(){
    cout<<"Enter the number of vertices\n";
    int n;int t=1;
    cin>>n;
    graph edges;
    while(t){
        cout<<"Choose one option...\n 1.Add edge  2.Krukshal's mst  3.Exit\n";
        int wish;
        cin>>wish;
        switch(wish){
            case 1:{
                cout<<"Enter the vertices followed by weight\n";
                int v1,v2,wt;
                cin>>v1>>v2>>wt;
                edges.addEdge(v1,v2,wt);
            }break;
            case 2:{
                krukshal(edges,n);
            }break;
            default:{
                t=0;
            }
        }
    }
    return 0;
}