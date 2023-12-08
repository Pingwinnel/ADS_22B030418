#include <bits/stdc++.h>  
using namespace std; 
#define ll long long 
//run id:

int main(){ 
    int n, m; 
    cin >> n >> m; 
    vector <pair<ll, pair<int,int>>> g; 
    while(m--){ 
        int l, r; 
        ll w; 
        cin >> l >> r >> w; 
 
        g.push_back(make_pair(w, make_pair(l, r))); 
    } 
 
    sort(g.begin(),g.end());
    int cnt = 2;
    ll mst = 0;
    while(cnt <= n){
        for(auto p : g){
            int a=p.second.first, b=p.second.second, c=p.first; 
            if(a<cnt && cnt<=b){ 
                cnt++;
                mst+=c;
                break;
            } 
        } 
    } 
    cout << mst; 
    return 0; 
}