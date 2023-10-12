#include <iostream>
#define ll long long int
using namespace std;

//run id:2284
ll arr[500];

struct Node{
    ll value;
    ll count;
    Node *left=NULL;
    Node *right=NULL;
    Node *parent=NULL;
    Node(){
        this->value=0;
        count=0;
    }
    Node(ll value){
        this->value=value;
        count=1;
    }
};
struct binary_tree{
    Node *head=NULL;
    Node* push(Node *node,ll x){
        if(head==NULL){
            head=new Node(x);
            return node;
        }
        if(node==NULL){
            return new Node(x);
        }else if(node->value==x){
            node->count+=1;
            return node;
        }else if(node->value<x){
            node->right=push(node->right,x);
            node->right->parent=node;
        }else{
            node->left=push(node->left,x);
            node->left->parent=node;
        }
        return node;
    }
    Node* deleteAct(Node *node,ll x){
        if(node==NULL){
            return node;
        }else if(node->value==x){
            node->count--;
        }else if(node->value<x){
            node=deleteAct(node->right,x);
        }else{
            node=deleteAct(node->left,x);
        }
        return node;
    }Node* searchOut(Node *node,ll x){
        if(node==NULL){
            cout<<0<<endl;
        }else if(node->value==x){
            cout<<node->count<<endl;
        }else if(node->value<x){
            node=searchOut(node->right,x);
        }else{
            node=searchOut(node->left,x);
        }
        return node;
    }
};


int main(){
    ll size,x;
    string act;
    cin>>size;
    binary_tree bintree;
    for(ll i=0;i<size;i++){
        cin>>act;
        if(act=="insert"){
            cin>>x;
            bintree.push(bintree.head,x);
        }else if(act=="cnt"){
            cin>>x;
            bintree.searchOut(bintree.head,x);
        }else{
            cin>>x;
            bintree.deleteAct(bintree.head,x);
        }
    }
}
