#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector< pair<ll, ll> > a(n);
    vector<ll> counte;

    for (auto &i : a) {
        cin >> i.first >> i.second;
        counte.push_back(i.first);
        counte.push_back(i.second + 1);
    }

    sort(counte.begin(), counte.end());
    counte.resize(unique(counte.begin(), counte.end()) - counte.begin());

    vector<int> count(2 * n);
    for (auto &i : a) {
        int posl = lower_bound(counte.begin(), counte.end(), i.first) - counte.begin();
        int posr = lower_bound(counte.begin(), counte.end(), i.second + 1) - counte.begin();
        count[posl]++;
        count[posr]--;
    }
    for (int i = 1; i < 2 * n; i++) {
        count[i] += count[i - 1];
    }

    vector<ll> ans(n + 1);
    for (int i = 1; i < 2 * n; i++) {
        ans[count[i - 1]] += counte[i] - counte[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}
