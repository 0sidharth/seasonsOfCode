// https://codeforces.com/contest/1175/problem/D
#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long

using namespace std;

int main() {
    ll n, k, temp = 0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ll a[n];
    vector<ll> sum;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        temp += a[i];
        sum.push_back(temp);
    }
    sum.pop_back();
    sort(sum.begin(), sum.end());
    reverse(sum.begin(), sum.end());
    for (int i = 0; i < k - 1; i++) {
        temp += sum[i];
    }
    cout << temp << endl;
    return 0;;
}
