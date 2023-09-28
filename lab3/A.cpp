#include <iostream>
#include <queue>
using namespace std;



int main(){
    queue<int> que; 

    int num;
    cin >> num;
    
    int arrnum[num];
    for(int i=0;i<num;i++){
        cin >> arrnum[i];
    }
    
    for(int j=0;j<num;j++){
        int n;
        n=arrnum[j];
        if(n==1){
            cout <<'1';
            cout << endl;
            continue;
        }
        int k=n;
        while(n>1){
            if(k==n){
                que.push(n);
            }
            
                for(int i=1;i<n;i++){
                    if(i==1){
                        que.push(n-1);
                    }
                    int u = que.front();
                    que.pop();
                    que.push(u);
                    
                }
            
            n--;
        }
        int app[que.size()];
        int count=que.size();
        int u=count;
            while(!que.empty()){
                app[count]=que.front();
                que.pop();
                count--;

            } 
            for(int i=1;i<=u;i++){
                cout << app[i] << " ";
            }
            cout << endl;
            }
}