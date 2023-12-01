#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// run id:3038
ll inf=(int) 1e9;
struct Graph {
    int VERTICESERTERTI;
    vector<list<int>> adj;
    vector<bool> red;
    Graph(int V){
        this->VERTICESERTERTI = V;
        adj.resize(V+1);
        red.resize(V+1);
    };
    void addEdge(int v, int w){
        adj[v].push_back(w);
        adj[w].push_back(v);
    };
    void redVertice(int v){
        red[v]=true;
    };
    void BFS(int s){
        vector<bool> visited(VERTICESERTERTI+1);
        visited.resize(VERTICESERTERTI+1, false);
        list<pair<int,int>> queue;
        visited[s] = true;
        queue.push_back({s,0});
        if(red[s]){
            cout<<0<<endl;
            return;
        }
        while (!queue.empty()){
            for(auto i:adj[queue.front().first]){
                if(!visited[i]){
                    queue.push_back({i,queue.front().second+1});
                    visited[i]=true;
                }
                if(red[i]){
                    cout<<queue.front().second+1<<endl;
                    return;
                }
            }
            queue.pop_front();
        }
        cout<<-1<<endl;
        return;
    };
};
 
int main(){
    ll vertices,edges,num;
    ll fir,sec;
    cin>>vertices>>edges>>num;
    Graph g(vertices);
    for(ll i=0;i<edges;i++){
        cin>>fir>>sec;
        g.addEdge(fir,sec);
    }
    for(ll i=0;i<num;i++){
        cin>>fir>>sec;
        if(fir==1){
            g.redVertice(sec);
        }else{
            g.BFS(sec);
        }
    }


    return 0;
}