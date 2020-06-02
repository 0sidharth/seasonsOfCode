#include <bits/stdc++.h>

using namespace std;

struct pt {
    long long x, y;
};

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull(vector<pt>& a) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}

long long int area(const vector<pt>& fig) {
    long long int res = 0;
    for (unsigned i = 0; i < fig.size(); i++) {
        pt p = i ? fig[i - 1] : fig.back();
        pt q = fig[i];
        res += (p.x - q.x) * (p.y + q.y);
    }
    return fabs(res);
}

int main() {
    int T;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
//    T = 313;
    while (T--) {
        int n;
        cin >> n;
        long long int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<pt> ar;
        struct pt temp;
        long long mx = a[0], mn = a[0];
        for (int i = 1; i < n; i++) {
            struct pt temp;
            temp.x = mn;
            temp.y = a[i];
            ar.push_back(temp);
            if (mx != mn) {
                temp.x = mx;
                ar.push_back(temp);
            }
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);
        }
        convex_hull(ar);
        long long ans = area(ar);
        cout << ans << endl;
    }
}
