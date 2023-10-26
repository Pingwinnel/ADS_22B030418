#include <iostream>
#define ll long long int
using namespace std;
//run id:
ll arr1[9999999];
void merge(ll arra[],ll left,ll left_end,ll right_start,ll right){

    int Left_arr[left_end+1-left], Right_arr[right+1-right_start];

    for (int i = 0; i < left_end+1-left; i++)
        Left_arr[i] = arra[left + i];
    for (int j = 0; j < right+1-right_start; j++)
        Right_arr[j] = arra[right_start + j];
    ll i=0,j=0,k=left;
    while(i<left_end+1-left && j<right+1-right_start){
        if(Left_arr[i]>Right_arr[j]){
            arra[k]=Right_arr[j];
            j++;
        }else{
            arra[k]=Left_arr[i];
            i++;
        }
        k++;
    }
    while(i<left_end+1-left){
        arra[k]=Left_arr[i];
        i++;
        k++;
    }
    while(j<right+1-right_start){
        arra[k]=Right_arr[j];
        j++;
        k++;
    }

}

void merge_sort(ll arra[] , ll left , ll right){

    if (right == left) {  
        return;
    }

    merge_sort(arra , left , left+(right-left)/2 );
    merge_sort(arra,(left+(right-left)/2)+1,right);
    merge(arra,left,left+(right-left)/2,(left+(right-left)/2)+1,right);
}


int main() {
    ll size1,size2;
    cin>>size1;
    ll Left_arr[size1];

    for (int i = 0; i < size1; i++){
        cin>>Left_arr[i];
    }
    cin>>size2;
    ll Right_arr[size2];
    for (int i = 0; i < size2; i++){
        cin>>Right_arr[i];
    }
    ll i=0,j=0;
    while(i<size1 && j<size2){
        if(Left_arr[i]>Right_arr[j]){
            cout<<Right_arr[j]<<" ";
            j++;
        }else{
            cout<<Left_arr[i]<<" ";
            i++;
        }
    }
    while(i<size1){
        cout<<Left_arr[i]<<" ";
        i++;
    }
    while(j<size2){
        cout<<Right_arr[j]<<" ";
        j++;
    }

    return 0;
}