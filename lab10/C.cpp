#include <iostream>
#include <cmath>
#define ll long long int
using namespace std;
//run id:5001

struct hashTable{
    char tapes;
    bool have=0;
};

hashTable arr[100000];
const ll P=31;

size_t Hash(string str){

    size_t hash_code=0;

    for(ll i=0;i<str.size();i++){
        hash_code=(hash_code*P+(str[i]));
    }

    return hash_code;

}


int main(){
    ll size,j=0;
    size_t hash_of_str,hash_of_searching;
    string str,tape;
    cin>>str;
    ll pw = 1;
    for(ll i=0;i<str.size();i++){
        arr[i].tapes=str[i];
    }
    cin>>size;
    for(ll i=0;i<size;i++){

        cin>>tape;
        pw = 1;
        for(ll y = 1; y < tape.size(); y ++) {
            pw *= P;
        }
        hash_of_str=Hash(str.substr(0,tape.size()));
        hash_of_searching=Hash(tape);

        for(ll j=0;j<=str.size()-tape.size();j++){

            if(hash_of_searching==hash_of_str){
                for(ll k=j;k<j+tape.size();k++){
                    arr[k].have=1;
                }
            }
            hash_of_str=((hash_of_str - (str[j] * pw )) * P+(str[j+tape.size()]));
        }
    }

    for(ll i=0;i<str.size();i++){
        if(arr[i].have==0){

            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}
