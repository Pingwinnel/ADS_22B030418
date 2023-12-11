#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
//run id:1861
 
int n, g[502][502], x[502];
bool used[502];
int main() {
	int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
	vector <int> v;
    for(int k = 1; k <= n; k++) {
        used[x[k]] = true;
        int temp = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) { 
                g[i][j] = min(g[i][j], g[i][x[k]] + g[x[k]][j]);
                if(used[i] && used[j]) {
                    temp = max(g[i][j], temp);
                }
            }
        }
        v.push_back(temp);
    }

    for(int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}

	return 0;
}