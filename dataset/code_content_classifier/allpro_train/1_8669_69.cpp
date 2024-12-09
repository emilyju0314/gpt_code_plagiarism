#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << " ";
  os << "]";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, set<T> S) {
  os << "{ ";
  for (auto s : S) os << s << " ";
  return os << "}";
}
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> M) {
  os << "{ ";
  for (auto m : M) os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
inline long long mul(long long x, long long y, long long m) {
  long long z = 1LL * x * y;
  if (z >= m) z %= m;
  return z;
}
inline long long add(long long x, long long y, long long m) {
  long long z = x + y;
  if (z >= m) z %= m;
  return z;
}
inline long long sub(long long x, long long y, long long m) {
  long long z = x - y;
  if (z < 0) z += m;
  z %= m;
  return z;
}
const long long N = 2005;
long long a[N], dp[N][2 * N], n, k;
long long rec(long long in, long long rem) {
  if (in == n) return rem > 0;
  if (dp[in][n + rem] != -1) return dp[in][n + rem];
  long long pr = (in - 1 + n) % n;
  if (a[in] == a[pr])
    return dp[in][n + rem] = mul(k, rec(in + 1, rem), 998244353);
  long long p = 0;
  p = add(p, rec(in + 1, rem - 1), 998244353);
  p = add(p, rec(in + 1, rem + 1), 998244353);
  p = add(p, mul(k - 2, rec(in + 1, rem), 998244353), 998244353);
  return dp[in][rem + n] = p;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for (long long i = 0; i < n; i++) cin >> a[i];
  memset(dp, -1, sizeof(dp));
  long long ans = rec(0, 0);
  cout << ans;
  return 0;
}
