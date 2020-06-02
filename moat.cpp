#include <bits/stdc++.h>

using namespace std;

int timer, l;
vector<int> tin, tout;
vector<vector<int> > up;

void dfs(int v, int p, vector<int> adj[]) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v, adj);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root, int n, vector<int> adj[]) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root, adj);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, u, vv, a, b, r, x, y, z;
    cin >> n >> q;
    vector<int> v[n];
    stack<int> path;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> vv;
        u--;
        vv--;
        v[u].push_back(vv);
        v[vv].push_back(u);
    }
    preprocess(0, n, v);
    for (int i = 0; i < q; i++) {
        cin >> a >> b >> r;
        a--;
        b--;
        r--;
        x = lca(a, r);
        y = lca(r, b);
        z = lca(a, b);
        if (y == z && x == r || (x == z && y == r)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}

