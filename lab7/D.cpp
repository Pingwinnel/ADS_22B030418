#include <iostream>
#include <iomanip>
#define ll long long int
using namespace std;
//run id:
struct Student{
    string last_name;
    string first_name;
    double gpa;
};
Student arr1[999999];
void merge(Student arra[],ll left,ll left_end,ll right_start,ll right){
    Student LeftArr[left_end+1-left], RightArr[right+1-right_start];

    for (int i = 0; i < left_end+1-left; i++)
        LeftArr[i] = arra[left + i];
    for (int j = 0; j < right+1-right_start; j++)
        RightArr[j] = arra[right_start + j];
    ll i=0,j=0,mergeIndex=left;
    while(i<left_end+1-left && j<right+1-right_start){
        if(LeftArr[i].gpa > RightArr[j].gpa){
            arra[mergeIndex]=RightArr[j];
            j++;
        }else if((LeftArr[i].gpa == RightArr[j].gpa) && (LeftArr[i].last_name > RightArr[j].last_name)){
            arra[mergeIndex]=RightArr[j];
            j++;  
        }else if((LeftArr[i].gpa == RightArr[j].gpa) &&  (LeftArr[i].last_name == RightArr[j].last_name) && (LeftArr[i].first_name > RightArr[j].first_name)){
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
void merge_sort(Student arra[],ll left,ll right){
    if(right==left){
        return;
    }
    merge_sort(arra,left,left+(right-left)/2);
    merge_sort(arra,(left+(right-left)/2)+1,right);
    merge(arra,left,left+(right-left)/2,(left+(right-left)/2)+1,right);
}

int main() {
   ll size=0,credit=0,numSubjects=0,totalCredits=0;
    double gpa=0.00,totalGpa=0.00,acum_gpa=0.00;
    string first_name,lastName,gpaLetter;
    cin>>size;
    for(ll i=0;i<size;i++){
        cin>>lastName>>first_name>>numSubjects;
        for(ll j=0;j<numSubjects;j++){
            cin>>gpaLetter;
            cin>>credit;
            if(gpaLetter=="A+"){
                gpa=4.00;
            }else if(gpaLetter=="A"){
                gpa=3.75;
            }else if(gpaLetter=="B+"){
                gpa=3.50;
            }else if(gpaLetter=="B"){
                gpa=3.00;
            }else if(gpaLetter=="C+"){
                gpa=2.50;
            }else if(gpaLetter=="C"){
                gpa=2.00;
            }else if(gpaLetter=="D+"){
                gpa=1.50;
            }else if(gpaLetter=="D"){
                gpa=1.00;
            }else if(gpaLetter=="F"){
                gpa=0;
            }
            acum_gpa+=gpa*credit*1.00;
            totalCredits+=credit;

        }
        totalGpa=acum_gpa*1.00/totalCredits*1.00;
        arr1[i]={lastName,first_name,totalGpa};
        acum_gpa=0;
        totalGpa=0;
        totalCredits=0;
    }
    merge_sort(arr1,0,size-1);
    for(ll i=0;i<size;i++){
        cout<<fixed<<setprecision(3)<<arr1[i].last_name<<" "<< arr1[i].first_name<<" "<<arr1[i].gpa<<endl;
    }
}