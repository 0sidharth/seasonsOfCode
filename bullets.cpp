#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a;
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            a.push_back(x);
        }
        bool flag = false;
        for (auto it = a.begin(); it != a.end(); it++) {
            if (count(a.begin(), a.end(), *it) % 2 != 0) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "Gaitonde\n";
        }
        else cout << "Isa\n";
    }
}
