#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <random>
#include <complex>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const int MN = 501*1000*1000;

ll gcd(ll a, ll b) {
    if (!a) return b;
    return gcd(b%a, a);
}
ll ext_gcd(ll a, ll b, ll &x, ll &y) {
    ll d = a;
    if (b) {
        d = ext_gcd(b, a%b, y, x);
        y -= a / b*x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

int w, d, n, m, t, u, h;
int x;
void init() {
    m = t-m%t;
    u = gcd(t, w+d), h = gcd(t, m);
    ll xx, y;
    ext_gcd(m, t, xx, y);
    x = ((xx % t) + t) % t;
}
int solve() {
    init();

    int res = 0;
    int l = 0;

    int s = 0;
    int th = t/h;
    for (int i = 0; i < t; i += h) {
        if (s<n) {
            res += max(0, (i-l - w + u) / u);
            l = (i/u+1)*u;
        }
        s += x; s %= th;
    }
    res += max(0, (t-l-w+u)/u);
    return res;
}

int main() {
    cin >> w >> d >> n >> m >> t; w++; d--;
    printf("%.20f\n", 1.0 * solve() / (t / u));
    return 0;
}