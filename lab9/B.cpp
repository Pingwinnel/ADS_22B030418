#include <iostream>
#include <vector>
#define ll long long int
using namespace std;
//run id:2321
ll count=0;
vector<ll> knut(string str,ll size){
    vector<ll> vec(str.size());
    vec[0]=0;
    ll j;
    for(ll i=1;i<str.size();i++){
        j=vec[i-1];
        while(j!=0 && str[j]!=str[i]){
            j=vec[j-1];
        }
        if(str[j]==str[i]){
            j++;
        }
        vec[i]=j;
        if(j==size) count++;
    }
    return vec;
}


int main(){
    string str,searching;
    ll num;
    cin>>str;
    cin>>num;
    cin>>searching;
    ll size=str.size();
    str+='*';
    str+=searching;
    vector<ll> vec=knut(str,size);
    if(count>num) cout<<"YES";
    else cout<<"NO";

    return 0;

}