#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;
//run id:3498

bool canDeliv(ll arr[],ll islands,ll flights,ll middle){
    for(ll i=0;i<islands;i++){
        int maze=arr[i];
        while(maze>0){
            maze-=middle;
            flights--;
        }
        if(flights<0){
            return false;
        }
    }
    return true;
}

int main() {
    ll numIslands,numFlights;
    ll minCap=1,maxCap=1;

    cin>>numIslands>>numFlights;

    ll arr[numIslands];

    for(ll i=0;i<numIslands;i++){
        cin>>arr[i];
        if(arr[i]>maxCap){
            maxCap=arr[i];
        }
    }
    ll middle;
    while(minCap<maxCap){
        middle =(minCap+maxCap)/2;
        if(canDeliv(arr,numIslands,numFlights,middle)){
            maxCap=middle;
        }else{
            minCap=middle+1;
        }
    }
    cout<<minCap;

}