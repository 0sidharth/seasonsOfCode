#include <bits/stdc++.h>

using namespace std;

long long longestIncreasing(vector<long long> &a, long long length, long long n) {
    long long  sum = 0, max_sum = LLONG_MIN, count = length, x;
    for (auto it = a.rbegin(); it != a.rend() && count > 0; it++) {
        sum += *it;
        if (sum > max_sum) {
            max_sum = sum;
            x = a.rend() - it;
            x -= n + 1;
            x = -x;
        }
        count--;
    }
    a.resize(n - x);
    return max_sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, split, sum = 0;
    cin >> n >> split;
    vector<long long> a;
    long long x;
    for (long long i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    while (split > 1) {
        long long sumer = 0, adder = LLONG_MIN, count = n + 1 - split, x;
        for (auto it = a.rbegin(); it != a.rend() && count > 0; it++) {
            sumer += *it;
            if (sumer > adder) {
                adder = sumer;
                x = a.rend() - it;
                x -= n + 1;
                x = -x;
            }
            count--;
        }
        a.resize(n - x);
        sum += split * adder;
//        sum += split * longestIncreasing(a, n + 1 - split, n);
        split--;
    }
    sum += accumulate(a.begin(), a.end(), 0);
    cout << sum << endl;
}
