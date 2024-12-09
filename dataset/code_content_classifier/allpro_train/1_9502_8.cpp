#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast,no-stack-protector")
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "\n";
  err(++it, args...);
}
function<void(void)> ____ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
};
template <typename T>
vector<T> &operator<<(vector<T> &__container, T x) {
  __container.push_back(x);
  return __container;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> &__container) {
  for (T _ : __container) out << _ << ' ';
  return out;
}
void sci() {}
template <typename... Args>
void sci(int &x, Args &...args) {
  scanf("%d", &x);
  sci(args...);
}
void scl() {}
template <typename... Args>
void scl(long long int &x, Args &...args) {
  scanf("%lld", &x);
  scl(args...);
}
const int MAXN = 5e3 + 7;
const int MOD = 1e9 + 7;
int n, A[MAXN << 2], prod[MAXN << 2], f[MAXN][MAXN << 1], ret[MAXN << 2],
    invp[MAXN << 2];
long long int ksm(long long int a, long long int b) {
  long long int ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % MOD;
    b >>= 1;
    a = a * a % MOD;
  }
  return ret;
}
long long int inv(int x) { return ksm(x, MOD - 2); }
void solve() {
  sci(n);
  for (int i = 1; i < n; i++) sci(A[i]);
  prod[0] = invp[0] = 1;
  for (int i = 1; i < n; i++) prod[i] = 1ll * prod[i - 1] * A[i] % MOD;
  for (int i = 1; i < n; i++) invp[i] = inv(prod[i]);
  auto F = [&](int d, int k) -> int {
    if (!k) return 0;
    return 1ll * prod[d + k - 1] * invp[d] % MOD * (A[d] - 1) % MOD;
  };
  f[1][0] = 1;
  for (int i = 2; i <= n; i++) {
    f[i][0] = 1;
    for (int j = 1; j <= n - 1 + i - 1; j++) {
      f[i][j] = (f[i - 1][j - 1] + F(i - 1, j - 1)) % MOD;
      ret[j] = (ret[j] + 1ll * prod[i - 1] * f[i][j] % MOD) % MOD;
    }
  }
  for (int i = 1; i < n; i++)
    for (int d = 1; d <= n - i; d++) ret[d] = (ret[d] + prod[i + d - 1]) % MOD;
  int inv2 = inv(2);
  for (int i = 1; i <= 2 * (n - 1); i++)
    cout << 1ll * ret[i] * inv2 % MOD << ' ';
  cout << "\n";
}
int main() {
  solve();
  return 0;
}
