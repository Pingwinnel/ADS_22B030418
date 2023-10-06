#include <iostream>
#define ll long long int
using namespace std;
//run id:3501

bool subarr(ll arr[],ll size,ll search,ll mid){
    for(ll i=mid;i<size+1;i++){
        ll y=arr[i];
        if(i>mid){
            y-=arr[i-mid];
        }
        if(y>=search){
            return true;
        }

    }
    return false;
}


int main(){
    ll size,search,sum=0,y,min;
    cin>>size>>search;
    ll arr[size];
    for(ll i=1;i<size+1;i++){
        cin>>y;
        sum+=y;
        arr[i]=sum;

    }
    ll left=1,right=size;
    ll mid;
    while(left<right){
        mid=(left+right)/2;
        if(subarr(arr,size,search,mid)){
            right=mid;
            min=mid;
        }else{
            left=mid+1;
        }
    }
    cout<<min;

    return 0;
}