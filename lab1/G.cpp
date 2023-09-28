#include <iostream>
#include <cmath>
using namespace std;
//run id :6986
int main(){
    int n;
    cin >> n;
    bool fl=true;
    int a[10000];
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
            a[cnt]=i;
            cnt++;            
        }
    }
    
    int ar[100];
    cnt=1;
    for(int i=2;i<1001;i++){
        fl=true;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){
                fl=false;
                break;
            }

        }
        if(fl==true){
            ar[cnt]=a[i];
            cnt++;      
                  
        }
    }
    cout << ar[n];
}