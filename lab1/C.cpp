#include <bits/stdc++.h>
using namespace std;

int main(){
    string g,h,gf,hf;
    int remove_num;
    cin>>g>>h;
    for(int i=0;i<g.size();i++){
        if(g[i]=='#' and i!=0){
            for(int j=i;j>=0;j--){
                if(g[j]!='#' and g[j]!='0'){
                    g[j]='0';
                    break;
                }
            }
        }
    }
    for(int i=0;i<h.size();i++){
        if(h[i]=='#' and i!=0){
            for(int j=i;j>=0;j--){
                if(h[j]!='#' and h[j]!='0'){
                    h[j]='0';
                    break;
                }
            }
        }
    }
    for(int i=0;i<g.size();i++){
        if(g[i]=='#' or g[i]=='0'){
            continue;
        }
        else{
            gf.push_back(g[i]);
        }
    }
    for(int i=0;i<h.size();i++){
         if(h[i]=='#' or h[i]=='0'){
            continue;
        }
        else{
            hf.push_back(h[i]);
        }
    }
    if(gf==hf){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }


}