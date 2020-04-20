// https://www.codechef.com/problems/ALTARAY
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
        bool flag = true;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < n - 1; i++) {
            int count = 1;
            while (i < n - 1 && ((arr[i] > 0 && arr[i + 1] < 0) || (arr[i] < 0 && arr[i + 1] > 0))) {
                count++;
                i++;
            }
            while (count--) {
                cout << count + 1 << " ";
            }
            if (i == n - 1) {flag = false;}
        }
        if (flag)
        cout << "1" << endl;
        else cout << endl;
    }
}
