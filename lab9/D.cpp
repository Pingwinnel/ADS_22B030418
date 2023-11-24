#include<bits/stdc++.h> 

#define ll long long int
using namespace std;
//run id:2332

struct strint{
    string str;
    ll cnt;
};


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
    string city,guest;
    ll size,largestCount=1,count=0,num=0;
    cin>>city>>size;
    transform(city.begin(), city.end(), city.begin(), ::tolower); 
    strint arr[size];
    for(ll i=0;i<size;i++){
        cin>>guest;
        arr[i].str=guest;
        transform(guest.begin(), guest.end(), guest.begin(), ::tolower); 
        guest=guest+'#'+city;
        count=knut(guest,guest.size());
        arr[i].cnt=count;
        if(count>largestCount){
            largestCount=count;
            num=1;
        }else if(count==largestCount) num++;
    }
    cout<<num<<endl;
    for(ll i=0;i<size;i++){
        if(arr[i].cnt==largestCount) cout<<arr[i].str<<endl;
        }
    return 0;

}