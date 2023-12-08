#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ss short int
//run id:1401
ll V,E;
ll infi=(int) 1e9;

struct Graph {
    int V;
    vector<ll> adj;
    vector<ll> ind;
    Graph(int V){
        this->V = V;
        ind.resize(V+1);

    };
    void addEdge(int weight){
        adj.push_back(weight);
    };
    ll parent(ll i){
        if(ind[i]==i) return i;
        return parent(ind[i]);
    };
    void unite(ll x,ll y){
        ind[x]=y;
    };

    void Kruscal(){
        sort(adj.begin(),adj.end());
        ll w=0;
        for(ll i=1;i<adj.size();i++){
            w+=adj[0]+adj[i];
        }
        cout<<w;
    };
};
 

int main(){
    ll weight;
    cin>>V;
    Graph graph(V);
    for(ll i=0;i<V;i++){
        cin>>weight;
        graph.addEdge(weight);
    }
    graph.Kruscal();
    
    return 0;
}