// https://codeforces.com/contest/5/problem/C
#include <bits/stdc++.h>

using namespace std;

int main() {
    char s[1000001];
    cin >> s;
    int n = strlen(s);
    int count = 1, current = 0, sum = 0;
    stack<int> a;
    int d[1000100], c[1000100];
    for (int i = 0; i < n; i++) {
        d[i] = INT_MAX;
        c[i] = INT_MAX;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            a.push(i);
        }
        else {
            if (!a.empty()) {
                d[i] = a.top();
                a.pop();
                cout << d[i] - 1 << " " << d[i] << endl;
                c[i] = min(c[d[i] - 1], d[i]);
            }
        }
    }
    for (int i = 0; n; i++) {
        if (s[i] == ')') {
            if (i - c[i] + 1 > current) {
                count = 1;
                current = i - c[i] + 1;
            }
            else if (i - c[i] + 1 == current) {
                count++;
            }
        }
    }
    cout << current << " " << count << endl;
}

