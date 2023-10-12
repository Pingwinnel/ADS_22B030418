#include <iostream>
using namespace std;
#define ll long long int

//run id :2241

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
Node* arr[1000];
ll arra[999];
struct binary_tree{
    Node *head=NULL;
    ll maxi=0;
   Node* push(Node* arr[],ll x){
        Node *node=arr[x];
        if(x==1){
            head=node;
        }
        if(node->left!=NULL){
            node->left=push(arr,node->left->value);
        }
        if(node->right!=NULL){
            node->right=push(arr,node->right->value);
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
    ll subtree(Node* node,ll i){
        arra[i]++;
        if(node->left!=NULL){
            subtree(node->left,i+1);
        }
        if(node->right!=NULL){
            subtree(node->right,i+1);
        }
        if(arra[i]>maxi){
            maxi=arra[i];
        }
    return maxi;
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
int getWidth(Node* root, int level)
{
    if (root == NULL)
        return 0;
    if (level == 1)
        return 1;
    else if (level > 1)
        return getWidth(root->left, level - 1)
               + getWidth(root->right, level - 1);
}

int getMaxWidth(Node* root)
{
    int maxWidth = 0;
    int width;
    int h = getHeight(root);
    int i;
 
    for (i = 1; i <= h; i++) {
        width = getWidth(root, i);
        if (width > maxWidth)
            maxWidth = width;
    }
 
    return maxWidth;
}
};
int main(){
   ll size,x,y,z;
    cin>>size;
    binary_tree bintree;
    arr[1]=new Node(1);
    for(ll i=0;i<size-1;i++){
        cin>>x>>y>>z;
        if(z==0){
            arr[y]=new Node(y);
            arr[x]->left=arr[y];
        }else{
            arr[y]=new Node(y);
            arr[x]->right=arr[y];
        }
    }
    bintree.push(arr,1);
    cout<<bintree.subtree(bintree.head,1);
}