#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int nax = 16;
int x[nax], y[nax], p[nax];
int n;
ll d[nax][2][1 << nax];

ll res[nax];
/// mimimum distance distance (x or y) to nearest line
/// denote that line pass through point in mask

inline void upd_min (ll &a, ll b) {
    a = min(a, b);
}

int main () {
    scanf("%d", &n);

    for (int i = 0 ; i < n ; ++ i)
        scanf("%d %d %d", x + i, y + i, p + i);

    for (int i = 0 ; i < n ; ++ i) {
        ll base = 1LL * p[i] * min(abs(x[i]) , abs(y[i]));
        for (int msk = 0 ; msk < (1 << n); ++ msk) {
            d[i][0][msk] = d[i][1][msk] = base;
            for (int j = 0 ; j < n ; ++ j) {
                if (msk >> j & 1) {
                    upd_min(d[i][0][msk], 1LL * p[i] * abs(x[j] - x[i]));
                    upd_min(d[i][1][msk], 1LL * p[i] * abs(y[j] - y[i]));
                }
            }
        }
    }

    fill(res, res + nax, LLONG_MAX);

    for (int m = 0 ; m < (1 << n) ; ++ m) {
        ll cur = LLONG_MAX;
        for (int sub = m; ; sub = (sub - 1) & m) {
            ll sum = 0;
            for (int k = 0 ; k < n ; ++ k)
                sum += min(d[k][0][sub], d[k][1][m ^ sub]);
            cur = min(cur, sum);
            if (sub == 0) break;
        }
        int pcnt = __builtin_popcount(m);
        res[pcnt] = min(res[pcnt], cur);
    }


    for (int i = 0 ; i <= n ; ++ i)
        printf("%lld\n", res[i]);


}
/*
    Good Luck
        -Lucina
*/
