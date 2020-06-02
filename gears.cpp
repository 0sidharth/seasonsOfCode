#include <bits/stdc++.h>

using namespace std;


long long change[100100], color[100100], parent[100100], ranke[100100], val[100100], blocked[100100];
long long parity, n, m;

long long find_set(long long v) {
    if (parent[v] != v) {
        parent[v] = find_set(parent[v]);
    }
    color[v] ^= parity;
    parity ^= change[v];
    change[v] = parity;
    return parent[v];
}

void union_sets(long long a, long long b) {
    parity = 0;
    long long x = find_set(a);
    parity = 0;
    long long y = find_set(b);
    if (x == y) {
        if(color[a]==color[b]) {
            blocked[x] = 1;
        }
        return;
    }
    if (ranke[x] < ranke[y]) {
        swap(x, y);
    }
    parent[y] = x;
    ranke[x] += ranke[y];
    if (color[a] == color[b]) {
        change[y] = 1;
        color[y] ^= 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
        parent[i] = i;
        ranke[i] = 1;
        color[i] = change[i] = blocked[i] = 0;
        cin >> val[i];
    }
    for (long long i = 0; i < m; i++) {
        long long a, b, c, d;
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            val[b] = c;
        }
        else if (a == 2) {
            cin >> b >> c;
            union_sets(b, c);
        }
        else {
            cin >> b >> c >> d;
            parity = 0;
            long long x = find_set(b);
            parity = 0;
            long long y = find_set(c);
            if (x != y || blocked[x] || blocked[y]) {
                cout << 0 << endl;
            }
            else
            {
                long long num = val[b] * d * pow(-1, (color[b] ^ color[c]));
                long long denom = val[c];
                long long g = __gcd(abs(num), denom);
                num /= g;
                denom /= g;
                cout << num << "/" << denom << endl;
            }
        }
    }
}
