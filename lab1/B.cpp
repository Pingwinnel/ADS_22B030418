#include <iostream>
using namespace std;
//run id :6972
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<n;i++){
        bool fg=true;
        for(int j=i-1;j>=0;j--){
            if(arr[i]>=arr[j]){
                cout << arr[j] << " ";
                fg = false;
                break;
            }
        }
        if(fg==true){
            cout << "-1 ";
        }
    }



}