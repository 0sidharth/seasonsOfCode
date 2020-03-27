// https://codeforces.com/problemset/problem/841/B
#include <bits/stdc++.h>

int main() {
    int n, a;
    bool flag = 0;
    std::cin >> n;
    int odd = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        if (a % 2 == 1) {
            odd++;
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        std::cout << "First";
    }
    else {
        std::cout << "Second";
    }
}
