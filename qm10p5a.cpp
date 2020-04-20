#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define mod 1000000007

int main() {
    int T;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        int count1 = 0, i, count2 = 0;
        i = 0;
        while ( i < n - 1) {
            if (str[i] != str[i + 1]) {
                count1++;
                i += 2;
            }
            else {
                i++;
            }
        }
        i = 1;
        while (i < n) {
            if (str[i] != str[i - 1]) {
                count2++;
                i += 2;
            }
            else {
                i++;
            }
        }
        cout << max(count1, count2) << endl;
    }
}
