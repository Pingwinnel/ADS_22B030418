#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//run id:3088
ll cnt;
ll row,column;
void find(string * arr,ll i,ll j){
    if(i >= 0 && j >= 0 && i < row && j < column){
        if(arr[i][j]=='1'){
            arr[i][j]='0';
            find(arr,i-1,j);
            find(arr,i+1,j);
            find(arr,i,j-1);
            find(arr,i,j+1);
        }
    }
}
int main(){
    cin>>row>>column;
    string arrStr[row];
    for(ll i=0;i<row;i++){
        cin>>arrStr[i];
    }
    for(ll i=0;i<row;i++){
        for(ll j=0;j<column;j++){
            if(arrStr[i][j]=='1'){
                find(arrStr,i,j);
                cnt++;
            }

        }
    }
    cout<<cnt;
    return 0;
}