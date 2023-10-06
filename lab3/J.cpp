#include <iostream>
#include <cmath>
#define ll long long int
using namespace std;
//run id:3500

bool Steal(int arr[],ll size,ll hours,ll middle){
    for(ll i=0;i<size;i++){
        ll x=arr[i];
        long double numBer=(x*1.00/middle*1.00);
        if(numBer<1){
            hours--;
        }else{
            hours-=ceil(numBer);

        }
        if(hours<0){
            return false;
        }
    }
    return true;
}

int main() {
    ll numBags,hour,right=0,left=999999999;
    cin>>numBags>>hour;
    int arr[numBags];
    for(ll i=0;i<numBags;i++){
        cin>>arr[i];
        if(arr[i]>right){
            right=arr[i];
        }
        if(arr[i]<left){
            left=arr[i];
        }
    }
    if(hour/numBags>1){
        left=left/(hour/numBags);
        right=right/(hour/numBags);
    }else if(hour-numBags==0){
        cout<<right;
        return 0;
    }
    ll middle=(left+right)/2;
    while(left<right){
        if(Steal(arr,numBags,hour,middle)){
            right=middle;
        }else{
            left=middle+1;
        }
        middle=(left+right)/2;
    }
    cout<<middle;
    return 0;
}