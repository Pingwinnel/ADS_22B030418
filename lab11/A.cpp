#include <bits/stdc++.h>  
using namespace std; 
#define ll long long 
//run id:1398
int main(){ 
    int n, m; 
    cin >> n >> m; 
    vector <pair<ll, pair<int,int>>> G; 
    while(m--){ 
        int l, r; 
        ll w; 
        cin >> l >> r >> w; 
 
        G.push_back(make_pair(w, make_pair(l, r))); 
    } 
 
    sort(G.begin(),G.end());
    int counter = 2;
    ll mst = 0;
    while(counter <= n){
        for(auto p : G){
            int a=p.second.first, b=p.second.second, w=p.first; 
            if(a<counter && counter<=b){ 
                counter++;
                mst+=w;
                break;
            } 
        } 
    } 
    cout << mst; 
    return 0; 
}