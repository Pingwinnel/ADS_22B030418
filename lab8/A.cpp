#include <iostream>
#include <math.h>
#include <map>
#define ll long long int
using namespace std;
//run id:5018

string Hashing(string str) {
    ll h = 0;
    ll p = 1;
    const int MOD = 1000000007;

    for (int i = 0; i < str.size(); i++) {
        h = (h + (str[i] - '0' + 1) * p) % MOD;
        p = (p * 11) % MOD;
    }

    return to_string(h);
}


int main() {
  ll n;
  string hashStr;
  cin>>n;
  string arr[n*2];
  map<string,long long> hashTable;
  for(ll i=0;i<n*2;i++){
    cin>>arr[i];
    hashTable[arr[i]]++;
  }
  int counter=0;
  for(int i=0;i<n*2;i++){
    if(counter>=n) return 0;
    hashStr=Hashing(arr[i]);
    if(hashTable[hashStr]){
      cout<<"Hash of string  \""<<arr[i]<<"\" is "<<hashStr<<endl;
      counter++;
    }
  }
  cin>>hashStr;
}