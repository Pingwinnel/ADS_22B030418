#include <iostream>
#include <vector>
#define ll long long int
using namespace std;
//run id:2357
ll count=0;
void knut(string str){
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
    cout<<str.size()- vec[str.size()-1];
}

int main(){
    string str;
    cin>>str;
    knut(str);
    return 0;
} 
