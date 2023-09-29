#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class LinkedList
{
public:
    LinkedList(/* args */);
    ~LinkedList();
        
    void push_back(T data);
    void push_front(T data);
    int getSize() {return Size;};
    T& operator[](const int index);
    void pop_front();
    void pop_back();
    void insert(T data,int index);
    void removeAt(int index);
    void clear();
    void rotate(int steps);
    void printlist();
    void rotateprintlist();
    void pushbackDatabase(int n);
    void push_backList(int n);
    void printFront();
    void printBack();

private:
    template<typename T1>
    class Node
    {
        public:
            Node *pNext;
            T data;
            Node(T data=T1(), Node *pNext=nullptr)
            {
                this->data=data;
                this->pNext=pNext;
            };
    };

    int Size;
    Node<T> *head,*tail;
        

};
        
    
    
template<typename T> 
LinkedList<T>::LinkedList()
{
    Size=0;
    head=nullptr;
    tail=head;
}

template<typename T> 
LinkedList<T>::~LinkedList()
{
clear();
}

template<typename T>
void LinkedList<T>::clear()
{
while (Size)
{
    pop_front();
}

}

template<typename T> 
void LinkedList<T>::push_backList(int n)
{
    Node<T> *tail;
for (int i = 1; i <= n; ++i) {
    T x;
    cin >> x;
    Node<T> *cur = new Node<T>();
    cur -> data = x;
 
    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> pNext = cur;
      tail = cur;
    }    


}
}

template<typename T> 
void LinkedList<T>::push_back(T data)
{
    if(head==nullptr)
    {
        head=new Node<T>(data);
        tail=head;
    }
    else
    {
        Node<T> *curr=this->head;
        while(curr->pNext!=nullptr)
        {
            curr=curr->pNext;
        }
        curr->pNext=new Node<T>(data);
        tail=curr->pNext;
    }
    Size++;
}

template<typename T>
void LinkedList<T> ::push_front(T data)
{
head=new Node<T>(data,head);
tail=tail->pNext;
Size++;
}

template<typename T> 
T& LinkedList<T>::operator[](const int index)
{
int counter=0;
Node<T> *curr=this->head;
while(curr!=nullptr)
{
    if(counter==index) return curr->data;
    curr=curr->pNext;
    counter++;
}
}
template<typename T>
void LinkedList<T> ::pop_front()
{
Node<T> *temp=head;
head=head->pNext;
cout<<temp->data<<endl;
delete temp;
Size--;
}


template<typename T>
void LinkedList<T>::insert(T data,int index)
{
    if(index==0) push_front(data);
    else
    {
        Node<T> *prev=this->head;
        for(int i=0;i<index-1;i++){
            prev=prev->pNext;
        }
        prev->pNext=new Node<T>(data,prev->pNext);
        
    }
    Size++;
}

template<typename T>
void LinkedList<T>::removeAt(int index)
{
    if(index==0) pop_front();
    else
    {
        Node<T> *prev=this->head;
        for(int i=0;i<index-1;i++){
            prev=prev->pNext;
        }
        Node<T> *toDElete=prev->pNext;
        prev->pNext=toDElete->pNext;
        delete toDElete;
    }
    Size--;
}

template<typename T>
void LinkedList<T> ::pop_back()
{
    cout<<tail->data<<endl;
    removeAt(Size-1);
    Size--;
}

template<typename T>
void LinkedList<T> ::rotate(int steps)
{
    Node<T> *p=head;
    Node<T> *q=head;
    Node<T> *prev=nullptr;
    int count=0;
    while(p and count<steps)
    {
        prev=p;
        p=p->pNext;
        q=q->pNext;
        count++;
    }
    p=prev;
    while(q)
    {
        prev=q;
        q=q->pNext;
    }
    q=prev;
    q->pNext=head;
    head=p->pNext;
    p->pNext=nullptr;
}

template<typename T>
void LinkedList<T>::printlist()
{
    Node<T> *curr=head;
while(curr!=nullptr)
        {
            cout<<curr->data<<" ";
            curr=curr->pNext;
        }
        
}

template<typename T>
void LinkedList<T>::pushbackDatabase(int n)
{
    string prev="";
    for (int i = 1; i <= n; ++i) {
        T x;
        cin >> x;
        if(x!=prev){
        push_front(x);
        prev=x;
    }
}
}

template<typename T>
void LinkedList<T>::printFront(){
cout<<head->data<<endl;
}

template<typename T>
void LinkedList<T>::printBack(){
    Node<T> *curr=head;
while(curr!=nullptr){
curr=curr->pNext;
}
cout<<curr->data<<endl;
}



int main(){
    LinkedList<string> nums;
    string n;
    cin>>n;
    while(true){
        if(n=="add_front"){
            string a;
            cin>>a;
            nums.push_front(a);
            cout<<"ok"<<endl;
        }
        else if(n=="add_back"){
            string a;
            cin>>a;
            nums.push_back(a);
            cout<<"ok"<<endl;
        }
        else if(n=="erase_front"){
            nums.pop_front();
        }
        else if(n=="erase_back"){
            nums.pop_back();
        }
        else if(n=="clear"){
            nums.clear();
        }
        else if(n=="front"){
            nums.printFront();
        }
        else if(n=="back"){
            nums.printBack();
        }
        else if(n=="exit"){
            break;
        }
    }
    return 0;
}