#include <iostream>
#include <cmath>
#define ll long long int
using namespace std;
//run id: 5000

const int q =  1e9 + 7;
const ll P=31;

size_t Hash(string str){

    size_t hashInt=0;

    for(ll i=0;i<str.size();i++){
        hashInt=(hashInt*P+(str[i]));
    }

    return hashInt;

}
int main(){
    ll counter=0 ;
    size_t hashStr2 , hashpara , hashStr1 ;
    string str1 , str2 , parasite;

    cin >> str1 >> str2 >> parasite;

    hashpara = Hash(parasite);
    hashStr1 = Hash(str1.substr(0,parasite.size()));
    hashStr2 = Hash(str2.substr(0,parasite.size()));

    ll pw = 1;
    for(ll i = 1; i < parasite.size(); i ++) {
        pw *= P;
    }

    for(ll i=0;i<=min(str1.size(),str2.size())-parasite.size();i++){


        if(hashStr1 == hashpara and hashStr2 == hashpara) counter++;

        hashStr1 = ((hashStr1 - (str1[i]) * pw ) * P + (str1[i+parasite.size()])) ;
        hashStr2 = ((hashStr2 - (str2[i]) * pw ) * P + (str2[i+parasite.size()] ));
    }

    cout << counter;

    return 0;
}