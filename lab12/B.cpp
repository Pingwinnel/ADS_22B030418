#include <bits/stdc++.h>

using namespace std;
//run id:1876

int INF = 1000000000;

vector<pair<int,int> > graph[200005];
int n,m;

int dijkstra(int start, int end){
    vector<int> des(200005, INF);

    des[start] = 0;
    set< pair<int,int> > q;
    q.insert(make_pair(des[start], start));
    while(!q.empty()){
        int v = (*(q.begin())).second;
        q.erase(q.begin());
        for(int j = 0; j<graph[v].size(); j++){
            int u = graph[v][j].first;
            int w = graph[v][j].second;

            if(des[v] + w < des[u]){
                q.erase(make_pair(des[u], u));
                des[u] = des[v] + w;
                q.insert(make_pair(des[u], u));
            }
        }
    }
    return des[end];
}



int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }

    int q,w,e,r;

    cin >> q >> w >> e >> r;

    int a,b;
    a = dijkstra(q,w) + dijkstra(w,e) + dijkstra(e,r);
    b = dijkstra(q,e) + dijkstra(e,w) + dijkstra(w,r) ;

    if(min(a,b) <= INF){
        cout << min(a,b);
    }else{
        cout << -1;
    }
    return 0;
}