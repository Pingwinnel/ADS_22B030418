#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ss short int
//run id:
ll V,E;
ll infi=(int) 1e9;

struct Graph {
    int V;
    vector<vector<ll>> adj;
    Graph(int V){
        this->V = V;
        adj.resize(V + 1, vector<ll>(V + 1, 0));
    };
    void addEdge(int v, int w,int weight){
        adj[v][w]=weight;
        adj[w][v]=weight;


    };
    int minKey(int key[], bool mstSet[]){
        int min = infi, min_index;
    
        for (int v = 0; v < V; v++)
            if (mstSet[v] == false && key[v] < min)
                min = key[v], min_index = v;
    
        return min_index;
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
                if (adj[u][v] && mstSet[v] == false && adj[u][v] < key[v])
                    parent[v] = u, key[v] = adj[u][v];
        }
        coutMST(parent);
    };
};
 

int main(){
    ll v1,v2,weight,big,small,smallest;
    string type;
    cin>>V>>E;
    Graph graph(V);
    cin>>big>>small;
    if(big>small){
        smallest=small;
    }else{
        smallest=big;
    }
    for(ll i=0;i<E;i++){
        cin>>type;
        cin>>v1>>v2>>weight;
        if(type=="big") weight*=big;
        else if(type=="small") weight*=small;
        else weight*=smallest;
        graph.addEdge(v1-1,v2-1,weight);
    }
    graph.primMST();
    
    return 0;
}