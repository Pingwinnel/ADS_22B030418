#include <iostream>
#include <vector>
using namespace std;
//run id :3034
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
    int i=1;
    Node<T> *curr=head;
while(curr!=nullptr)
        {
            if(i%2!=0){
            cout<<curr->data<<" ";
            curr=curr->pNext;
            }
            else curr=curr->pNext;
            i++;
        }
        
}



int main(){
    LinkedList<string> nums;
    int n;
    cin>>n;

    nums.push_back(n);
   nums.printlist();

    return 0;
}