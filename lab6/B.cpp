#include <iostream>
#define ll long long int
using namespace std;
//run id:1957
ll arr[100000];
ll arr2[100000];
ll heapSize,heapSize2;


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
void heapifyDown(ll arr[],ll i,ll size){
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= size && arr[l] < arr[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= size && arr[r] < arr[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        swap(arr[i], arr[maxIndex]);
        heapifyDown(arr,maxIndex,size);
    }
}
void heapDel(ll arra[],ll index,ll size){
    swap(arra[size],arra[index]);
    size--;
    heapifyDown(arra,index,size);
}
int main() {
    ll sizeFirst,sizeSecond,x;
    cin>>sizeFirst>>sizeSecond;
    for(ll i=0;i<sizeFirst;i++){
        cin>>x;
        heapSize++;
        arr[heapSize]=x;
        heapifyUp(arr,heapSize);
    }for(ll i=0;i<sizeSecond;i++){
        cin>>x;
        heapSize2++;
        arr2[heapSize2]=x;
        heapifyUp(arr2,heapSize2);
    }
    while(heapSize!=0 && heapSize2!=0){
        if(arr[1]==arr2[1]){
            cout<<arr[1]<<" ";
            heapDel(arr,1,heapSize);
            heapDel(arr2,1,heapSize2);
            heapSize2--;
            heapSize--;
        }else if(arr[1]>arr2[1]){
            heapDel(arr2,1,heapSize2);
            heapSize2--;
        }else{
            heapDel(arr,1,heapSize);
            heapSize--;
        }
    }
}