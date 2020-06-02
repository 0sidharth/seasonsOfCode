#include <bits/stdc++.h>

#define  ll long long int

using namespace std;
ll getSum(ll BITree[],ll index) {
    ll sum = 0;
    while (index > 0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(ll BITree[], ll n, ll index,ll val) {
    while (index <= n) {
       BITree[index] += val;
       index += index & (-index);
    }
}

ll getInvCount(vector<ll> arr,ll n) {
    ll invcount = 0;
    ll maxElement = 0;
    for (ll i = 0; i < n; i++)
        if (maxElement < arr[i])
            maxElement = arr[i];
    ll BIT[maxElement + 1];
    for (ll i = 1; i <= maxElement; i++)
        BIT[i] = 0;
    for (ll i = n - 1; i >= 0; i--) {
        invcount += getSum(BIT, arr[i] - 1);
        updateBIT(BIT, maxElement, arr[i], 1);
    }
    return invcount;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        bool flag = false;
        for (int j = 0; j < n; j++) {
            ll x;
            cin >> x
            arr.push_back(x);
            if (!flag) {
                if (count(arr.begin(), arr.end(), x) > 1) {
                    flag = true;
                }
            }
        }
        cerr << "h";
        int initial = getInvCount(arr, n);
        if (k <= initial) {
            cout << initial - k << endl;
        }
        else {
            k -= initial;
            if (k & 1 && flag == false) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
    }
}
