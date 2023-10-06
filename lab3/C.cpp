#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;
//run id:3470

ll binary_search(ll arr[],ll size,ll l,ll r){
    ll left=0,right=size;
    ll indexl,indexr;

    while(left<=right){
        ll mid=(left+right)/2;
        if(arr[mid]==l){
            indexl=mid;
            break;
        }else if(left+1==right && (arr[left]<l && arr[right]>l)){
            indexl=right;
            break;
        }else if(left==right && arr[left]>l){
            indexl=right;
            break;  
        }else if(left==right && arr[left]<l){
            return 0;
        }else if(arr[mid]>l){
            right=mid;
        }else{
            left=mid;
        }
    }
    left=0,right=size;

    while(left<=right){
        ll mid=(left+right)/2;

        if(arr[mid]==r){
            indexr=mid;
            break;
        }else if(left==right && arr[left]>r){
            return 0;  
        }else if(left+1==right && (arr[left]<r && arr[right]<r)){
            indexr=right-1;
            break;
        }else if(left+1==right && (arr[left]<r && arr[right]>r)){
            indexr=left;
            break;
        }else if(arr[mid]>r){
            right=mid;
        }else{
            left=mid;
        }
    }
    return indexr-indexl+1;
}

int main() {
    ll size,query;
    cin>>size>>query;
    ll arr[size];
    ll l1,l2,r1,r2;
    for(ll i=0;i<size;i++){
        cin>>arr[i];
    }
    sort(arr,arr+size);
    for(ll i=0;i<query;i++){
        cin>>l1>>r1>>l2>>r2;
        if(max(l1,l2)>min(r1,r2)){
            cout<<binary_search(arr,size,min(l1,l2),min(r1,r2))+binary_search(arr,size,max(l1,l2),max(r1,r2))<<endl;
        }else{
            cout<<binary_search(arr,size,min(l1,l2),max(r1,r2))<<endl;
        }
    }
    return 0;
}