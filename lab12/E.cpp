#include <bits/stdc++.h>

using namespace std;
//run id:

vector<int>roadways[410];
vector<int>airlanes[410];
int cities[405][405];


struct edge {
    int u, v, w;
};

int n, m, v;
vector<edge> e;

const int INF = 100000;
bool isCycle = false;

void solve() {
    vector<int> dest (n, INF);
    dest[v] = 0;
    vector<int> p (n, -1);
    int x;

    for (int i=0; i<n; i++) {
        x = -1;
        for (int j=0; j < n * n; j++)
            if (dest[e[j].u] < INF)
                if (dest[e[j].v] > dest[e[j].u] + e[j].w) {
                    dest[e[j].v] = max (-INF, dest[e[j].u] + e[j].w);
                    p[e[j].v] = e[j].u;
                    x = e[j].v;
                }
    }

    if (x == -1)
        isCycle = false;
    else {
        int y = x;
        for (int i=0; i<n; ++i)
            y = p[y];

        vector<int> path;
        for (int cur=y; ; cur=p[cur]) {
            path.push_back (cur);
            if (cur == y && path.size() > 1)  break;
        }
        reverse (path.begin(), path.end());

        cout << "YES" << endl;
        cout << path.size() << endl;
        for (int i=0; i<path.size(); ++i)
            cout << ++path[i] << ' ';
        cout << endl;
        isCycle = true;
    }
}

int main(){
    cin >> n;
    vector<int> d(n, INF);
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            edge cur;
            cin >> cur.w;
            cur.u = i; cur.v = j;
            e.push_back(cur);
        }
    }

    for (int i = 0; i < n; i ++){
        v = i;
        solve();
        if (isCycle)
            break;
    }
    if (!isCycle)
        cout << "NO" << endl;
}