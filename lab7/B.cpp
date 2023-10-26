#include <iostream>
#define ll long long int
using namespace std;
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
void heapify_up(ll arr[],ll i){
    while (i > 1 && arr[parent(i)] > arr[i]) {
        swap(arr[parent(i)], arr[i]);
         i = parent(i);
    }
}
void heapifydown(ll arr[],ll i,ll size){
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
        heapifydown(arr,maxIndex,size);
    }
}
void heap_delete(ll arra[],ll index,ll size){
    swap(arra[size],arra[index]);
    size--;
    heapifydown(arra,index,size);
}
int main() {
    ll size_of_first,size_of_second,x;
    cin>>size_of_first>>size_of_second;
    for(ll i=0;i<size_of_first;i++){
        cin>>x;
        heapSize++;
        arr[heapSize]=x;
        heapify_up(arr,heapSize);
    }for(ll i=0;i<size_of_second;i++){
        cin>>x;
        heapSize2++;
        arr2[heapSize2]=x;
        heapify_up(arr2,heapSize2);
    }
    while(heapSize!=0 && heapSize2!=0){
        if(arr[1]==arr2[1]){
            cout<<arr[1]<<" ";
            heap_delete(arr,1,heapSize);
            heap_delete(arr2,1,heapSize2);
            heapSize2--;
            heapSize--;
        }else if(arr[1]>arr2[1]){
            heap_delete(arr2,1,heapSize2);
            heapSize2--;
        }else{
            heap_delete(arr,1,heapSize);
            heapSize--;
        }
    }
}