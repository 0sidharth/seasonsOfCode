// https://www.codechef.com/problems/COMPILER
#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    cin.ignore();
    while (T--) {
        stack <char> a;
        int count = 0, max = 0;
        string line;
        getline(cin, line);
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '<') {
                a.push(line[i]);
            }
            else if (a.empty()) {
                max += 2 * count;
                count = 0;
                break;
            }
            else {
                count++;
                a.pop();
            }
        }
        max += count * 2;
        cout << max << endl;
    }
}
