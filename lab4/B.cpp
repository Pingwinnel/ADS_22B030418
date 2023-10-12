    #include <iostream>
    using namespace std;
    #define ll long long int
    //run id:2108
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
        ll i=0;
        binary_tree(ll x){
            head=new Node(x);
        }
        Node* push(Node *node,ll x){
            if(node==nullptr){
                return new Node(x);
            }else if(node->value<x){
                node->right=push(node->right,x);
            }else{
                node->left=push(node->left,x);
            }
            return node;
        }

        Node* search(Node *head,ll x){
    if(head->value==x or head==nullptr){
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
        ll subtree(Node* node){
    if(node->left!=nullptr){
        i=subtree(node->left);
    }
    this->i++;
    if(node->right!=nullptr){
        i=subtree(node->right);
    }
    return i;
    }

    };
    int main(){
    ll size,n;
    cin>>size;
    binary_tree bintree(size);
    for(int i=0;i<size;i++){
        cin>>n;
        bintree.push(bintree.head,n);
    }
    cin>>n;
    Node* searched=bintree.search(bintree.head,n);
    bintree.subtree(searched);
    cout<<bintree.i;
    }