#include <iostream>
#include <cmath>
#define ll long long int
using namespace std;
//run id:5075
string subString;
string arr[10];
const ll P=31;

size_t Hash(string str){

    size_t hashCode=0;

    for(ll i=0;i<str.size();i++){
        hashCode=(hashCode*P+(str[i]));
    }

    return hashCode;

}
bool binary_search(string arr[],ll mid,ll size){
    bool find=false;
    ll findCounter=0;
    ll pNum=1;
    for(ll i=1;i<mid;i++){
        pNum*=P;
    }
    for(ll i=0;i<=arr[0].size()-mid;i++){
        size_t hashSearch = Hash(arr[0].substr(i,mid));

        for(ll j=1;j<size;j++){
            size_t hash_str = Hash(arr[j].substr(0,mid));

            for(ll k=0;k<=arr[j].size()-mid;k++){
                if(hash_str == hashSearch) {
                    find=true;
                    break;
                    }
                hash_str=((hash_str-(arr[j][k]* pNum))*P+(arr[j][k+mid]));
            }
            if(find){
                findCounter++;
                find=false;
            }else{
                findCounter=0;
                break;
            }
        }
        if(findCounter==size-1) {
            subString=arr[0].substr(i,mid);
            return true; 
        }

    }
    return false;
}


int main(){
    ll size;
    cin>>size;
    for(ll i=0;i<size;i++){
        cin>>arr[i];
        if(arr[0].size()>arr[i].size()) swap(arr[0],arr[i]);
    }
    ll left=1,right=arr[0].size();
    ll mid=left+(right-left)/2;
    while(left<right){
        if(left==mid){
            mid++;
        }
        if(binary_search(arr,mid,size)){
            left=mid;
        }else{
            right=mid-1;
        }
        mid=left+(right-left)/2;
    }
    cout<<subString;
} 