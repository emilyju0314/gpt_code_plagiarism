#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;

const int MAXN = 2007;
const int MOD = 1000 * 1000 * 1000 + 7;

ll fct[MAXN];

using arr = array<ll, MAXN>;
using varr = array<arr, 2>;

vector <int> e[MAXN];

arr f[MAXN];
int sz[MAXN];
arr fnt[MAXN];
arr fclosed[MAXN];

ll pw(ll a, int b = MOD - 2) {
    if (b == 0) {
        return 1;
    }

    ll v = pw(a, b / 2);
    v = (v * v) % MOD;
    if (b & 1) {
        v = (v * a) % MOD;
    }

    return v;
}

ll rev2 = pw(2);


arr mrg(int s1, const arr& a1, int s2, const arr& a2, int off = 0) {
    arr r;
    r.fill(0);
    for (int i = 0; i < s1; ++i) {
        for (int j = 0; j < min(s2, MAXN - 1 - s1 - off); ++j) {
            r[i + j + off] = (r[i + j + off] + a1[i] * a2[j]) % MOD;
        }
    }

    return r;
}



arr ad(const arr& a1, const arr& a2) {
    arr r;
    r.fill(0);
    for (int i = 0; i < MAXN; ++i) {
        r[i] = (a1[i] + a2[i]) % MOD;
    }

    return r;
}

arr d2(const arr& a1) {
    arr r;
    r.fill(0);
    for (int i = 0; i < MAXN; ++i) {
        r[i] = (a1[i] * rev2) % MOD;
    }

    return r;
}


arr m2(const arr& other) {
    return ad(other, other);
}

int main() {
#ifdef PAUNSVOKNO
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cout.tie(nullptr); cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        e[x].push_back(i);
    }

    for (int i = n; i >= 1; --i) {
        sz[i] = 1;
        auto& cf = f[i];
        auto& cfnt = fnt[i];
        auto& cclosed = fclosed[i];

        cfnt[0] = 1;

        for (int u : e[i]) {
            arr tot_sum = ad(f[u], fnt[u]);
            arr c_sum = ad(tot_sum, fclosed[u]);
            arr m_sum = ad(m2(fnt[u]), f[u]);
            
            arr nf = mrg(sz[i], cf, sz[u], c_sum);
            nf = ad(nf, mrg(sz[i], cfnt, sz[u], m_sum, 1));

            arr ncf = mrg(sz[i], cfnt, sz[u], c_sum);

            arr nclosed = mrg(sz[i], cclosed, sz[u], c_sum);
            nclosed = ad(nclosed, d2(mrg(sz[i], cf, sz[u], m_sum, 1)));

            cf = nf;
            cfnt = ncf;
            cclosed = nclosed;


            sz[i] += sz[u];
        }

    }

    ll ans = 0;
    ll mul = 1;
    
    fct[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fct[i] = (fct[i - 1] * i) % MOD;
    }

    auto tot = f[1];

    for (int i = 0; i <= n; ++i) {
        tot[i] = (tot[i] + fnt[1][i] + fclosed[1][i]) % MOD;
    }


    for (int i = 0; i < n; ++i) {
        ll vl = (tot[i] * fct[n - i]) % MOD;

        if (i & 1) {
            ans -= vl;
        } else {
            ans += vl;
        }

        ans %= MOD;
    }

    if (ans < 0) {
        ans += MOD;
    }

    cout << ans << "\n";
}