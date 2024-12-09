#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    ll mod = 1000000007;
    vector<ll> x(n), y(m);
    rep(i, n)cin >> x[i];
    rep(i, m)cin >> y[i];
    ll a = 0;
    rep(i, n)a = (a + (2 * (i + 1) - 1 - n) * x[i] % mod) % mod;
    ll b = 0;
    rep(i, m)b = (b + (2 * (i + 1) - 1 - m) * y[i] % mod) % mod;
    cout << a * b % mod << endl;
}