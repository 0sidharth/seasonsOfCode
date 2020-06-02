#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSUtil(int u, vector<int> adj[],
                    bool visited[])
{
    visited[u] = true;
    cout << u << " ";
    for (int i = 0; i < adj[u].size(); i++)
        if (visited[adj[u][i]] == false)
            DFSUtil(adj[u][i], adj, visited);
}

void connectedComponents(vector<int> adj[], int V)
{
    bool *visited = new bool[V];
    for(int v = 0; v < V; v++)
        visited[v] = false;

    for (int v = 0; v < V; v++)
    {
        if (visited[v] == false)
        {
            DFSUtil(v, adj, visited);

            cout << "\n";
        }
    }
    delete[] visited;
}

/*void DFS(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    for (int u = 0; u < V; u++)
        if (visited[u] == false)
            DFSUtil(u, adj, visited);
}*/

int main() {
    int n, m, x;
    cin >> n >> m;
    vector<int> v;
    vector<int> adj[m];
    set<int> value;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        addEdge(adj, a - 1, b - 1);
        cerr<<"here";
/*        value.insert(v[a].first);
        value.insert(v[b].first);
        v[a].second = 1;
        v[b].second = 1;
        if (v[a] < 0 && v[b] < 0) {
            if (v[a] == v[b])
            continue;
            else {
                if (v[-v[a]] <= v[-v[b]]) {
                    v[-v[b]] = v[a];
                }
                else {
                    v[-v[a]] = v[b];
                }
            }
        }
        else if (v[a] < 0) {
            if (v[-v[a]] <= v[b]) {
                v[b] = v[a];
            }
            else {
                v[-v[a]] = 0 - v[b];
                v[a] = 0 - v[b];
            }
        }
        else if (v[b] < 0) {
            if (v[-v[b]] <= v[a]) {
                v[a] = v[b];
            }
            else {
                v[-v[b]] = 0 - v[a];
                v[b] = 0 - v[a];
            }
        }
        else {
            if (v[a] <= v[b]) {
                v[b] = 0 - a;
            }
            else {
                v[a] = 0 - b;;
            }
        }*/
    }
    connectedComponents(adj, m);
/*    long long ans = *value.begin();
    for (int i = 1; i <= n; i++) {
        if (v[i].second == 0) {
            ans += v[i].first;
        }
    }
    cout << ans << endl;*/
}
