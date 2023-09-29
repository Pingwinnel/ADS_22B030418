#include <string>
#include <iostream>
using namespace std;
//run id:5273
class Node
{
public:
    string key;    
    Node* next;
public:
    Node(string key){
        this->key = key;
        this->next = nullptr;
    }
};
class LinkedList{
public:
    Node* head;
    Node* tail;
public:
    LinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
    }
    ~LinkedList(){
        while(head != nullptr) pop_front();
    }
    void pop_front(){
        if(head == nullptr){
            return;
        }
        if(head==tail){
            delete tail;
            head = tail = nullptr;
            return;
        }
        Node* node = head;
        head = node->next;
        delete node;
    }

    void push_back(string val){
        Node* node = new Node(val);
        if(head==nullptr){
            head = node;
        }
        if(tail!=nullptr){
            tail->next = node; 
        }
        tail = node;
    }
    void print(){
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->key << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    int num, index;
    cin >> num >> index;
    cin.ignore();
    LinkedList linklist;
    string str;
    getline(cin, str);
    string buf = "";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            linklist.push_back(buf);
            buf = "";
        } else {
            buf += str[i];
        }
    }
    if (!buf.empty()) {
        linklist.push_back(buf);
    }
    for (int i = 0; i < index; i++) {
        linklist.push_back(linklist.head->key);
        linklist.pop_front();
    }
    linklist.print();
    return 0;
}