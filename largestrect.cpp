#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007

int main() {
    ll T = 1;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (1) {
        cin >> T;
        if (T == 0) break;
        ll x, n = T;
        vector<ll> heights;
        for (ll i = 0; i < n; i++) {
            cin >> x;
            heights.push_back(x);
        }
        stack<ll> s;
        ll start, area, max = 0, i = 0;
        while (i < heights.size()) {
            if (s.size() == 0 || heights[s.top()] <= heights[i]) {
                s.push(i++);
            }
            else {
                start = s.top();
                s.pop();
                ll width;
                if (s.size() == 0) {
                    width = i;
                }
                else {
                    width = i - s.top() - 1;
                }
                area = heights[start] * width;
                if (area > max) {
                  max = area;
                }
            }
        }
        while (s.size() != 0) {
            start = s.top();
            s.pop();
            ll width;
            if (s.size() == 0) {
                width = i;
            }
            else {
                width = i - s.top() - 1;
            }
            area = heights[start] * width;
            if (area > max) {
                max = area;
            }
        }
        cout << max << endl;
    }
}
