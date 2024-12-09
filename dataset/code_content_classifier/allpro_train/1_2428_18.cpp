#include<bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;

struct RH {
    const int n;
    static constexpr lint mod0 = 1e9 + 7, mod1 = 1e9 + 9;
    static constexpr lint b0 = 12345678, b1 = 87654321;
    V<lint> h0, h1, powb0, powb1;
    template<class Itr> RH(Itr first, Itr last) :
        n(last - first), h0(n + 1), h1(n + 1), powb0(n + 1), powb1(n + 1) {
        powb0[0] = powb1[0] = 1;
        for (int i = 0; i < n; ++i, ++first) {
            h0[i + 1] = (h0[i] * b0 + *first) % mod0;
            h1[i + 1] = (h1[i] * b1 + *first) % mod1;
            powb0[i + 1] = powb0[i] * b0 % mod0;
            powb1[i + 1] = powb1[i] * b1 % mod1;
        }
    }
    pair<lint, lint> get(int l, int r) {
        lint res0 = (h0[r] - h0[l] * powb0[r - l]) % mod0;
        lint res1 = (h1[r] - h1[l] * powb1[r - l]) % mod1;
        if (res0 < 0) res0 += mod0;
        if (res1 < 0) res1 += mod1;
        return {res0, res1};
    }
};

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;
    RH rh(begin(s), end(s));
    reverse(begin(s), end(s));
    RH rev(begin(s), end(s));
    auto chk = [&](int k) -> bool {
        int t = 2 * k - 2;
        if (n <= t) {
            return rh.get(2 * k - n - 1, k - 1) == rev.get(0, n - k);
        }
        if (rh.get(0, k) != rev.get(n - t - 1, n - k + 1)) return false;
        for (int i = 0; i < n; i += t) {
            int w = min(t, n - i);
            if (rh.get(0, w) != rh.get(i, i + w)) return false;
        }
        return true;
    };
    // cerr << rh.get(0, 3).first << endl;
    // cerr << rev.get(1, 4).first << endl;
    // return 0;
    for (int k = 2; k <= n; ++k) {
        if (chk(k)) return cout << k << "\n", 0;
    }
    assert(false);
    return 0;
}
