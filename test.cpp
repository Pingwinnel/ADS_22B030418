# include <iostream>
# include <algorithm>
# include <cassert>
 
using namespace std;
 
struct Node {
  int val;
  Node *next;
 
  Node() {
    val = 0;
    next = NULL;
  }
 
};
 
 
 
int findMaxSum(int n, Node *head) {
	// Implement this function
 
}

void insert(int index,int x,int n,Node *head){
Node *curr=head;
int i=0;
Node *prev=head;
for(int i=0;i<n;i++){
    if(index==0) head=new Node (x,*head);
}

}
 
int main() {
  int n;
  cin >> n;
 
  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;
 
    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }


 
  cout << findMaxSum(n, head) << "\n";
  return 0;
}