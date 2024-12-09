#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
typedef long long ll;
using namespace std;
ll flr(ll x, int i) {
    return x & ~ ((1ll<<i) - 1);
}
ll acc(ll x, int i) { // the number of integers in [0,x) which has i-th bit
    ll y = flr(x, i);
    ll z = flr(x, i+1);
    return z/2 + (z == y ? 0 : x - y);
}
int main() {
    while (true) {
        // input
        int n; cin >> n;
        if (n == 0) break;
        vector<ll> k(n); repeat (i,n) cin >> k[i];
        // trivial
        bool is_trivial = false; // due to B muse \le 10^{18}
        if (60 < n) is_trivial = true;
        for (ll it : k) {
            if (1000000000000000000ll < it) is_trivial = true;
        }
        // compute
        vector<pair<ll, ll> > cands;
        for (int delta : { -1, 0, 1 }) {
            ll l = k[0] * 2 + delta;
            if (l <= 0) {
                continue;
            } else if (l == 1) {
                ll a = 0;
                repeat (i,n) {
                    if (k[i]) a += 1ll<<i;
                }
                cands.emplace_back(a, a);
            } else {
                int i = n-1;
                ll base = 0;
                while ((k[i] == 0 or k[i] == l) and i != 0) {
                    if (k[i] == l) base += 1ll<<i;
                    -- i;
                }
                ll b = (1ll<<i) + k[i] - 1 + base;
                ll a = b - l + 1;
                if (a <= 0) continue;
                cands.emplace_back(a, b);
            }
        }
        vector<pair<ll, ll> > ans;
        for (auto it : cands) {
            ll a, b; tie(a, b) = it;
            bool is_valid = true;
            if (1000000000000000000ll < b) is_valid = false;
            repeat (j,n) {
                if (acc(b+1, j) - acc(a, j) != k[j]) {
                    is_valid = false;
                    break;
                }
            }
            if (is_valid) {
                ans.emplace_back(a, b);
            }
        }
        // output
        switch (ans.size()) {
            case 0: cout << "None" << endl; break;
            case 1: cout << ans[0].first << ' ' << ans[0].second << endl; break;
            default: cout << "Many" << endl; break;
        }
    }
    return 0;
}