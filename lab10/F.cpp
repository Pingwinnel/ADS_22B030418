#include <iostream>
#include <unordered_map>

#define ll long long int
using namespace std;
//run id:5054

const ll P=29;

size_t Hash(string str){

    size_t hashCode=0;

    for(ll i=0;i<str.size();i++){
        hashCode=(hashCode*P+(str[i]));
    }

    return hashCode;

}


int main(){
    unordered_map<size_t,int> permutation;
    string str;
    size_t hashSearching;
    cin>>str;
    for (int i = 0; i < str.size(); ++i) {
        size_t hashVal = 0;
        ll pow = 1;
        for (int j = i; j < str.size(); ++j) {
            hashVal = (hashVal + (str[j] - 'a' + 1) * pow);
            pow = (pow * P);
            permutation[hashVal]=1;
        }
    }
    cout<<permutation.size();
} 