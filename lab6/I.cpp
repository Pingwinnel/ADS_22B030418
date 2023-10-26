#include <iostream>
#define ll long long int
using namespace std;
//run id:1976
char arr[100000];
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
void heapifyUp(char arr[],ll i){
    while (i > 1 && arr[parent(i)] > arr[i]) {
        swap(arr[parent(i)], arr[i]);
         i = parent(i);
    }
}
void heapifyDown(char arr[],ll i){
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
    string str;
    cin>>str;
    for(ll i=0;i<str.size();i++){
        heapSize++;
        arr[heapSize]=str[i];
        heapifyUp(arr,heapSize);
    }
    for(ll i=1;i<=str.size();i++){
        cout<<arr[1];
        heapDel(1);
    }
}
