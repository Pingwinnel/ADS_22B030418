#include <iostream>
#include <math.h>
#define ll long long int
using namespace std;
//run id:918



int main() {
  ll n,charHash,hashXPrev=0,hashYprev;
  cin>>n;
  for(ll i=0;i<n;i++){
    cin>>charHash;
    hashYprev=charHash;
    charHash-=hashXPrev;
    charHash/=pow(2,i);
    hashXPrev=hashYprev;
    cout<<char(charHash+97);
  }
}