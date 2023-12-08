#include <bits/stdc++.h>

using namespace std;
//run id:

class Graph{
public:
    vector <vector <int> > G;
    vector <int> parent;
    int V;

    Graph(int size){
        V = size;
        for(int i = 0; i < V; i++){
            vector <int> t;
            G.push_back(t);
        }
        fillParent();
    }

    void fillParent(){
        for(int i = 0; i < V; i++){
            parent.push_back(i);
        }
    }

    void addEdge(int u, int v){
        if(u < v){
            G[u].push_back(v);
        } else{
            G[v].push_back(u);
        }
    }

    int findParent(int v){
        if(v == parent[v]){
            return v;
        }
        return parent[v] = findParent(parent[v]);
    }

    bool unite(int x, int y){
        int u = findParent(x);
        int v = findParent(y);
        if(u == v){
            return false;
        }
        parent[u] = v;
        return true;
    }
};

int main(){

    int n, m;
    cin >> n >> m;
    Graph * g = new Graph(n);

    while(m--){
        int u, v;
        cin >> u >> v;
        g->addEdge(--u, --v);
    }

    int count = -1;
    stack <int> answers;
    for(int i = n - 1; i >= 0; i--){
        count++;
        answers.push(count);
        for(int j = 0; j < g->G[i].size(); j++){
            if(g->unite(i, g->G[i][j])){
                count--;
            }
        }
    }

    while(!answers.empty()){
        cout << answers.top() << endl;
        answers.pop();
    }

    return 0;
}