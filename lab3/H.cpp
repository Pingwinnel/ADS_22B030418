#include <iostream>

using namespace std;
//run id:3415

int binary_search(int arr[], int l, int r, int x)
{
    int m,max=r;
    while (l <= r) {
        m = l + (r - l) / 2;
 
        if (arr[m] == x)
            return m;
 
        if (arr[m] < x)
            l = m + 1;
 
        else
            r = m - 1;
    }
 
    if(arr[m]>x){
        return m;
    }
    else if(x>arr[m]){
        return m+1;
    }
    else{
        return m-1;
    }
}

int main(){

    int n,m,l,sum=0;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>l;
        sum+=l;
        arr[i]=sum;
    }
    int arr2[m],r=n-1;
    for(int i=0;i<m;i++){
        cin>>n;
        arr2[i]=n;
    }
    for(int i=0;i<m;i++){
        cout<<binary_search(arr,0,r,arr2[i])+1<<endl;
    }
}