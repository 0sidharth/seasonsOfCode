#include <bits/stdc++.h>

using namespace std;

bool isPalin(string s) {
    bool ret = true;
    int n = s.length();
    for (int i = 0; i <= n / 2; i++) {
        if (s[i] != s[n - 1 - i]) {
            ret = false;
            break;
        }
    }
    return ret;
}

int main() {
    int T;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--) {
        string s, a, b;
        cin >> s;
        int n = s.length();
        int ans = 0;
        if (n & 1 ^ 1) {
            if (isPalin(s)) {
                ans = 3;
                for (int i = n / 2 - 1; i >= 1; i--) {
                    if (s[i] == s[i - 1]) {
                        ans += 2;
                    }
                    else break;
                }
            }
            else {
                ans = 0;
                if (s[0] != s[n - 1]) {
                    if (isPalin(s.substr(0, n - 2))) {
                        ans += 1;
                    }
                    if (isPalin(s.substr(1, n - 1))) {
                        cout << s.substr(1, n - 1);
                        ans += 1;
                    }
                }
                else {
                    int i = 0;
                    while (s[i] == s[n - 1 - i]) {
                        i++;
                    }
                    if (isPalin(s.substr(i, n - 1 - 2 * i))) {
                        ans += 1;
                        for (int k = i - 1; k >= 0; k--) {
                            if (s[n - 1 - i] == s[k]) {
                                ans++;
                            }
                            else break;
                        }
                    }
                    if (isPalin(s.substr(i + 1, n - 1 - 2 * i))) {
                        ans += 1;
                        for (int k = n - i; k < n; k++) {
                            if (s[i] == s[k]) {
                                ans++;
                            }
                            else break;
                        }
                    }
                }
            }
        }
        else {
            if (isPalin(s)) {
                ans = 2;
                for (int i = n / 2; i >= 1; i--) {
                    if (s[i] == s[i - 1]) {
                        ans += 2;
                    }
                    else break;
                }
            }
            else {
                ans = 0;
                if (s[0] != s[n - 1]) {
                    if (isPalin(s.substr(0, n - 2))) {
                        ans += 1;
                    }
                    if (isPalin(s.substr(1, n - 1))) {
                        cout << s.substr(1, n - 1);
                        ans += 1;
                    }
                }
                else {
                    int i = 0;
                    while (s[i] == s[n - 1 - i]) {
                        i++;
                    }
                    if (isPalin(s.substr(i, n - 1 - 2 * i))) {
                        ans += 1;
                        for (int k = i - 1; k >= 0; k--) {
                            if (s[n - 1 - i] == s[k]) {
                                ans++;
                            }
                            else break;
                        }
                    }
                    if (isPalin(s.substr(i + 1, n - 1 - 2 * i))) {
                        ans += 1;
                        for (int k = n - i; k < n; k++) {
                            if (s[i] == s[k]) {
                                ans++;
                            }
                            else break;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
