#include <bits/stdc++.h>
using namespace std;

struct adjList{
    int v1;
    int v2;
    int wt;
    adjList *next;
};

adjList *createEdge(int v1,int v2,int wt){
    adjList *temp=new adjList;
    temp->next=NULL;
    temp->v1=v1;
    temp->v2=v2;
    temp->wt=wt;
    return temp;
}

void addEdge(adjList *head,int v1,int v2,int wt){
    adjList *temp=createEdge(v1,v2,wt);
    temp->next=head->next;
    head->next=temp;
    temp=createEdge(v2,v1,wt);
    temp->next=head->next;
    head->next=temp;
}

void bellmanford(adjList *head,int v,int n){
    vector<pair<unsigned int,unsigned int>> result(n);
    result[v]=make_pair(v,0);
    for(int i=0;i<n;++i){
        if(i!=v){
            result[i]=make_pair(v,INT_MAX);
        }
    }
    int j=n-1;
    while(j--){
        adjList *temp=head;
        while(temp){
            if(temp->wt+result[temp->v1].second<result[temp->v2].second){
                result[temp->v2].second=temp->wt+result[temp->v1].second;
                result[temp->v2].first=temp->v1;
            }
            temp=temp->next;
        }
    }
    cout<<v<<" "<<result[v].second<<" "<<result[v].first<<"\n";
    for(int i=0;i<n;++i){
        if(i!=v)
            cout<<i<<" "<<result[i].second<<" "<<result[i].first<<"\n";
    }
}

int main(){
    cout<<"Enter the number of vertices\n";
    int n;int t=1;
    cin>>n;
    adjList *edge=NULL;
    while(t){
        cout<<"Choose one option...\n1.Add Edge  2.Display the min weights\n";
        int wish;
        cin>>wish;
        switch(wish){
            case 1:{
                cout<<"Enter the vertices followed by wt\n";
                int v1,v2,wt;
                cin>>v1>>v2>>wt;
                if(edge==NULL)
                {edge=createEdge(v1,v2,wt);edge->next=createEdge(v2,v1,wt);}
                else
                addEdge(edge,v1,v2,wt);
            }break;
            case 2:{
                cout<<"Enter the vertex to find\n";
                int v;
                cin>>v;
                bellmanford(edge,v,n);
            }break;
            default:{
                t=0;
            }
        }
    }
    return 0;
}