#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#define ll long long int
using namespace std;
//run id:3084
ll inf=(int) 1e9;
ll was[9999999];

int main(){
    ll verSize,edgeSize,ver1,ver2; 
    unordered_map<ll,vector<ll>> edList;  
    cin>>verSize>>edgeSize;
    for(ll i=0;i<edgeSize;i++){
        cin>>ver1>>ver2;
        edList[ver1].push_back(ver2);
        edList[ver2].push_back(ver1);
    }
    ll head,tail;
    queue<ll> que;
    cin>>head>>tail;
    que.push(head);
    was[head]=1;

    while(!que.empty()) {

        for(auto i:edList[que.front()]) {
            if(was[i]==0){
                que.push(i);
                was[i]=1;
            }
        }
        que.pop();
    }
    if(was[tail]==1) cout<<"YES";
    else cout<<"NO";
    



    return 0;

}
