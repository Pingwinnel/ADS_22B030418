#include <iostream>
#define ll long long int
using namespace std;
//run id:1974
ll arr[100000];
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
    ll size,dateTime,x,x2,x3;
    cin>>size;
    string str;
    for(ll i=0;i<size;i++){
        cin>>x>>x2>>x3;
        dateTime=abs(x3*10000)+abs(x2*100)+x;
        heapSize++;
        arr[heapSize]=dateTime;
        heapifyUp(arr,heapSize);
    }
    for(ll i=1;i<=size;i++){
        string dates = to_string(arr[1]);
        cout<<dates[6]<<dates[7]<<"-"<<dates[4]<<dates[5]<<"-"<<dates[0]<<dates[1]<<dates[2]<<dates[3]<<endl;
        heapDel(1);
    }
}