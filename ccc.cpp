#include <bits/stdc++.h>

using namespace std;

bool cmp(long long x, long long y) {
    return x > y;
}

double slope(long long dp2[], long long x1, long long x2) {
    return (dp2[x2] - dp2[x1]) * 1.0 / (x2 - x1);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t;
    cin >> t;
    while (t--) {
        long long n, z;
        cin >> n >> z;
        long long a[n + 1];
        for (long long i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort (a + 1, a + n + 1, cmp);
        long long dp[n + 1], dp2[n + 1], arr[n + 1] = {};
        long long ans = dp[0] = INT_MAX;
        long long one, two;
        for (long long i = 1; i <= n; i++) {
            dp[i] = i * a[i];
        }
        for (long long k = 2; k <= z; k++) {
            one = 1;
            two = 0;
            for(long long i = 0; i <= n; i++) {
                dp2[i] = dp[i];
            }

            for (long long i = 1; i <= n; i++) {
                while (one < two && slope(dp2, arr[two - 1], arr[two]) >= a[i]) {
                    two--;
                }
                dp[i] = dp2[arr[two]] + (i - arr[two]) * a[i];
                while (one < two && slope(dp2, arr[two - 1], arr[two]) >= slope(dp2, arr[two], i)) {
                    two--;
                }
                arr[++two] = i;
            }
        }
        for (long long i = 1; i <= n; i++) {
            ans = min(ans, dp[i]);
        }
        cout << ans << endl;
    }
}
