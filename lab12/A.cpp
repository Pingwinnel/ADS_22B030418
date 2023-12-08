#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//run id :2782
ll inf=(int) 1e9+7;
struct pairs{
    ll x,y;
};

int main(){
    ll row,column,time=0,mushrooms=0;
    cin>>row>>column;
    ll arr[row+1][column+1];
    queue<pairs> que;
    for(ll i=0;i<row;i++){
        for(ll j=0;j<column;j++){
            cin>>arr[i][j];
            if(arr[i][j]==1) mushrooms++;
            else if(arr[i][j]==2) que.push({i,j});
        }
    }

    while(true){
        if(mushrooms==0){
            cout<<time;
            return 0;
        }if(que.empty()){
            cout<<-1;
            return 0;
        }
        ll size=que.size();
        for(ll i=0;i<size;i++){
            if(arr[que.front().x-1][que.front().y]==1 && que.front().x>0){

                que.push({que.front().x-1,que.front().y});
                arr[que.front().x-1][que.front().y]=2;
                mushrooms--;

            }if(arr[que.front().x+1][que.front().y]==1 && que.front().x<row-1){

                que.push({que.front().x+1,que.front().y});
                arr[que.front().x+1][que.front().y]=2;
                mushrooms--;

            }if(arr[que.front().x][que.front().y-1]==1 && que.front().y>0){

                que.push({que.front().x,que.front().y-1});
                arr[que.front().x][que.front().y-1]=2;
                mushrooms--;

            }if(arr[que.front().x][que.front().y+1]==1 && que.front().y<column-1){

                que.push({que.front().x,que.front().y+1});
                arr[que.front().x][que.front().y+1]=2;
                mushrooms--;

            }
            que.pop();
        }
        time++;
    }

    return 0;
}