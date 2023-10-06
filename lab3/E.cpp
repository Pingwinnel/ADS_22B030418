#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;

//run id:3493

bool can_enclose_sheeps(ll sheep_areas[][4],ll n,ll sidelen,ll k) {
    ll count = 0;
    for (ll i = 0; i < n; i++) {
        ll maxX = sheep_areas[i][2];
        ll maxY = sheep_areas[i][3];
        if (maxX <= sidelen && maxY <= sidelen) {
            count++;
        }
    }
    return count >= k;
}

ll find_minimum_square_side_length(ll n, ll k, ll sheep_areas[][4]) {
    ll left = 0;
    ll right = 999999999;  

    while (left < right) {
        ll mid = (left + right) / 2;
        if (can_enclose_sheeps(sheep_areas, n, mid, k)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    ll n, k;
    cin >> n >> k;
    ll sheepArea[n][4];

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < 4; j++) {
            cin >> sheepArea[i][j];
        }
    }

    ll ans = find_minimum_square_side_length(n, k, sheepArea);
    cout << ans << endl;

    return 0;
}