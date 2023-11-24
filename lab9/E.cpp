#include <iostream>
#include <vector>
#define ll long long int
using namespace std;
//run id:2338
ll knut(string str,ll size){
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
    return vec[size-1];
}


int main(){
    ll size,num;
    cin>>size;
    string str;
    for(ll i=0;i<size;i++){
        cin>>str>>num;
        ll sizeFinal=str.size();
        ll last=knut(str,sizeFinal);
        last=sizeFinal-last;
        sizeFinal=sizeFinal+last*(num-1);
        cout<<sizeFinal<<endl;
    }
    return 0;

}