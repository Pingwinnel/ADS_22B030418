#include <iostream>
#include <vector>
#define ll long long int
using namespace std;
//run id:2322
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
    ll size;
    string str1,str2;
    cin>>str1>>str2;
    size=str1.size();
    for(ll i=0;i<size;i++){
        str1+=str1[i];
    }
    str2+='*';
    str2+=str1;
    vector<ll> vec=knut(str2,size);

    if(count==1) cout<<vec[vec.size()-1];
    else cout<<-1;
    return 0;

}