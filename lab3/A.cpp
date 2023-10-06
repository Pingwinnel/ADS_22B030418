#include <iostream>
#include <vector>
#include <map>

using namespace std;
//run id:2446

int main(){
multimap<int,pair<int,int>> mp;
vector<int> vecInput;
int n,m,k;
bool flag=false;
cin>>n;
for(int i=0;i<n;i++){
    cin>>m;
    vecInput.push_back(m);
}
cin>>n>>m;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>k;
        mp.emplace(k,make_pair(i,j));
    }
}

for(int i=0;i<vecInput.size();i++){
    if(mp.find(vecInput[i])!=mp.end()){
        auto  it=mp.find(vecInput[i]);
        cout<<it->second.first<<" "<<it->second.second<<endl;
    }
    else cout<<-1<<endl;
}
}