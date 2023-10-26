#include <iostream>
#define ll long long int
using namespace std;
//run id:1963
ll arr[100][100];
ll rowSize,columSize;

int parent(int i){
    return (i / 2);
}
int leftChild(int i){
    return (2 * i);
}
int rightChild(int i){
    return ((2 * i) + 1);
}
void heapifyUp(ll i,ll j){
    while (i > 1 && arr[parent(i)][j] < arr[i][j]) {
        swap(arr[parent(i)][j], arr[i][j]);
         i= parent(i);
    }
}
void heapifyDown(int i,int j){
    ll maxIndex = i;
    ll l = leftChild(i);
    if (l <= rowSize && arr[l][j] > arr[maxIndex][j]) {
        maxIndex = l;
    }
    ll r = rightChild(i);
    if (r <= rowSize && arr[r][j] > arr[maxIndex][j]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        swap(arr[i][j], arr[maxIndex][j]);
        heapifyDown(maxIndex,j);
    }
}
void heapDel(){
    for(ll i=1;i<=columSize;i++){
        swap(arr[rowSize][i],arr[1][i]);
        arr[rowSize][i]=0;
        heapifyDown(1,i);
    }
    rowSize--;
}

int main() {
    ll row,colum,x;
    cin>>row>>colum;
    for(ll i=0;i<row;i++){
        rowSize++;
        columSize=0;
        for(ll j=0;j<colum;j++){
            cin>>x;
            columSize++;
            arr[rowSize][columSize]=x;
            heapifyUp(rowSize,columSize);
        }
    }
    for(ll i=1;i<=row;i++){
        for(ll j=1;j<=colum;j++){
            cout<<arr[1][j]<<" ";
        }
        heapDel();
        cout<<endl;
    }
    return 0;
}