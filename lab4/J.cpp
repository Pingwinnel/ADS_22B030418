#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

//run id:2288
void rec(int arr[],int Left,int Right){
	if(Left+1>=Right){
		cout << arr[Left] << " ";
		return;
	}
	cout << arr[(Left+Right)/2] << " ";
	rec(arr,Left,(Left+Right)/2);
	rec(arr,((Left+Right)/2)+1, Right);
}

int main(){
	int n;
	cin >> n;
	n = pow(2,n) -1;
	int arr[n];
	for(int i =0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr,arr+n);
    int L = 0;
    int R = n - 1;
	rec(arr,L,R);
	
}