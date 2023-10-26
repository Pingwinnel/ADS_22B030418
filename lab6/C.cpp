#include <iostream>
#define ll long long int
using namespace std;
//run id:1958
ll arr[200000];
ll heapSize;

int parent(int i){
    return (i / 2);
}
int leftChild(int i){
    return (2 * i);
}
int rightChild(int i){
    return ((2 * i) + 1);
}
void heapifyUp(ll arr[],ll i){
    while (i > 1 && arr[parent(i)] > arr[i]) {
        swap(arr[parent(i)], arr[i]);
         i = parent(i);
    }
}
void heapifyDown(ll arr[],ll i){
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && arr[l] < arr[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && arr[r] < arr[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        swap(arr[i], arr[maxIndex]);
        heapifyDown(arr,maxIndex);
    }
}
void heapDel(ll index){
    swap(arr[heapSize],arr[index]);
    heapSize--;
    heapifyDown(arr,index);

}
int main() {
    ll size,x;
    ll diff=9999999999;
    cin>>size;
    for(ll i=0;i<size;i++){
        cin>>x;
        heapSize++;
        arr[heapSize]=x;
        heapifyUp(arr,heapSize);
    }
    for(ll i=1;i<size;i++){
        x=arr[1];
        heapDel(1);
        if(arr[1]-x<diff){
            diff=arr[1]-x;
        }
    }
    for(ll i=size;i>1;i--){
        if(arr[i-1]-arr[i]==diff){
            cout<<arr[i]<<" "<<arr[i-1]<<" ";
        }
    }
}