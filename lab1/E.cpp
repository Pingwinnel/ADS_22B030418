#include <iostream>
#include <queue>

using namespace std;
int main(){
    queue <int> Borya;
    queue <int> Nurs;
    for(int i=0;i<5;i++){
        int n;
        cin >> n;
        Borya.push(n);
    }
    for(int i=0;i<5;i++){
        int n;
        cin >> n;
        Nurs.push(n);
    }
    int cnt=0;
    while(true)
    {
        if(Borya.empty()){
            cout << "Nursik " << cnt;
            return 0;
        }
        if(Nurs.empty()){
            cout << "Boris " << cnt;
            return 0;

        }
        if(cnt>=1000000){
            cout << "blin nichya";
            return 0;
        }
        
        if((Borya.front() == 9 && Nurs.front() == 0) or (Borya.front()<Nurs.front())){
            if(Borya.front() == 0 and Nurs.front() == 9){
                int a=Borya.front();
                Borya.push(a);
                Borya.pop();
                int c=Nurs.front();
                Nurs.pop();
                Borya.push(c);
                cnt++;
                continue;
            }
            int a=Borya.front();
            Nurs.push(a);
            Borya.pop();
            int c=Nurs.front();
            Nurs.pop();
            Nurs.push(c);
            cnt++;
        }
        else if((Borya.front() == 0 and Nurs.front() == 9) or (Borya.front()>Nurs.front())){
            if(Borya.front() == 9 and Nurs.front() == 0){
                int a=Borya.front();
                Nurs.push(a);
                Borya.pop();
                int c=Nurs.front();
                Nurs.pop();
                Nurs.push(c);
                cnt++;
                continue;
            }
            int a=Borya.front();
            Borya.push(a);
            Borya.pop();
            int c=Nurs.front();
            Nurs.pop();
            Borya.push(c);
            cnt++;
        }
        
        
}
}