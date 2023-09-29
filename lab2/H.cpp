#include <iostream>
#include <math.h>
using namespace std;

template<typename T>
class LinkedList
{
public:
    LinkedList(/* args */);
    ~LinkedList();
        
    void push_back(int n);
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
    void rotateRange(int steps,int index);
    void shift_left(int steps);
    void shift_right(int steps);
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
    Node<T> *head;
        

};
        
    
    
template<typename T> 
LinkedList<T>::LinkedList()
{
    Size=0;
    head=nullptr;
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
void LinkedList<T>::push_back(int n)
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
void LinkedList<T> ::push_front(T data)
{
head=new Node<T>(data,head);
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
       removeAt(Size-1);
    Size--;
}

template<typename T>
void LinkedList<T> ::rotate(int steps)
{
    steps=steps%Size;
    Node<T> *p=head;
    Node<T> *q=head;
    Node<T> *prev=nullptr;
    int count=0;
    while(count<steps)
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
void LinkedList<T> ::rotateRange(int a,int b)
{
    Node<T> *curr=head,*temp1,*temp2;
    int count=0;
    T data2,data3;
     while (curr!= NULL)
     {
       if(a == count)
        {
            data2=curr->data;
            temp1=curr;
            count++;
        }
        else if(count==b){
           data3=curr->data;
           temp2=curr;
           count++;
        }
      curr = curr->pNext;
    }
    temp1->data=data3;
    temp2->data=data2;

}


template<typename T>
void LinkedList<T> ::shift_left(int steps){
    Node<T> *curr=head,*tail;
    tail=this[abs((steps%Size)-Size)];
    int data1;
    while(steps%Size){
        tail->data=data1;
        tail->data=head->data;
        tail=tail->pNext;
        head->data=data1;
        head=head->pNext;

    }
}




int main(){
    LinkedList<int> nums;
    int n;
    while(true)
    {
    cin>>n;
    if(n==0){
        break;
    }
    else if(n==1){
        int a,index;
        cin>>a>>index;
        nums.insert(a,index);
    }
    else if(n==2){
        int index;
        cin>>index;
        nums.removeAt(index);
    }
    else if(n==3){
        nums.printlist();
        cout<<endl;
    }
    else if(n==4){
        int a,b;
        cin>>a;
        cin>>b;
        nums.rotateRange(a,b);
    }
    else if(n==5){
        nums.printlist();
    }
    else if(n==6){
    int a;
    cin>>a;
    nums.shift_left(a);
    }
    }


    return 0;
}