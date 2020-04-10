#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define ll long long

struct teachers {
    int day;
    int lecture;
    int curse;
};

bool check(teachers a, teachers b) {
    return a.curse > b.curse;
}

int main() {
    int t;
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        teachers a[n];
        int schedule[d];
        int curseTotal = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i].day >> a[i].lecture >> a[i].curse;
        }
        for (int i = 0; i < d; i++) {
            schedule[i] = -1;
        }
        sort (a, a + n, check);
        for (int i = 0; i < n; i++) {
            if (a[i].lecture > d - a[i].day + 1) {
                curseTotal += (a[i].lecture - d + a[i].day - 1) * a[i].curse;
                a[i].lecture = d - a[i].day + 1;
            }
            int arrival = a[i].lecture;
            for (int j = 0; j < arrival; j++) {
                if (schedule[a[i].day - 1 + j] == -1) {
                    schedule[a[i].day - 1 + j] = i + 1;
                    a[i].lecture -= 1;
                }
            }
            curseTotal += a[i].lecture * a[i].curse;
        }
        cout << curseTotal << endl;
    }
}
