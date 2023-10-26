#include <iostream>
#include <iomanip>
#define ll long long int
using namespace std;
//run id:2001
ll heap_size;
struct Student{
    string last_name;
    string first_name;
    double gpa;
};
Student arrSrudents[1000000];

int parent(int i){
    return (i / 2);
}
int leftChild(int i){
    return (2 * i);
}
int rightChild(int i){
    return ((2 * i) + 1);
}
void heapifyUp(Student arr[],ll i){
    while (i > 1 && arr[parent(i)].gpa >= arr[i].gpa) {
        if(arr[parent(i)].gpa > arr[i].gpa){
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }else if((arr[parent(i)].gpa == arr[i].gpa) && (arr[parent(i)].last_name > arr[i].last_name)){
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }else if((arr[parent(i)].gpa == arr[i].gpa) && (arr[parent(i)].last_name == arr[i].last_name) && (arr[parent(i)].first_name > arr[i].first_name)){
            swap(arr[parent(i)], arr[i]);
            i = parent(i);            
        }else{
            break;
        }
    }
}
void heapifyDown(Student arr[],ll i){
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heap_size && (arr[l].gpa < arr[maxIndex].gpa
     || ((arr[l].gpa == arr[maxIndex].gpa) && (arr[l].last_name < arr[maxIndex].last_name))
     || (arr[l].gpa == arr[maxIndex].gpa) && (arr[l].last_name == arr[maxIndex].last_name) && (arr[l].first_name < arr[maxIndex].first_name))) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heap_size && (arr[r].gpa < arr[maxIndex].gpa
     || ((arr[r].gpa == arr[maxIndex].gpa) && (arr[r].last_name < arr[maxIndex].last_name))
     || (arr[r].gpa == arr[maxIndex].gpa) && (arr[r].last_name == arr[maxIndex].last_name) && (arr[r].first_name < arr[maxIndex].first_name))) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        swap(arr[i], arr[maxIndex]);
        heapifyDown(arr,maxIndex);
    }
}
void heapDel(ll index){
    swap(arrSrudents[heap_size],arrSrudents[index]);
    heap_size--;
    heapifyDown(arrSrudents,index);

}
int main() {
    ll size=0,credits=0,numSubjects=0,totalCredits=0;
    double gpa=0.00,total_gpa=0.00,acum_gpa=0.00;
    string firstName,last_name,gpaLetter;
    cin>>size;
    for(ll i=1;i<=size;i++){
        cin>>last_name>>firstName>>numSubjects;
        for(ll j=0;j<numSubjects;j++){
            cin>>gpaLetter;
            cin>>credits;
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
            acum_gpa+=gpa*credits*1.00;
            totalCredits+=credits;

        }
        total_gpa=acum_gpa*1.00/totalCredits*1.00;
        heap_size++;
        arrSrudents[heap_size]={last_name,firstName,total_gpa};
        heapifyUp(arrSrudents,heap_size);
        acum_gpa=0;
        total_gpa=0;
        totalCredits=0;
    }
    for(ll i=1;i<=size;i++){
        cout<<fixed<<setprecision(3)<<arrSrudents[1].last_name<<" "<< arrSrudents[1].first_name<<" "<<arrSrudents[1].gpa<<endl;
        heapDel(1);
    }
}
