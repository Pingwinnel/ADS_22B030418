#include <iostream>

using namespace std;

int main(){
    int count = 0,n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
 
            if (sum + arr[j] >= k) {
                sum=sum-arr[j];
                count++;
            }
            else {
                sum=sum+arr[i];
            }
        }

   
}
cout<<count;
}