#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007

ll noOfDigits(ll val) {
    ll temp = val, count = 0;
    while (temp > 0) {
        temp /= 10;
        count++;
    }
    return count;
}

int main() {
    int T;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--) {
        bool flag = false;
        ll x, y;
        cin >> x >> y;
        ll temp = x, count = 1;
        if (x % y == 0) {
            cout << x << endl;
            flag = true;
        }
        else {
            while (temp < 1e18) {
                temp *= 10;
                count *= 10;
//                cerr << temp / int(pow(10, noOfDigits(temp) - noOfDigits(x)) + 0.5) << endl;
                if (temp % y == 0 && temp > 0 && temp <= 1e18) {
                    flag = true;
                    cout << temp << endl;
                    break;
                }
                if (y - (temp % y) < count) {
                    flag = true;
                    temp += y - (temp % y);
                    if (temp > 0 && temp <= 1e18) {
                        cout << temp << endl;
                    }
                    else {
                        flag = false;
                    }
                    break;
                }
            }
        }
        if (!flag) {
            cout << "-1" << endl;
        }
    }
}
