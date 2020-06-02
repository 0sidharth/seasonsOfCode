#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    void add(vector<int> b, int idx, int x) {
        while (idx <= N) {
            b[idx] += x;
            idx += idx & -idx;
        }
    }

    void range_add(l,r,x) {
        add(B1, l, x);
        add(B1, r+1, -x);
        add(B2, l, x*(l-1));
        add(B2, r+1, -x*r);
    }

    int sum(vector<int> b, int idx) {
        total = 0;
        while (idx > 0) {
            total += b[idx];
            idx -= idx & -idx;
        }
        return total;
    }

    int prefix_sum(int idx) {
        return sum(B1, idx)*idx -  sum(B2, idx);
    }

    int range_sum(int l, int r) {
        return prefix_sum(r) - prefix_sum(l-1);
    }
};

int main() {

}
