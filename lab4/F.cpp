#include <iostream>
#define ll long long int
using namespace std;
//run id:2246

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

    Node* search(Node *node,ll x){
        if(node==NULL || node->value==x ){
            return node;
        }else if(node->value<x){
            node=search(node->right,x);
        }else{
            node=search(node->left,x);
        }
        return node;
    }
    Node* findTraiangle(Node *node){
        if(node->left!=NULL){
            findTraiangle(node->left);
        }
        if(node->left!=NULL && node->right!=NULL){
            this->max++;
        }
        if(node->right!=NULL){
            findTraiangle(node->right);
        }
        return node;
    }
    Node* subtree(Node *node,ll i){
        arr[i]++;
        if(node->left!=NULL){
            subtree(node->left,i+1);
        }
        if(node->right!=NULL){
            subtree(node->right,i+1);
        }
        if(node->left==NULL && node->right==NULL && i>max){
            max=i;
        }
        return node;
    }

};


int main(){
    ll size,searchingVal;
    cin>>size;
    cin>>searchingVal;
    binary_tree bintree(searchingVal);
    for(ll i=0;i<size-1;i++){
        cin>>searchingVal;
        bintree.push(bintree.head,searchingVal);
    }
    bintree.findTraiangle(bintree.head);
    cout<<bintree.max;
}