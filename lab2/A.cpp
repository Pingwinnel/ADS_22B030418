#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,a,k;
    cin>>n;
    vector<int> vec;
    for(int i=0;i<n;i++){
        cin>>a;
        vec.push_back(a);
    }
    cin>>k;
    int max=INT32_MAX;
    for(int i=0;i<vec.size();i++)
    {
        if(abs(k-vec[i])<max)
        {
            max=abs(k-vec[i]);
            n=i;
        }
    }
    cout<<n;
}