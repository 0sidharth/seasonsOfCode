#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
//    std::cin >> t;
    t = 1;
    while (t--) {
        int n = 100000, index = 0, count = 0, sum = 0;
//        std::cin >> n;
        pair <int, int> arr[n];
        for (int i = 0; i < n; i++) {
            arr[i].first = (i + 1) * 10000;
//            std::cin >> arr[i].first;
            arr[i].second = i + 1;
        }
        std::sort(arr, arr + n);
        while (arr[n - 1].first >= 0) {
            while (arr[index].first - sum < 0) {
                index++;
            }
            arr[n - 1].first -= arr[index].second;
            sum += arr[index].second;
            count++;
        }
        std::cout << count << std::endl;
    }
}
