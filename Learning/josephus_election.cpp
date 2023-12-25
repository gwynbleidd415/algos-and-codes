#include <bits/stdc++.h>
using namespace std;

struct llist{
    int data;
    llist *next;
};

void insert(llist **node,int data){
    llist *temp=new llist;
    temp->data=data;
    temp->next=NULL;
    if(*node==NULL){
        *node=temp;
        (*node)->next=*node;
    }
    else{
        temp->next=(*node)->next;
        (*node)->next=temp;
        *node=temp;
    }
}

void delet(llist *node){
    if(node==NULL)
    cout<<"ERROR!!!\n";
    else{
        if(node==node->next)
        node=NULL;
        else{
            llist *temp=node->next;
            node->next=node->next->next;
            delete temp;
        }
    }
}

int main(){
    cout<<"Enter the number of people and the eliminating sequence\n";
    int num,n,i;
    cin>>num>>n;
    llist *node=NULL;
    for(i=1;i<=num;++i)
    insert(&node,i);i=0;
    while(node->next!=node){
        cout<<"After "<<i<<" round\n";
        int j=0;llist *temp=node->next;
        for(;j<num-i;++j){
            cout<<temp->data<<' ';
            temp=temp->next;
        }
        cout<<endl;
        j=n;
        while(--j)
        node=node->next;
        delet(node);
        ++i;
    }
    cout<<"WINNER is "<<node->data<<"\n";
    return 0;
}