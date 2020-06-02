#include <bits/stdc++.h>

using namespace std;

#define int unsigned long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n, z;
        cin >> n >> z;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort (arr, arr + n);
        int res = n * arr[0];
        if (z == 1) {
            for (int i = 1; i < n; i++) {
                res = min(res, (n - i) * arr[i]);
            }
            cout << res << endl;
        }
        else cout << 0 << endl;
    }
}
