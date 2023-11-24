#include <bits/stdc++.h>
using namespace std;
//run id:2306

int kmp(string str, int m){
    int n = str.length();
    int lim = 0;
    vector<int> vec(n, 0);

    for(int i = 1; i < n; i++){
        int j = vec[i-1];
        while(j > 0 && str[j] != str[i]){
            j = vec[j-1];
        }
        if(str[j]==str[i]) {
            vec[i] = ++j;
            if(lim <j && i >= m)
                lim = j;
        }
    }

    return lim;
}

int main(){
    string a, b, temp;

    getline(cin, a);
    getline(cin, b);

    temp = a;
    int m = b.length();

    int response = 1;

    while(a.length() < b.length()){
        a += temp;
        response++;
    }

    int limit = 0;
    int curr = 0;

    while(true){
        curr = kmp(b + "#" + a, m);
        if(limit < curr)
            limit = curr;
        else
            break;
        if(curr == m){
            cout<<response;
            return 0;
        }
        a += temp;
        response++;
    }

    cout<<-1;
    return 0;
}