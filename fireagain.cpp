#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int k, dist1 = INT_MAX, dist2 = 0, x, a, b;
    cin >> k;
    pair<int, int> start[k], furthest;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        start[i] = make_pair(a, b);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dist1 = INT_MAX;
            for (int l = 0; l < k; l++) {
                dist1 = min(dist1, abs(start[l].first - i) + abs(start[l].second - j));
            }
            if (dist1 > dist2) {
                dist2 = dist1;
                furthest = make_pair(i, j);
            }
        }
    }
    if (furthest.first == 0) {
        cout << start[0].first << " " << start[0].second;
    }
    else cout << furthest.first << " " << furthest.second;
}
