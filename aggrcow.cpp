#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--) {
        int n, c;
        cin >> n >> c;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int diff[n - 1];
        for (int i = 0; i < n - 1; i++) {
            diff[i] = arr[i + 1] - arr[i];
        }
        int count = (arr[n - 1] - arr[0]) / (c - 1);
        int sum = 0, i = 0, diffyet, ans = arr[n - 1] - arr[0];
        vector<int> difference;
        while (i < n - 1) {
            sum += diff[i];
            if (sum > count) {
                if (sum == diff[i]) {
                    diffyet = diff[i];
                    sum = 0;
                }
                else {
                    diffyet = sum - diff[i];
                    sum = diff[i];
                }
                difference.push_back(diffyet);
            }
            else if (sum == count) {
                diffyet = sum;
                sum = 0;
//                ans = min(ans, diffyet);
                difference.push_back(diffyet);
            }
            i++;
        }
        if (sum) {
            difference.push_back(sum);
        }
        while (difference.size() > c - 1) {
            vector<int>::iterator low;
            int temp = 0;
            for (auto it = difference.begin() + 1; it != difference.end() - 1; it++) {
                if (*it > temp) {
                    low = it;
                }
            }
            if (*(low - 1) >= *(low + 1)) {
                *low += *(low + 1);
                difference.erase(low + 1);
            }
            else {
                *low += *(low - 1);
                difference.erase(low - 1);
            }
        }
        sort(difference.begin(), difference.end());
        cout << difference[0] << endl;
    }
}
