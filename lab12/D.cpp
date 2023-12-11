#include <bits/stdc++.h>
using namespace std;
//run id:1890

const int MAX_N = 1e5 + 5;
const int INF = 1e9;

vector<pair<int, int> > graph[MAX_N];
int minimal_ages[MAX_N];
int n;
set<pair<int, int> > way_roads;

void dijkstra(int start){
    for(int i = 1; i <= n; i++){
        if(i == start)
            minimal_ages[i] = 0;
        else
            minimal_ages[i] = INF;

        way_roads.insert(make_pair(minimal_ages[i], i));
    }

    for(int i = 0 ; i < n; i++){
        pair<int, int> p = *(way_roads.begin());
        way_roads.erase(p);

        int u = p.second;
        int v = p.first;

        if(v == INF) break;

        for(int j = 0; j< graph[u].size(); j++){
            p = graph[u][j];
            int v = p.first, w = p.second;
            if(minimal_ages[v] > w && minimal_ages[v] > minimal_ages[u]){
                way_roads.erase(make_pair(minimal_ages[v], v));
                minimal_ages[v] = max(minimal_ages[u], w);
                way_roads.insert(make_pair(minimal_ages[v], v));
            }
        }
    }
}

int main(){
    cin >> n;
    pair<int, int> city_coord[n];

    for(int i = 0; i < n ; i++){
        int x, y;
        cin >> x >> y;
        city_coord[i] = make_pair(x, y);
    }

    for(int i = 0 ; i < n; i++){
        for(int j = i+1; j < n; j++){
            int w = abs(city_coord[i].first - city_coord[j].first) + abs(city_coord[i].second-city_coord[j].second);
            graph[i+1].push_back(make_pair(j+1, w));
            graph[j+1].push_back(make_pair(i+1, w));
        }
    }

    dijkstra(1);

    cout << minimal_ages[n];


    return 0;
}