#include <iostream>
#define ll long long int
using namespace std;
//run id:2262

ll arr[500];

struct Node{
    ll value;
    Node *left=NULL;
    Node *right=NULL;
    Node *parent=NULL;
    Node(){
        this->value=0;
    }
    Node(ll value){
        this->value=value;
    }
};
struct binary_tree{
    Node *head=NULL;
    ll max=0;
    binary_tree(ll x){
        head=new Node(x);
    }
    Node* push(Node *node,ll x){
        if(node==NULL){
            return new Node(x);
        }else if(node->value<x){
            node->right=push(node->right,x);
            node->right->parent=node;
        }else{
            node->left=push(node->left,x);
            node->left->parent=node;
        }
        return node;
    }
    Node* find(Node *node){
        if(node->right!=NULL){
            find(node->right);
        }
        this->max+=node->value;
        node->value=max;
        cout<<node->value<<" ";
        if(node->left!=NULL){
            find(node->left);
        }
        return node;
    }
};


int main(){
    ll size,searchedVal;
    cin>>size;
    cin>>searchedVal;
    binary_tree bintree(searchedVal);
    for(ll i=0;i<size-1;i++){
        cin>>searchedVal;
        bintree.push(bintree.head,searchedVal);
    }
    bintree.find(bintree.head);
}
