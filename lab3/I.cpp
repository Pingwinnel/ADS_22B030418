#include <iostream>

using namespace std;
//run id:3406

    
bool binary_search(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return true;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return false;
}

int main(){
int n,k,max=0;
cin>>n;
max=n-1;
int arr[n];
for(int i=0;i<n;i++){
    cin>>k;
    arr[i]=k;
}
cin>>n;
if(binary_search(arr,0,max,n)) cout<<"Yes";
else cout<<"No";
    
}