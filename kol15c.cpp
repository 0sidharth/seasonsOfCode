#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, u;
    cin >> n >> u;
    int arr[200001] = {};
    int val = sqrt(u);
    int a, b;
    int c[200001] = {};
    vector<int> queries[200001];
    for (int i = 0; i < u; i++) {
        cin >> a >> b;
        if (a > val) {
            for (int j = b; j <= n; j += a) {
                arr[j]++;
            }
        }
        else {
            queries[a].push_back(b);
        }
    }
    for (int i = 1; i <= val; i++) {
        memset(c, 0, sizeof(c));
        for (int j = 0; j < queries[i].size(); j++) {
            c[queries[i][j]]++;
        }
        if (queries[i].size() == 0) continue;
        for (int j = 1; j <= n; j++) {
            arr[j] += c[j];
            c[i + j] += c[j];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
}
