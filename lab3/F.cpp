#include <iostream>
#include <vector>

using namespace std;
//run id:2452

int main(){
int n,k,sum=0,count=0;
cin>>n;
vector<int> vec;
for(int i=0;i<n;i++){
    cin>>k;
    vec.push_back(k);
}
cin>>n;
for(int i=0;i<n;i++){
    cin>>k;
    for(int j=0;j<vec.size();j++){
        if(k>=vec[j]){
            count++;
            sum+=vec[j];
        }
    }
   cout<<count<<" "<<sum<<endl; 
   sum=0;
   count=0;
}

    
}