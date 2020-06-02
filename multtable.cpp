#include <bits/stdc++.h>

using namespace std;

#define ll long long

int f(ll k, ll n, ll m, ll mid) {
    ll count = 0;
    for (int i = 1; i <= n; i++) {
        count += min(m, mid / i);
    }
    return count >= k;
}

int main() {
    ll n, m, k;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    ll low = 1, high = 1ll*n*m, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (f(k, n, m, mid)) high = mid  - 1;
        else low = mid + 1;
    }
    cout << high + 1 << endl;
}
