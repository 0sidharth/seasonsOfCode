#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll subCount[300001];
ll height[300001];
ll cost[300001];

void subTreeCounter(int a, int b, vector<pair<int, int> > adj[]) {
    subCount[a] = 1;
    for (int i = 0; i < adj[a].size(); i++) {
        int v = adj[a][i].first;
        int w = adj[a][i].second;
        if (v == b) continue;
        height[v] = height[a] + w;
        subTreeCounter(v, a, adj);
        subCount[a] += subCount[v];
    }
}

void costCalculater(int a, int b, vector<pair<int, int> > adj[], int n) {
    for (int i = 0; i < adj[a].size(); i++) {
        int v = adj[a][i].first;
        int w = adj[a][i].second;
        if (v == b) continue;
        ll temp = n - subCount[v];
        cost[v] = cost[a] - w*subCount[v] + w*temp;
        costCalculater(v, a, adj, n);
    }
}

int main() {
    int n, u, v, w;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<pair<int, int> > adj[n];
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    subTreeCounter(0, -1, adj);
    for (int i = 0; i < n; i++) {
        cost[0] += height[i];
    }
    costCalculater(0, -1, adj ,n);
    for (int i = 0; i < n; i++) {
        cout << cost[i] << " ";
    }
}
