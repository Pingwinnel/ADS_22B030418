#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//run id:2955
struct Graph {
    int V;
    vector<int> adj;
    Graph(int V){
        this->V = V;
        adj.resize(V+1);
    };
    void addEdge(int v, int w){
        adj[v]=w;

    };
    void BFS(int a,int search){
        stack<int> loli;
        loli.push(a);
        ll cnt=0;
        ll now=a;
        while (adj[now]!=search){
            loli.push(adj[now]);
            now=adj[now];
            cnt++;
        }
        cout<<cnt+1<<endl;
        for(int i=0;i<cnt+1;i++){
            cout<<loli.top()<<" ";
            loli.pop();
        }
    };
};
 
int main(){
    ll fir,sec;
    cin>>fir>>sec;
    ll counter=0;
    list<ll> loli;
    while(fir!=sec){
        loli.push_front(sec);
        if(sec%2==1){
            counter++;
            sec++;
            if(fir==sec){
                break;
            }
            loli.push_front(sec);
        }
        if(fir>sec){
            loli.pop_front();
            while(fir!=sec){
                loli.push_front(sec);
                counter++;
                sec++;
            }
            break;
        }
        sec/=2;
        counter++;
    }
    cout<<counter<<endl;
    for(int i=0;i<counter;i++){
        cout<<loli.front()<<" ";
        loli.pop_front();
    }
    return 0;
}