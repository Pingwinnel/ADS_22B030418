#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ss short int
//RUN ID:1413
ll V,E;
ll infi=(int) 1e9;

struct Graph {
    int V;
    vector<vector<ll>> adj;
    Graph(int V){
        this->V = V;
        adj.resize(V + 1, vector<ll>(V + 1, -1));
    };
    void addEdge(int v, int w,int weight){
        adj[v][w]=weight;
    };
    int minKey(int key[], bool mstSet[]){
        int min = infi, min_ind;
    
        for (int v = 0; v < V; v++)
            if (mstSet[v] == false && key[v] < min)
                min = key[v], min_ind = v;
    
        return min_ind;
    };
    void coutMST(int parent[]){
        ll weight=0;
        for (int i = 1; i < V; i++)
            weight+=adj[i][parent[i]];
        cout<<weight;
    };
    void primMST(){
        int parent[V];
        int key[V];
        bool mstSet[V];
        for (int i = 0; i < V; i++)
            key[i] = infi, mstSet[i] = false;
    
        key[0] = 0;
        parent[0] = -1;
        for (int count = 0; count < V - 1; count++) {
            int u = minKey(key, mstSet);
            mstSet[u] = true;
            for (int v = 0; v < V; v++)
                if (adj[u][v]!=-1 && mstSet[v] == false && adj[u][v] < key[v])
                    parent[v] = u, key[v] = adj[u][v];
        }
        coutMST(parent);
    };
};
 

int main(){
    ll v1,v2,weight;
    cin>>V;
    Graph graph(V);
    for(ll i=0;i<V;i++){
        for(ll j=0;j<V;j++){
            cin>>weight;
            graph.addEdge(i,j,weight);
        }
    }
    graph.primMST();
    
    return 0;
}