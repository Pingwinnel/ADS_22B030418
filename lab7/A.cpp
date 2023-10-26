#include <iostream>
#define ll long long int
using namespace std;
char arrVowel[100000];
char arr1[100000];
ll heapSizeVowel;
ll heapSizeArr1;

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
void heapifyDown(char arr[],ll i,ll heap_size){
    ll maxIndex = i;
    int l = leftChild(i);
    if (l <= heap_size && arr[l] < arr[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heap_size && arr[r] < arr[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        swap(arr[i], arr[maxIndex]);
        heapifyDown(arr,maxIndex,heap_size);
    }
}
ll heapDelete(char arr[],ll index,ll heap_size){
    swap(arr[heap_size],arr[index]);
    heap_size--;
    heapifyDown(arr,index,heap_size);
    return heap_size;
}
int main() {
    ll size;
    string vowels="aeuio";
    cin>>size;
    char x;
    for(ll i=0;i<size;i++){
        cin>>x;
        if(vowels.find(x)<size){
            heapSizeVowel++;
            arrVowel[heapSizeVowel]=x;
            heapifyUp(arrVowel,heapSizeVowel);
        }else{
            heapSizeArr1++;
            arr1[heapSizeArr1]=x;
            heapifyUp(arr1,heapSizeArr1);
        }
    }
    for(ll i=heapSizeVowel;i>=1;i--){
        cout<<arrVowel[1];
        heapSizeVowel=heapDelete(arrVowel,1,heapSizeVowel);
    }
    for(ll i=heapSizeArr1;i>=1;i--){
        cout<<arr1[1];
        heapSizeArr1=heapDelete(arr1,1,heapSizeArr1);
    }
}