#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
const int maxN = 5 * (int)1e6 + 100;
int fact[maxN], invfact[maxN], inv[maxN];
int cnk(int a, int b) {
    if (a < 0 || b < 0 || a < b) return 0;
    return mult(fact[a], mult(invfact[b], invfact[a - b]));
}
int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    fact[0] = inv[1] = fact[1] = invfact[1] = invfact[0] = 1;
    for (int i = 2; i < maxN; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    int total = cnk(3 * m + n - 1, n - 1);
    int coef = mult(n, cnk(3 * m - 2 * m - 1 + n - 1, n - 1));
    total = sub(total, coef);
    int add = 0;
    for (int coef = 0; coef < m; coef++) {
        int odd = 3 * m - 2 * coef;
        add = sum(add, mult(cnk(n, odd), cnk(coef + n - 1, n - 1)));
    }
    total = sub(total, add);
    cout << total;
    return 0;
}