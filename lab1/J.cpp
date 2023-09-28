#include <iostream>
#include <deque>
using namespace std;
//run id :6989
int main(){
    deque<int> que;
    string str; 
    int b;
    int multipl=1;
    while(getline(cin, str)){
        b=0;
        for(int i=str.size()-1;i>=2;i--){
            b+=(int(str[i])-'0') * multipl;
            multipl=multipl*10;
        }
        if (str[0]=='+'){
            que.push_front(b);
        }
        else if(str[0]=='-'){
            que.push_back(b);
        }
        else if(str[0]=='*'){
            if(que.size()==1){
                cout << (que.front()+que.back()) << endl;
                que.pop_front();
                continue;
            }

            else if(que.size()!=0){
                cout << que.front()+que.back() << endl;
                que.pop_front();
                que.pop_back();
                continue;
            }
            cout << "error" << endl;
        }
        multipl=1;
    }
}