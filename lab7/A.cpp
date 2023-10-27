#include <bits/stdc++.h>
#define ll long long int
using namespace std;
//run id:612
string arr[9999];
void merge(string arrStr[],ll left,ll left_end,ll right_start,ll right){

    string LeftArr[left_end+1-left], RightArr[right+1-right_start];

    for (int i = 0; i < left_end+1-left; i++)
        LeftArr[i] = arrStr[left + i];
    for (int j = 0; j < right+1-right_start; j++)
        RightArr[j] = arrStr[right_start + j];
    ll leftIndex=0,rightIndex=0,mergeIndex=left;
    while(leftIndex<left_end+1-left && rightIndex<right+1-right_start){
        if(LeftArr[leftIndex].size()>RightArr[rightIndex].size()){
            arrStr[mergeIndex]=RightArr[rightIndex];
            rightIndex++;
        }else{
            arrStr[mergeIndex]=LeftArr[leftIndex];
            leftIndex++;
        }
        mergeIndex++;
    }
    while(leftIndex<left_end+1-left){
        arrStr[mergeIndex]=LeftArr[leftIndex];
        leftIndex++;
        mergeIndex++;
    }
    while(rightIndex<right+1-right_start){
        arrStr[mergeIndex]=RightArr[rightIndex];
        rightIndex++;
        mergeIndex++;
    }

}



void merge_sort(string arra[],ll left,ll right){
    if(right==left){
        return;
    }
    merge_sort(arra,left,left+(right-left)/2);
    merge_sort(arra,(left+(right-left)/2)+1,right);
    merge(arra,left,left+(right-left)/2,(left+(right-left)/2)+1,right);
}


int main() {
    ll size,count;
    string lineStr;
    cin>>size;
    cin.ignore();
    for(ll i=0;i<size;i++){
        getline(cin, lineStr);
        stringstream stream(lineStr);
        string temp;
        count=0;
        while(getline(stream,temp,' ')){
            arr[count]=temp;
            count++;
        }
        merge_sort(arr,0,count-1);
        for(ll j=0;j<count;j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl;
    }
}