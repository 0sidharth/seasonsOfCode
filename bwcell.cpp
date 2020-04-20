#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int white = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'W') {
                white = i;
                break;
            }
        }
        if (white == s.length() - white - 1) {
            cout << "Chef\n";
        }
        else {
            cout << "Aleksa\n";
        }
    }
}
