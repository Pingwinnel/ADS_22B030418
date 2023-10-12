#include <iostream>
#define ll long long int
using namespace std;
//run id:2257
struct Node{
    ll value;
    Node *left=NULL;
    Node *right=NULL;
    ll leftmax=0;
    ll rightmax=0;

    Node(){
        this->value=0;
    }
    Node(ll value){
        this->value=value;
    }
};
struct binary_tree{
    Node *head=NULL;
    ll total=0;
    binary_tree(ll x){
        head=new Node(x);
    }
    Node* push(Node *node,ll x){
        if(node==NULL){
            return new Node(x);
        }else if(node->value==x){
            return node;
        }else if(node->value<x){
            node->right=push(node->right,x);
        }else{
            node->left=push(node->left,x);
        }
        return node;
    }
    ll maxlenth(Node*node){
        if(node->left!=NULL){
            node->leftmax=maxlenth(node->left);
        }
        if(node->right!=NULL){
            node->rightmax=maxlenth(node->right);
        }
        total=max(node->leftmax+node->rightmax,total);
        return max(node->leftmax,node->rightmax)+1;
    }
};

int main(){
    ll size,x;
    cin>>size;
    cin>>x;
    binary_tree bintree(x);
    for(ll i=0;i<size-1;i++){
        cin>>x;
        bintree.push(bintree.head,x);
    }
    bintree.maxlenth(bintree.head);
    cout<<bintree.total+1;
}