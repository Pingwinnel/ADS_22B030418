#include <iostream>
#include <vector>
#define ll long long int
using namespace std;
//run id:2441
ll count=0;
vector<ll> knut(string str){
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
    }
    for(ll i=0;i<(str.size()-1)/2;i++){
        if(str[i+1]==str[0] && (vec[i*2+1]-vec[i]==i+1)){
            count++;
        }
    }
    cout<<count;
    return vec;
}

int main(){
    string str;
    cin>>str;
    knut(str);
    return 0;
} 