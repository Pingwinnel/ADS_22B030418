#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//run id:3094
ll inf=(int) 1e9+7;

struct Graph {
    ll VERTI;
    vector<list<ll>> adj;
    vector<bool> visited;
    ll Fam=0;

    Graph(ll VERTEX){
        this->VERTI = VERTEX;
        adj.resize(VERTEX+1);
        visited.resize(VERTEX+1,false);
    }
    void addEdge(ll v,ll w){

        adj[v].push_back(w);

    }
    void BFS(ll s){
        Fam++;
        list<ll> queue;
        visited[s] = true;
        queue.push_back(s);
        while (!queue.empty()){
            for(ll i:adj[queue.front()]){
                if(adj[i].size()>adj[queue.front()].size()) Fam++;
                if(visited[i]) continue;
                queue.push_back(i);
                visited[i]=true;
                
            }
            queue.pop_front();
        }
    }
};

int main(){
    ll size,val1,val2,edges,low=inf;
    cin>>size>>edges;
    Graph graph(size);
    for(ll i=0;i<edges;i++){
        cin>>val1>>val2;
        graph.addEdge(val1,val2);
        if(val1<low) low=val1;
    }
    for(ll i=1;i<=size;i++){
        if(!graph.visited[i])
             graph.BFS(i);
    }
    cout<<graph.Fam;

    return 0;
}
