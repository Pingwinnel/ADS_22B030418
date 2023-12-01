#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//run id:3092
ll inf=(int) 1e9+7;

struct Graph {
    ll VERTI;
    vector<list<ll>> adj;
    bool posible=false;
    vector<int> visited;
    stack<ll> topStack;

    Graph(ll V){
        this->VERTI = V;
        adj.resize(V+1);
        visited.resize(V+1,0);
    }
    void addEdge(ll v,ll w){
        adj[v].push_back(w);
    }
    void BFS(ll i){
        visited[i]=2;
        if(adj[i].empty()){
            topStack.push(i);
            visited[i]=1;
            return;
        }
        for(ll j :adj[i]){
            if(visited[j]==2){
                posible=true;
                return;
            }else if(visited[j]==1){
                continue;
            }
            BFS(j);
        }
        topStack.push(i);
        visited[i]=1;
    }
};

int main(){
    ll VERTEX,E,fir,sec;
    cin>>VERTEX>>E;
    Graph graph(VERTEX);
    for(ll i=0;i<E;i++){
        cin>>fir>>sec;
        graph.addEdge(fir,sec);
    }
    for(ll i=VERTEX;i>=1;i--){
        if(graph.visited[i]==1) continue;
        graph.BFS(i);
        if(graph.posible){
            cout<<"Impossible";
            return 0;
        }
    }
    cout<<"Possible"<<endl;
    for(ll i=0;i<VERTEX;i++){
        cout<<graph.topStack.top()<<" ";
        graph.topStack.pop();
    }
    return 0;
}