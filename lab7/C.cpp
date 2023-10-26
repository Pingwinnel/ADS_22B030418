#include <iostream>
#define ll long long int
using namespace std;
//run id:
ll arr1[9999999];
ll arr2[9999999];
void merge(ll arra[],ll left,ll left_end,ll right_start,ll right){

    int LeftArr[left_end+1-left], RightArr[right+1-right_start];

    for (int i = 0; i < left_end+1-left; i++)
        LeftArr[i] = arra[left + i];
    for (int j = 0; j < right+1-right_start; j++)
        RightArr[j] = arra[right_start + j];
    ll i=0,j=0,mergeIndex=left;
    while(i<left_end+1-left && j<right+1-right_start){
        if(LeftArr[i]>RightArr[j]){
            arra[mergeIndex]=RightArr[j];
            j++;
        }else{
            arra[mergeIndex]=LeftArr[i];
            i++;
        }
        mergeIndex++;
    }
    while(i<left_end+1-left){
        arra[mergeIndex]=LeftArr[i];
        i++;
        mergeIndex++;
    }
    while(j<right+1-right_start){
        arra[mergeIndex]=RightArr[j];
        j++;
        mergeIndex++;
    }

}



void merge_sort(ll arra[],ll left,ll right){
    if(right==left){
        return;
    }
    merge_sort(arra,left,left+(right-left)/2);
    merge_sort(arra,(left+(right-left)/2)+1,right);
    merge(arra,left,left+(right-left)/2,(left+(right-left)/2)+1,right);
}


int main() {
    ll sizeFirst,sizeSecond;
    cin>>sizeFirst>>sizeSecond;
    if(sizeFirst==0 || sizeSecond==0) return 0;
    for(ll i=0;i<sizeFirst;i++){
        cin>>arr1[i];
    }for(ll i=0;i<sizeSecond;i++){
        cin>>arr2[i];
    }
    merge_sort(arr1,0,sizeFirst-1);
    merge_sort(arr2,0,sizeSecond-1);
    ll i=0,j=0;
    while(i<sizeFirst && j<sizeSecond){
        if(arr1[i]==arr2[j]){
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }else if(arr1[i]>arr2[j]){
            j++;
        }else{
            i++;
        }
    }
    return 0;
}