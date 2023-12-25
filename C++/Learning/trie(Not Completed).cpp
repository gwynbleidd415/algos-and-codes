#include <bits/stdc++.h>
using namespace std;

struct trie{
    char letter;
    trie *alt;
    trie *next;
    bool eol;
};

trie *createNode(char letter){
    trie *temp=new trie;
    temp->letter=letter;
    temp->alt=NULL;
    temp->next=NULL;
    temp->eol=false;
    return temp;
}

void insert(trie *root, string word){
    int n=word.length();
    int i=0;
    trie *temp=root;
    while(i<n){
        while(word[i]!=temp->letter&&temp->alt!=NULL)
        temp=temp->alt;
        if(temp->letter!=word[i]){
            temp->alt=createNode(word[i]);
            temp=temp->alt;++i;
            while(i<n){
                temp->next=createNode(word[i]);
                temp=temp->next;++i;
            }
            temp->eol=true;
            return;
        }
        else{
            ++i;
            if(temp->next!=NULL)
            temp=temp->next;
            else{
                while(i<n){
                    temp->next=createNode(word[i]);
                    temp=temp->next;
                }
                temp->eol=true;
                return;
            }
        }
    }
    temp->eol=true;
}

int main(){
    short int t=1;
    trie *root=NULL;
    while(t){
        cout<<"Choose one option...\n1.Insert word  2.Check for Word  3.Delete Word  4.Exit\n";
        short int wish;
        cin>>wish;
        switch(wish){
            case 1:{
                cout<<"Enter the word to add to the trie"<<endl;
                string word;
                cin>>word;
                if(root==NULL)
                root=createNode(word[0]);
                insert(root,word);
            }
            break;
            case 2:{
                //
            }
            break;
            case 3:{
                //
            }
            break;
            default:{
                t=0;
            }
        }
    }
    return 0;
}