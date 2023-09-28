#include <iostream>
#include <stack>
using namespace std;

//run id :6973
int main(){
    string str;
    cin >> str;
    stack <char> stac;
    for(int i=0;i<str.size();i++){
        if(stac.empty()){
            stac.push(str[i]);
        }
        else if(!stac.empty()){
            if(str[i]==stac.top()){
                stac.pop();

            }
            else{
                stac.push(str[i]);
            }
        }
    }
    if(stac.empty()==true){
        cout << "Yes";
        return 0;
    }
    cout <<"No";
}