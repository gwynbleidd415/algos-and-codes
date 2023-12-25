#include <bits/stdc++.h>
using namespace std;

struct tree{
    int data,height;
    tree *left,*right;
};

int getHeight(tree *root){
    if(root->left==NULL&&root->right==NULL)
    return 0;
    if(root->left==NULL){
        return root->right->height+1;
    }
    if(root->right==NULL){
        return root->left->height+1;
    }
    return max(root->left->height,root->right->height)+1;
}

int getBalance(tree *root){
    if(root->left==NULL&&root->right==NULL)
    return 0;
    if(root->left==NULL)
    return -(root->right->height+1);
    if(root->right==NULL)
    return root->left->height+1;
    return root->left->height-root->right->height;
}

tree *rotateRight(tree *root){
    tree *temp=root;
    root=root->left;
    temp->left=root->right;
    root->right=temp;
    temp->height=getHeight(temp);
    root->height=getHeight(root);
    return root;
}

tree *rotateLeft(tree *root){
    tree *temp=root;
    root=root->right;
    temp->right=root->left;
    root->left=temp;
    temp->height=getHeight(temp);
    root->height=getHeight(root);
    return root;
}

tree *createNode(int data){
    tree *temp=new tree;
    temp->data=data;
    temp->height=0;
    temp->left=temp->right=NULL;
    return temp;
}

tree *insert(tree *root, int data){
    if(root==NULL){
        root=createNode(data);
        return root;
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }
    else
    return root;
    root->height=getHeight(root);
    int bal=getBalance(root);
    if(bal>1){
        if(root->left->data>data)
        root=rotateRight(root);
        else{
            root->left=rotateLeft(root->left);
            root=rotateRight(root);
        }
    }
    if(bal<-1){
        if(root->right->data<data)
        root=rotateLeft(root);
        else{
            root->right=rotateRight(root->right);
            root=rotateLeft(root);
        }
    }
    return root;
}

tree *deletion(tree *root,int data){
    if(root==NULL)
    return root;
    if(root->data>data)
    root->left=deletion(root->left,data);
    else if(root->data<data)
    root->right=deletion(root->right,data);
    else{
        if(root->left==NULL)
        {tree *temp=root;root=root->right;free(temp);return root;}
        else if(root->right==NULL)
        {tree *temp=root;root=root->left;free(temp);return root;}
        else{
            tree *temp=root->right;
            while(temp->left!=NULL)
            temp=temp->left;
            root->data=temp->data;
            root->right=deletion(root->right,temp->data);
        }
    }
    root->height=getHeight(root);
    int bal=getBalance(root);
    if(bal>1){
        if(getBalance(root->left)>=0)
        root=rotateRight(root);
        else{
            root->left=rotateLeft(root->left);
            root=rotateRight(root);
        }
    }
    if(bal<-1){
        if(getBalance(root->right)<=0)
        root=rotateLeft(root);
        else{
            root->right=rotateRight(root->right);
            root=rotateLeft(root);
        }
    }
    return root;
}

void inDis(tree *root){
    if(root==NULL)
    return;
    inDis(root->left);
    cout<<root->data<<" ";
    inDis(root->right);
}

void preDis(tree *root){
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preDis(root->left);
    preDis(root->right);
}

int main(){
    int t=1;
    tree *root=NULL;
    while(t){
        cout<<"Choose one option...\n1.Insert  2.Delete  3.Display  4.Exit"<<endl;
        int wish;
        cin>>wish;
        switch(wish){
            case 1:{
                cout<<"Enter Data to be inserted"<<endl;
                int data;
                cin>>data;
                root=insert(root,data);
            }
            break;
            case 2:{
                cout<<"Enter Data to be deleted"<<endl;
                int data;
                cin>>data;
                root=deletion(root,data);
            }
            break;
            case 3:{
                cout<<"InOrder display is...\n";
                inDis(root);
                cout<<"\nPreOrder display is...\n";
                preDis(root);
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