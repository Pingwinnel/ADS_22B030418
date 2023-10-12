#include <iostream>
#define ll long long int
using namespace std;
//run id:2099

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
};


int main(){
    ll size,ways,x;
    string road;
    cin>>size>>ways;
    cin>>x;
    binary_tree bintree(x);
    for(ll i=0;i<size-1;i++){
        cin>>x;
        bintree.push(bintree.head,x);
    }
    for(int j=0;j<ways;j++){
        cin>>road;
        Node *current=bintree.head;
        for(char i:road){
            if(i=='L'){
                current=current->left;
            }else if(i=='R'){
                current=current->right;
            }
            if(current==NULL){
                break;
            }
        }
        if(current!=NULL){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }

}