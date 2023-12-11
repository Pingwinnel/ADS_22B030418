#include <bits/stdc++.h>

using namespace std;
//run id:1878


int main(){
    int n,m,u,v;
    cin >> n >> m;
    vector<int>roadways[410];
    vector<int>airlanes[410];
    int cities[405][405];
    for(int i=0;i<m;i++){
        cin >> u >> v;
        roadways[--u].push_back(--v);
        roadways[v].push_back(u);
        cities[u][v] = cities[v][u] = 1;
    }
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            if (cities[i][j] == 0 && i != j){
                airlanes[i].push_back(j);
            }
        }
    }
    queue<int>que1;
    vector<int>dist1(n+1);
    vector<bool>used1(n+1);
    que1.push(0);
    used1[0] = true;
    while(!que1.empty()){
        v = que1.front();
        que1.pop();
        for(int i=0;i<roadways[v].size();i++){
            u = roadways[v][i];
            if(!used1[u]){
                used1[u] = true;
                que1.push(u);
                dist1[u] = dist1[v]+1;
            }
        }
    }
    queue<int>que2;
    vector<int>dist2(n+1);
    vector<bool>used2(n+1);
    que2.push(0);
    used2[0] = true;
    while(!que2.empty()){
        v = que2.front();
        que2.pop();
        for(int i=0;i<airlanes[v].size();i++){
            u = airlanes[v][i];
            if(!used2[u]){
                used2[u] = true;
                que2.push(u);
                dist2[u] = dist2[v]+1;
            }
        }
    }

    if (!used1[n-1] || !used2[n-1]){
        cout << -1;
    }

    else {
        cout << max(dist1[n-1], dist2[n-1]);
    }
}