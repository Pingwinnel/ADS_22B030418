#include <iostream>
#include <algorithm>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int num): val(num), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int num, Node* next): val(num), next(next) {}
};
 
Node* insert(Node* head, Node* node, int a){
    Node* cur = head;
    if (a == 0) {
        node->next = head;
        head = node;
    }
    else {
        for(int i = 0; i < a - 1; i++) {
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
    }
    return head;
}
 
Node* remove(Node* head, int a){
    Node* cur = head;
    if (a == 0) {
        head = head->next;
    }
    else {
        for(int i = 0; i < a - 1; i++) {
            cur = cur->next;
        }
        Node* tmp = cur->next->next;
        delete cur->next;
        cur->next = tmp;
    }
    return head;
}
 
Node* replace(Node* head, int p1, int p2){
    Node *cur1 = head, *cur2 = head;
    Node *prev1 = NULL, *prev2 = NULL;
    int cnt = 0;
    if (p1 == 0 and p2 == 0) {
        return head;
    }
    while(cnt < p1) {
        prev1 = cur1;
        cur1 = cur1->next;
        cnt++;
    }
    if (p1 == 0) {
        head = head->next;
        cur2 = head;
    }
    if (p1 != 0) {
        prev1->next = cur1->next;
    }
    cnt = 0;
    while(cnt < p2) {
        prev2 = cur2;
        cur2 = cur2->next;
        cnt++;
    }
    if (p2 != 0) {
        prev2->next = cur1;
        cur1->next = cur2;
    }
    else {
        cur1->next = cur2;
    }
    if (p2 == 0) {
        head = cur1;
        return head;
    }
    return head;
}
 
Node* reverse(Node* head){
    Node *prev = NULL, *next = NULL;
    Node *cur = head;
    while(cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return head;
}
 
void print(Node* head){
    Node* cur = head;
    if (cur == NULL) {
        cout << -1 << "\n";
        return;
    }
    while(cur != NULL) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << "\n";
}
 
Node* cyclic_left(Node* head, int num){
    Node *cur = head;
    while(cur->next != NULL) {
        cur = cur->next;
    }
    while(num--) {
        cur->next = head;
        head = head->next;
        cur = cur->next;
        cur->next = NULL;
    }
    return head;
}
 
Node* cyclic_right(Node* head, int num){
    Node *cur = head;
    int cnt = 1;
    while(cur->next != NULL) {
        cur = cur->next;
        cnt++;
    }
    cur->next = head;
    num = cnt - num;
    while(num--) {
        cur = cur->next;
    }
    head = cur->next;
    cur->next = NULL;
    return head;
}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int num, a; cin >> num >> a;
            head = insert(head, new Node(num), a);
        }else if (command == 2){
            int a; cin >> a;
            head = remove(head, a);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int num; cin >> num;
            head = cyclic_left(head, num);
        }else if (command == 7){
            int num; cin >> num;
            head = cyclic_right(head, num);
        }   
    }
    return 0;
}