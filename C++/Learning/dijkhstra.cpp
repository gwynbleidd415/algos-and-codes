#include<bits/stdc++.h>
using namespace std;

struct adjList{
    int wt,ind;
    adjList *next;
};

adjList *newAdjLst(int v2,int wt){
    adjList *temp=new adjList;
    temp->wt=wt;
    temp->ind=v2;
    temp->next=NULL;
    return temp;
}

void addEdge(vector<adjList *>& vert,int v1,int v2,int wt){
    adjList *temp=newAdjLst(v2,wt);
    temp->next=vert[v1]->next;
    vert[v1]->next=temp;
    temp=newAdjLst(v1,wt);
    temp->next=vert[v2]->next;
    vert[v2]->next=temp;
}

void swapHeap(vector<int>& heap,vector<pair<int,int>>& pos,int a,int b){
    int temp=heap[a];
    heap[a]=heap[b];
    heap[b]=temp;
    temp=pos[a].second;
    pos[a].second=pos[b].second;
    pos[b].second=temp;
    pos[pos[a].second].first=a;
    pos[pos[b].second].first=b;
}

void popHeap(vector<int>& heap,vector<pair<int,int>>& pos){
    int n=heap.size()-1;
    swapHeap(heap,pos,0,n);
    //heap.pop_back();
    --n;
    int i=0;
    while(1){
        int chi=2*i+1;
        if(chi+1<=n){
            if(heap[chi]<=heap[chi+1]&&heap[i]>heap[chi])
            {swapHeap(heap,pos,i,chi);i=chi;continue;}
            else if(heap[chi+1]<heap[i])
            {swapHeap(heap,pos,chi+1,i);i=chi+1;continue;}
        }
        else if(chi==n&&heap[chi]<heap[i])
        swapHeap(heap,pos,i,chi);
        break;
    }
}

void decHeap(vector<int>& heap,vector<pair<int,int>>& pos,int v){
    int i=pos[v].first;
    //int ind=(heap[i]-1)/2;
    while(1){
        int ind=(i-1)/2;
        if(ind>=0&&heap[ind]>heap[i]){
            swapHeap(heap,pos,i,ind);
            i=ind;
            continue;
        }
        break;
    }
}

void dijkhstra(vector<adjList *>& vert,int v1,int n){
    int j=0;
    vector<int> heap,result;
    vector<pair<int,int>> pos(n);
    heap.push_back(0);pos[j].second=v1;pos[v1].first=j++;
    for(int i=0;i<n;++i){
        if(i!=v1){
            heap.push_back(INT_MAX);
            pos[j].second=i;
            pos[i].first=j++;
        }
    }
    while(!heap.empty()){
        int wt=heap[0];
        int v=pos[0].second;
        result.push_back(wt);
        popHeap(heap,pos);
        heap.pop_back();
        adjList *temp=vert[v]->next;
        while(temp){
            if(pos[temp->ind].first<heap.size()){
                if(heap[pos[temp->ind].first]>temp->wt+wt){
                    heap[pos[temp->ind].first]=temp->wt+wt;
                    decHeap(heap,pos,temp->ind);
                }
            }
            temp=temp->next;
        }
    }
    for(int i=n-1;i>=0;--i){
        cout<<pos[i].second<<"("<<result[n-1-i]<<")-->";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the number of vertices\n";
    cin>>n;
    vector<adjList *> vert(n);
    for(int i=0;i<n;++i){
        vert[i]=new adjList;
        vert[i]->wt=0;
        vert[i]->ind=i;
        vert[i]->next=NULL;
    }
    int t=1;
    while(t){
        cout<<"Choose one option...\n1.AddEdge  2.Dijkstra\n";
        int wish;
        cin>>wish;
        switch(wish){
            case 1:{
                cout<<"Enter the vertices followed by weight\n";
                int v1,v2,wt;
                cin>>v1>>v2>>wt;
                addEdge(vert,v1,v2,wt);
            }break;
            case 2:{
                cout<<"Enter the vertex for min distance\n";
                int v;
                cin>>v;
                dijkhstra(vert,v,n);
            }break;
            default:{
                t=0;
            }
        }
    }
    return 0;
}