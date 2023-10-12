#include <iostream>
using namespace std;
#define ll long long int
//run id:2180
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
    string subtreeAns;
    binary_tree(ll x){
        head=new Node(x);
    }
    Node* push(Node *node,ll x){
        if(node==NULL){
            return new Node(x);
        }else if(node->value<x){
            node->right=push(node->right,x);
        }else{
            node->left=push(node->left,x);
        }
        return node;
    }
     Node* search(Node *head,ll x){
    if(head->value==x or head==NULL){
        return head;
    }
    else if(head->value<x){
       head= search(head->right,x);
    }
    else {
        head=search(head->left,x);
    }
    return head;
    }
    Node* subtree(Node* node){
        cout<<node->value<<" ";
        if(node->left!=NULL){
            subtree(node->left);
        }
        if(node->right!=NULL){
            subtree(node->right);
        }
    return node;
    }
};

//run id :
int main(){
   ll n,m;
   cin>>n;
   cin>>m;
   binary_tree bintree(m);
   for(int i=1;i<n;i++){
    cin>>m;
    bintree.push(bintree.head,m);
   }
   cin>>m;
   Node* searched=bintree.search(bintree.head,m);
   bintree.subtree(searched);
}