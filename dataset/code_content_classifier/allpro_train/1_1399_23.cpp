#include <bits/stdc++.h>
using namespace std;
bool chmin(int64_t& a, const int64_t& b) { return b < a ? a = b, 1 : 0; }
bool chmax(int64_t& a, const int64_t& b) { return a < b ? a = b, 1 : 0; }
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return 31 - __builtin_clz(x); }
const int N = 1e6 + 5;
int64_t binpow(int64_t a, int64_t b, int64_t m = 1000000007) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
int64_t gcd(int64_t a, int64_t b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
int64_t extended_gcd(int64_t a, int64_t b, int64_t& x, int64_t& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int64_t x1, y1;
  int64_t d = extended_gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
void run_case() {
  int n, m;
  cin >> n >> m;
  vector<int64_t> x(n), p(m);
  int64_t g = 0;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    if (i > 0) {
      g = gcd(g, x[i] - x[i - 1]);
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < m; i++) {
    if (g == p[i] || g % p[i] == 0) {
      cout << "YES\n";
      cout << x[0] << ' ' << i + 1 << endl;
      return;
    }
  }
  puts("NO");
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) {
    run_case();
  }
  return 0;
}
