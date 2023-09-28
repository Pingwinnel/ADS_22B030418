#include <iostream>
#include <cmath>
using namespace std;
//run id :6987
int main(){
    int n;
    cin >> n;
    if(n==1){
        cout << "NO";
        return 0;
    }
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}