#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define ll long long

vector<int> tree[int(10e5 + 1)];
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : tree[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort(vector<int> tree[], int n) {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
}

int main() {
    int n, m, p, q, a, b;
    cin >> n >> m >> p >> q;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
    }
    topological_sort(tree, n);
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[q] = 1;
    for (int i = n; i > 0; i--) {
        for (auto it = tree[i].begin(); it != tree[i].end(); it++) {
            dp[i] += dp[*it];
            dp[i] %= mod;
        }
    }
    cout << dp[p];
}

