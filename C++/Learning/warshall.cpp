#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

class graph{
    int n;
    vector<vector<unsigned int>> vert;
public:
    graph(int n){
        this->n=n;
        vector<unsigned int> temp;
        for(int i=0;i<n;++i)
        temp.push_back(INT_MAX);
        for(int i=0;i<n;++i){
            vert.push_back(temp);
            vert[i][i]=0;
        }
    }
    void addEdge(int v1,int v2,int wt){
        vert[v1][v2]=wt;
        vert[v2][v1]=wt;
    }
    void display(){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(vert[i][j]<100000)
                cout<<setw(6)<<vert[i][j]<<"\t";
                else
                cout<<setw(6)<<"INF"<<"\t";
            }
            cout<<"\n";
        }
    }
    void warshall(){
        //vector<vector<unsigned int>> war(n,vector<unsigned int>(n,INT_MAX));
        //for(int i=0;i<n;++i)
        //war[i][i]=0;
        vector<vector<unsigned int>> war=vert;
        for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
        for(int k=0;k<n;++k)
        if(war[j][k]>war[j][i]+war[i][k])
        war[j][k]=war[j][i]+war[i][k];
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(war[i][j]<100000)
                cout<<setw(6)<<war[i][j]<<"\t";
                else
                cout<<setw(6)<<"INF"<<"\t";
            }
            cout<<"\n";
        }
    }
};

int main(){
    cout<<"Enter the number of vertices\n";
    int n;
    cin>>n;
    graph g(n);
    int t=1;
    while(t){
        cout<<"Choose one option...\n1.AddEdge  2.Display  3.Warshall  4.Exit\n";
        int wish;
        cin>>wish;
        switch(wish){
            case 1:{
                cout<<"Enter the vertices followed by wt\n";
                int v1,v2,wt;
                cin>>v1>>v2>>wt;
                g.addEdge(v1,v2,wt);
            }break;
            case 2:{
                g.display();
            }break;
            case 3:{
                g.warshall();
            }break;
            default:{
                t=0;
            }
        }
    }
    return 0;
}