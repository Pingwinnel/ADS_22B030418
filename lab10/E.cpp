#include <iostream>
#define ll long long int
using namespace std;
//run id:3069
ll inf=(int) 1e9;
ll was[999][999];

int main(){
    ll elements,num,ver;
    cin>>elements>>num;
    ll was[elements+1][elements+1];

    for(ll i=1;i<=elements;i++){
        for(ll j=1;j<=elements;j++){
            cin>>ver;
            if(ver==1) was[i][j]=1;
            else was[i][j]=0;
        }
    }
    ll arr[3];
    for(ll i=0;i<num;i++){
        cin>>arr[0]>>arr[1]>>arr[2];
        if(was[arr[0]][arr[1]]==1 && was[arr[0]][arr[2]] && was[arr[1]][arr[2]]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}