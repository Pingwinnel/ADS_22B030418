#include <iostream>
#define ll long long int
using namespace std;


bool canDivide(ll arr[],ll size,ll middle,ll block){
    ll count=0;
    ll placedBlocks=0;
    for(ll i=0;i<size;i++){
        count+=arr[i];
        if(count>middle){
            placedBlocks++;
            count=arr[i];
        }
    }
    return block>=placedBlocks+1;
}


int main(){
    ll homeNum,block,allsum=0,maximal=0;
    cin>>homeNum>>block;
    ll arr[homeNum];
    for(ll i=0;i<homeNum;i++){
        cin>>arr[i];
        allsum+=arr[i];
        if(arr[i]>maximal){
            maximal=arr[i];
        }
    }
    ll left=maximal,right=allsum,middle=left+(right-left)/2;
    while(right>=left){
        if(canDivide(arr,homeNum,middle,block)){
            right=middle-1;
            middle=left+(right-left)/2;

        }else{
            left=middle+1;
            middle=left+(right-left)/2;
        }
    }
    cout<<middle;
}