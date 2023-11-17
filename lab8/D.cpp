#include <iostream>
#include <cmath>
#define ll long long int
using namespace std;
//run id:5020

const ll P=57;

struct hashTable{
    string str;
    ll hash;
};


ll Hash(string str){
    ll hashCode=0;
    for(ll i=0;i<str.size();i++){
        hashCode+=pow(P,i)*str[i];
    }
    return hashCode;

}


int main(){
    ll size,x,cnt=0,MAX_cnt=0;
    hashTable arr[200];
    string str1;
    ll hashStr;

    while(true){
        cin>>x;
        if(x!=0){
            for(ll j=0;j<x;j++){
                cin>>str1;
                arr[j].str=str1;
                arr[j].hash=Hash(str1);
            }
            cin>>str1;
            for(ll j=0;j<x;j++){

                hashStr=Hash(str1.substr(0,arr[j].str.size()));

                for(ll i=0;i<str1.size()+1-arr[j].str.size();i++){
                    if(hashStr==arr[j].hash){
                        cnt++;
                    }
                    hashStr=(((hashStr-str1[i]))+str1[i+arr[j].str.size()]*pow(P,arr[j].str.size()))/P;
                }
                if(MAX_cnt<cnt){
                    MAX_cnt=cnt;
                }
                arr[j].hash=cnt;
                cnt=0;
            }
            cout<<MAX_cnt<<endl;
            for(ll i=0;i<x;i++){
                if(arr[i].hash==MAX_cnt) cout<<arr[i].str<<endl;
            }
            MAX_cnt=0;
        }else{
            break;
        }
    }
    return 0;
}