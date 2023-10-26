#include <iostream>
#include <map>
#define ll long long int
using namespace std;
//run id:2002



int main() {
    ll size,x;
    map<string,string> data;
    string oldName,newName;
    cin>>size;
    for(ll i=0;i<size;i++){
        cin>>oldName>>newName;
        data[oldName]=newName;
    }
    map <string,string> :: iterator it = data.begin();
    for (int i = 0; it != data.end(); it++, i++) {
        while(true){
        if( data.find(it->second)!=data.end() && it->first!=it->second){
            map <string, string> :: iterator full_name;
            full_name = data.find(it->second);
            data[it->first]=data[it->second];
            data.erase(full_name);}
        else{
            break;
        }
        }
    }
    cout<<data.size()<<endl;
    for (it = data.begin(); it !=data.end(); it++) {
        cout<<it->first<<" "<<it->second<<endl;
    }

}