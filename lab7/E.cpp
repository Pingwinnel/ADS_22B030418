#include <iostream>
#define ll long long int
using namespace std;
//run id:
ll rowSize,columSize,x;
struct almas{
    string str="";
    ll sum=0;
};
almas arr1[5000];
void merge(almas arra[],ll left,ll left_end,ll right_start,ll right){

    almas LeftArr[left_end+1-left], RightArr[right+1-right_start];

    for (int i = 0; i < left_end+1-left; i++)
        LeftArr[i] = arra[left + i];
    for (int j = 0; j < right+1-right_start; j++)
        RightArr[j] = arra[right_start + j];
    ll i=0,j=0,mergeIndex=left;
    while(i<left_end+1-left && j<right+1-right_start){
        if(LeftArr[i].sum==RightArr[j].sum){
            if(LeftArr[i].str>RightArr[j].str){
                arra[mergeIndex]=RightArr[j];
                j++;
            }else{
                arra[mergeIndex]=LeftArr[i];
                i++;
            }
        }else if(LeftArr[i].sum<RightArr[j].sum){
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



void merge_sort(almas arra[],ll left,ll right){
    if(right==left){
        return;
    }
    merge_sort(arra,left,left+(right-left)/2);
    merge_sort(arra,(left+(right-left)/2)+1,right);
    merge(arra,left,left+(right-left)/2,(left+(right-left)/2)+1,right);
}


int main() {
    cin>>rowSize>>columSize;
    for(ll i=0;i<rowSize;i++){
        for(ll j=0;j<columSize;j++){
            cin>>x;
            arr1[i].str+=to_string(x);
            arr1[i].str+=" ";
            arr1[i].sum+=x;
        }
    }
    merge_sort(arr1,0,rowSize);
    for(ll i=0;i<rowSize;i++){
        cout<<arr1[i].str;
        cout<<endl;
    }
}