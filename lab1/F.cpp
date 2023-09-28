#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    bool fl=true;
    int arr[1001];
    int cnt=1;
    for(int i=2;i<=10000;i++){
        fl=true;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){
                fl=false;
                break;
            }

        }
        if(fl==true){
            arr[cnt]=i;
            if(cnt==n){
                cout << arr[cnt] << " ";
            }
            cnt++;
            
        }
    }
}