// https://www.codechef.com/JULY17/problems/IPCTRAIN
#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define ll long long

struct teachers {
    ll day;
    ll lecture;
    ll curse;
    ll index;
};

bool check(teachers a, teachers b) {
    return a.curse > b.curse;
}

bool checkday(teachers a, teachers b) {
    return a.day < b.day;
}

struct checkDay {
    bool operator()(teachers const& a, teachers const& b) {
        return a.curse < b.curse;
    }
};

int main() {
    int t;
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--) {
        ll n, d;
        ll curseTotal = 0, curseTotalSaved = 0;
        cin >> n >> d;
        teachers a[n];
        for (ll i = 0; i < n; i++) {
            cin >> a[i].day >> a[i].lecture >> a[i].curse;
            a[i].index = i;
            curseTotal += a[i].lecture * a[i].curse;
        }
        sort (a, a + n, checkday);
        for (ll i = 0; i < n; i++) {
            a[i].index = i;
        }
/*        for (int i = 0; i < n; i++) {
            cout << daywise[i].index << " " << daywise[i].lecture << " " << daywise[i].day;
        }*/
        priority_queue < teachers, vector<teachers>, checkDay > curseDayWise;
        ll count = 0;
        for (int i = 1; i <= d; i++) {
            while (count < n && a[count].day == i) {
                curseDayWise.push(a[count]);
                count++;
            }
            if (curseDayWise.empty()) continue;
//            cerr  << a[curseDayWise.top().index].lecture << " "  << curseDayWise.top().index;
            curseTotalSaved += curseDayWise.top().curse;
            a[curseDayWise.top().index].lecture = a[curseDayWise.top().index].lecture - 1;
//            cerr << " " <<  a[curseDayWise.top().index].lecture << "<<<";
            if (a[curseDayWise.top().index].lecture == 0) {
                curseDayWise.pop();
            }
//            cerr << curseTotalSaved << " " << curseDayWise.top().lecture << endl;
        }
        cout << curseTotal - curseTotalSaved << endl;
    }
}
