#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[15];
int b[15];
int c[15][15];

int need;
void go(int ind) {
    set<int> bad;
    forn(i, ind) {
        bad.insert(a[i]);
        forn(j, i) {
            bad.insert(a[i] + a[j]);
        }
    }
    int ways = 0;
    int beg = 1;
    if (ind > 0) {
        beg = a[ind - 1];
    }
    for (int j = beg; ; ++j) {
        if (bad.count(j)) {
            continue;
        }
        bool ok = true;
        forn(i, ind) if (bad.count(a[i] + j)) {
            ok = false;
            break;
        }
        if (!ok) {
            continue;
        }
        ++ways;
        a[ind] = j;
        if (ind == need - 1) {
            if (a[ind] + a[ind - 1] < b[ind] + b[ind - 1]) {
                memcpy(b, a, sizeof b);
            }
        } else {
            go(ind + 1);
        }
        if (ways == 3) {
            break;
        }
    }
}

LL ans[10][10];

int main() {
    for (need = 1; need <= 9; ++need) {
        forn(i, need) b[i] = 1234;
        go(0);
        forn(i, need) c[need][i] = b[i];
        int cur = 1 + b[need - 1];
        if (need > 1) {
            cur += b[need - 2];
        }
    }

    cin >> n;
    LL mul = 1;
    for (int i = n - 1; i >= 1; --i) {
        forn(j, i) {
            ans[i][j] = ans[j][i] = c[i][j] * mul;
        }
        if (i > 1) {
            mul *= c[i][i - 2] + c[i][i - 1] + 1;
        }
    }
    forn(i, n) {
        forn(j, n) cout << ans[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
