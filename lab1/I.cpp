#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
//run id :6988
int main(){
    int num; cin >> num;
    string sum; cin >> sum;
    stack < char> st;
    int cntKasuragi=0;
    int cntSakur=0;
    bool flag=true;
    int cnt=0;
    for(int i=0;i<sum.size();i++){
        if(st.empty()){

            
            if(cnt>0){
                if(cntKasuragi>cntSakur){
                    st.push(sum[i]);
                    if(sum[i]=='K'){
                        cntKasuragi++;
                        
                    }
                    else if(sum[i]=='S'){
                        cntKasuragi--;
                        st.pop();
                        flag=false;
                    }
                }   
                else if(cntKasuragi<cntSakur){
                    st.push(sum[i]);
                    if(sum[i]=='S'){
                        cntSakur++;
                    }
                    else if(sum[i]=='K'){
                        cntSakur--;
                        st.pop();
                        flag=false;
                    }
                }
                else if(cntKasuragi==0 or cntSakur==0){
                    st.push(sum[i]);
                    if(sum[i]=='K'){
                        cntKasuragi++;

                    }
                    else if(sum[i]=='S'){
                        cntSakur++;
                        flag=false;
                    }
                }
                continue;
            }
            st.push(sum[i]);
            if(sum[i]=='K'){
                cntKasuragi++;
            }
            else{
                cntSakur++;
            }
        
            continue;
        }





        if(cntKasuragi>cntSakur){
            st.push(sum[i]);
            if(sum[i]=='K'){
                cntKasuragi++;
                
            }
            else if(sum[i]=='S'){
                cntKasuragi--;
                st.pop();
                flag=false;
            }
        }
        else if(cntKasuragi<cntSakur){
            st.push(sum[i]);
            if(sum[i]=='S'){
                cntSakur++;
            }
            else if(sum[i]=='K'){
                cntSakur--;
                st.pop();
                flag=false;
            }
        }
        else if(cntKasuragi==0 or cntSakur==0){
            st.push(sum[i]);
            if(sum[i]=='K'){
                cntKasuragi++;

            }
            else if(sum[i]=='S'){
                cntSakur++;
                flag=false;
            }
        }
        if(i==sum.size()-1 and flag==false){
            i=-1;
            sum="";
            int y=st.size();
            for(int j=0;j<y;j++){
                sum+=st.top();
                st.pop();
            }
            
            reverse(sum.begin(), sum.end());
            flag=true;
            cnt++;
        }

    }
    int cnS=0;
    int cnK=0;
    
    while(!st.empty()){
        if(st.top()=='S'){
            cnS++;
            st.pop();
            continue;
        }
        cnK++;
        st.pop();
    }
    if(cnK==0){
        cout << "SAKAYANAGI";
        return 0;
    }
    cout << "KATSURAGI";
}