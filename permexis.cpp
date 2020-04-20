// https://www.codechef.com/problems/PERMEXIS
#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    set<int> a;
    while (T--) {
        a.clear();
        int n, x;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x;
            a.insert(x);
        }
        set<int>::iterator one = prev(a.end());
        set<int>::iterator two = a.begin();
        if (a.size() == *one - *two + 1) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
}
