// https://www.codechef.com/problems/ADAKNG
#include <bits/stdc++.h>

int main() {
    clock_t tStart = clock();
    int t, r, c, k, width, height;
    std::cin >> t;
    while (t--) {
        std::cin >> r >> c >> k;
        if (r - k <= 0) {
            if (c - k <= 0) {
                if (r + k > 8) {
                    width = 8;
                    if (c + k > 8) {
                        height = 8;
                    }
                    else {
                        height = c + k;
                    }
                }
                else {
                    width = r + k;
                    if (c + k > 8) {
                        height = 8;
                    }
                    else {
                        height = c + k;
                    }
                }
            }
            else {
                if (r + k > 8) {
                    width = 8;
                    if (c + k > 8) {
                        height = 8 - c + k + 1;
                    }
                    else {
                        height = 2 * k + 1;
                    }
                }
                else {
                    width = r + k;
                    if (c + k > 8) {
                        height = 8 - c + k + 1;
                    }
                    else {
                        height = 2 * k + 1;
                    }
                }
            }
        }
        else {
            if (c - k <= 0) {
                if (r + k > 8) {
                    width = 8 - r + k + 1;
                    if (c + k > 8) {
                        height = 8;
                    }
                    else {
                        height = c + k;
                    }
                }
                else {
                    width = 2 * k + 1;
                    if (c + k > 8) {
                        height = 8;
                    }
                    else {
                        height = c + k;
                    }
                }
            }
            else {
                if (r + k > 8) {
                    width = 8 - r + k + 1;
                    if (c + k > 8) {
                        height = 8 - c + k + 1;
                    }
                    else {
                        height = 2 * k + 1;
                    }
                }
                else {
                    width = 2 * k + 1;
                    if (c + k > 8) {
                        height = 8 - c + k + 1;
                    }
                    else {
                        height = 2 * k + 1;
                    }
                }
            }
        }
        std::cout << width * height << std::endl;
    }
    printf ("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}
