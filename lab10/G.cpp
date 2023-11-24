#include <iostream>
#include <cmath>
#include <vector>

#define ll long long int

using namespace std;
//run id:5073
const int q = 1e9 + 7;
const ll P = 29;

ll Hash(const string& str, int start, int end) {
    ll hashCode = 0;
    for (int i = start; i <= end; i++) {
        hashCode = (hashCode * P + (str[i] - 'a' + 1)) % q;
    }
    return hashCode;
}

int main() {
    string str;
    cin >> str;

    int size;
    cin >> size;

    vector<int> cnt(size, 0);

    for (int i = 0; i < size; i++) {
        int l, r;
        cin >> l >> r;
        int powNum=int(pow(P,(r-l)));
        ll hashSearch = Hash(str, l - 1, r - 1);
        ll hashStr = Hash(str, 0, r - l);

        for (int j = 0; j < str.size() - (r - l); j++) {
            if (hashStr == hashSearch) {
                cnt[i]++;
            }
            hashStr = ((hashStr - (str[j] - 'a' + 1) * powNum) * P + (str[j + (r - l + 1)] - 'a' + 1)) % q;
        }

        if (cnt[i] == 0) {
            cout << 1 << endl;
        } else {
            cout << cnt[i] << endl;
        }
    }

    return 0;
}