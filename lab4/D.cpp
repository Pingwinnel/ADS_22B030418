#include <iostream>
using namespace std;
#define ll long long int

//run id :2210

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
        if(node->left!=NULL){
            subtree(node->left);
        }
        if(node->right!=NULL){
            subtree(node->right);
        }
    return node;
    }
    ll getHeight(Node* root)
{
    if (root->left == NULL && root->right == NULL)
        return 0;
 
    int left = 0;
    if (root->left != NULL)
        left = getHeight(root->left);
 
    int right = 0;
    if (root->right != NULL)
        right = getHeight(root->right);
 
    return (max(left, right) + 1);
}

void calculateLevelSum(Node* node, ll level, ll sum[])
{
    if (node == NULL)
        return;
 
    sum[level] += node->value;
 
    calculateLevelSum(node->left, level + 1, sum);
    calculateLevelSum(node->right, level + 1, sum);
}
};
int main(){
   ll n,m;
   cin>>n;
   cin>>m;
   binary_tree bintree(m);
   for(int i=1;i<n;i++){
    cin>>m;
    bintree.push(bintree.head,m);
   }
   ll lev=bintree.getHeight(bintree.head)+1;
   ll sum[lev]={0};
   bintree.calculateLevelSum(bintree.head,0,sum);
   cout<<lev<<endl;
   for(ll i=0;i<lev;i++){
    cout<<sum[i]<<" ";
   }
}