#include <bits/stdc++.h>
using namespace std;
//run id:5140
struct node{
    char d;
    node*next;
    node(){}
    node(int num) {
        this->d = num;
        this->next = NULL;
        }
};
int main() {
    int num;
    cin>>num;
    while(num--){
        node*head=NULL;
        node*c = head;
        map<char,int> maps;
        int num;
        cin>>num;
        for(int i =0; i<num; i++){
            char a;
            cin>>a;
            if(i==0 || head == NULL){
                head = new node(a);
                c = head;
                maps[a]++;
            }
            else{
                c->next = new node(a);
                c = c->next;
                maps[a]++;
            }
            while((head->d == c->d || maps[head->d]>1) && head !=c){
                node*oog = head;
                maps[head->d]++;
                head = head->next;
                delete oog;
            }
            if(head == c && i!=0 &&maps[c->d]> 1){
                cout<<-1<<" ";
                head = head->next;
            }
            else{
                cout<<head->d<<" ";
            }
        }
        cout<<"\num";
    }
}
