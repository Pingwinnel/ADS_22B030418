#include <iostream>
#define ll long long int
using namespace std;
//run id:1482
ll arr[1000000];
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
void heapDelete(ll index){
    swap(arr[heapSize],arr[index]);
    heapSize--;
    heapifyDown(arr,index);

}
int main() {
    ll numActions,x,count=0,maximalK;
    string action;
    cin>>numActions>>maximalK;
    while(numActions>0){
        numActions--;
        cin>>action;
        if(action=="insert"){
            cin>>x;
            heapSize++;
            arr[heapSize]=x;
            heapifyUp(arr,heapSize);
            if(heapSize>maximalK){
                heapDelete(1);
            }
        }else{
            for(ll i=1;i<=heapSize;i++){
                count+=arr[i];
            }
            cout<<count<<endl;
            count=0;
        }


    }
    return 0;
}