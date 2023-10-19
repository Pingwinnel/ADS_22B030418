#include <iostream>
#define ll long long int
using namespace std;
//run id:849

ll arr[100000];
ll heapSize;

int parent(int i){
    return (i / 2);
}
int leftCh(int i){
    return (2 * i);
}
int rightCh(int i){
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
    int l = leftCh(i);
    if (l <= heapSize && arr[l] < arr[maxIndex]) {
        maxIndex = l;
    }
    int r = rightCh(i);
    if (r <= heapSize && arr[r] < arr[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        swap(arr[i], arr[maxIndex]);
        heapifyDown(arr,maxIndex);
    }
}
void heapDelete(ll index){
    swap(arr[heapSize],arr[index]);
    heapSize--;
    heapifyDown(arr,index);

}
int main() {
    ll size,x,count=0,peopleNum=0;
    cin>>size;
    cin>>peopleNum;
    cin>>x;
    heapSize++;
    arr[heapSize]=x;
    for(ll i=1;i<size;i++){
        cin>>x;
        heapSize++;
        arr[heapSize]=x;
        heapifyUp(arr,heapSize);
    }
    while(peopleNum!=0){
     count+=arr[1];
     arr[1]--;
     if(arr[1]<arr[2] || arr[1]<arr[3]){
    heapifyDown(arr,1);
     }
    peopleNum--;
    }
    cout<<count;
    cin>>size;
    return 0;
}