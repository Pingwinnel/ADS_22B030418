#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll inf=(int) 1e9+7;
//run id:2807

struct Graph {
    ll VERTI=0;
    vector<list<ll>> adj;
    Graph(ll V){
        this->VERTI = V;
        adj.resize(V+1);
    }
    void addEdge(ll v,ll w){
        adj[v].push_back(w);

    }
    void BFS(ll s,ll d){
        vector<bool> visited;
        visited.resize(VERTI+1,false);
        list<ll> queue;
        ll arr[VERTI+1];
        for(ll i=1;i<=VERTI;i++){
            arr[i]=inf;
        }
        arr[s]=0;
        visited[s] = true;
        queue.push_back(s);
        while (!queue.empty()){
            for(ll i:adj[queue.front()]){
                if(!visited[i]){
                    queue.push_back(i);
                    visited[i]=true;
                    if(arr[queue.front()]+1<arr[i]) arr[i]=arr[queue.front()]+1;
                }
            }
            queue.pop_front();
        }
        if(visited[d]==true){
            cout<<arr[d];
        }else cout<<-1;
    }
};

int main(){
    ll size,value;
    cin>>size;
    Graph graph(size);
    for(ll i=1;i<=size;i++){
        for(ll j=1;j<=size;j++){
            cin>>value;
            if(value==1)  graph.addEdge(i,j);
        }
    }
    ll vertice1,vertice2;
    cin>>vertice1>>vertice2;
    graph.BFS(vertice1,vertice2);

    return 0;
}