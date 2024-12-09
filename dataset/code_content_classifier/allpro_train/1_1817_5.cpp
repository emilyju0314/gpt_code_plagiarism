#include <bits/stdc++.h>
using namespace std;

#define en '\n'
using ll = long long;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vec<vec<T>>;
#define REP(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define all(hoge) hoge.begin(), hoge.end()
constexpr ll MOD = 1000000007;

class Combination {
  public:
    vec<ll> fact, finv;
    ll mod;
    Combination(ll n, ll _mod) {
        mod = _mod;
        fact.resize(n + 1);
        fact[0] = 1;
        REP(i, n) {
            fact[i + 1] = (fact[i] * (i + 1LL)) % mod;
        }
        finv.resize(n + 1);
        finv[n] = mod_inv(fact[n]);
        for(int i = n; i > 0; i--) {
            finv[i - 1] = finv[i] * i % mod;
        }
    }
    ll mod_inv(ll x) {
        ll n = mod - 2;
        ll res = 1LL;
        while(n > 0) {
            if(n & 1)
                res = res * x % mod;
            x = x * x % mod;
            n >>= 1;
        }
        return res;
    }
    ll nCr(ll n, ll r) {
        if(n < r or n < 0 or r < 0)
            return 0;
        return fact[n] * finv[r] % mod * finv[n - r] % mod;
    }
};

Combination com(101010, MOD);
ll pow2[101010];

void solve(int n) {
    vec<int> a(n), in(n);
    REP(i, n) {
        cin >> a[i];
        a[i]--;
        in[a[i]]++;
    }

    vec<int> used(n, -1);
    int con = 0;
    int con2 = 0;
    int con3 = 0;
    REP(i, n) {
        if(in[i] >= 3) {
            cout << 0 << en;
            return;
        } else if(in[i] == 2 and a[a[i]] != i) {
            cout << 0 << en;
            return;
        }
    }
    REP(i, n) {
        if(used[i] != -1)
            continue;
        used[i] = i;
        if(in[i] == 1 and a[a[i]] == i and in[a[i]] == 1) {
            con++;
            con2++;
            used[a[i]] = i;
            continue;
        }

        int v = i;
        while(true) {
            v = a[v];
            if(used[v] == i) {
                if(a[a[v]] == v) {
                    con++;
                    con3++;
                    used[v] = i;
                    break;
                }
                cout << 0 << en;
                return;
            }
            if(used[v] != -1)
                break;
            used[v] = i;
        }
    }
    //cout << con2 << " " << con3 << en;

    ll ans = 0;
    REP(k, con2 / 2 + 1) {
        int l = con2 - 2 * k;
        if(l > con3 + 1)
            continue;
        //cout << k << " " << l << " " << com.nCr(k + con3, con3) << " " << com.nCr(con3 + 1, l) % MOD * (k + con3 + 1) << en;
        ans += com.nCr(k + con3, con3) * com.nCr(con3 + 1, l) % MOD * (k + con3 + 1) % MOD;
        ans %= MOD;
    }
    ans = ans * pow2[con] % MOD * com.fact[con3] % MOD * com.fact[con2] % MOD;
    cout << ans << en;
}

int main(void) {
    pow2[0] = 1;
    REP(i, 101000) {
        pow2[i + 1] = pow2[i] * 2 % MOD;
    }

    int n;
    while(cin >> n) {
        if(n == 0)
            break;
        solve(n);
    }
    return 0;
}

