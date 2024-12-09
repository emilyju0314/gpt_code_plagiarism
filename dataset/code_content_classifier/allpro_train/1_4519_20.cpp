#include <bits/stdc++.h>
using namespace std;
void canhazfast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
template <typename T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
T extgcd(T a, T b, T &x, T &y) {
  T x0 = 1, y0 = 0, x1 = 0, y1 = 1;
  while (b) {
    T q = a / b;
    a %= b;
    swap(a, b);
    x0 -= q * x1;
    swap(x0, x1);
    y0 -= q * y1;
    swap(y0, y1);
  }
  x = x0;
  y = y0;
  return a;
}
int ctz(unsigned x) { return __builtin_ctz(x); }
int ctzll(unsigned long long x) { return __builtin_ctzll(x); }
int clz(unsigned x) { return __builtin_clz(x); }
int clzll(unsigned long long x) { return __builtin_clzll(x); }
int popcnt(unsigned x) { return __builtin_popcount(x); }
int popcntll(unsigned long long x) { return __builtin_popcountll(x); }
int bsr(unsigned x) { return 31 ^ clz(x); }
int bsrll(unsigned long long x) { return 63 ^ clzll(x); }
int a[200016], c[200016], s[200016];
int main() {
  canhazfast();
  int n, p, amax, xmin;
  int lo = 200016, hi = -200016;
  vector<int> ans;
  cin >> n >> p;
  for (int i = 0; i < n; ++i) cin >> a[i];
  amax = *max_element(a, a + n);
  xmin = max(amax - (n - 1), 0);
  for (int i = 0; i < n; ++i) {
    int q = max(a[i] - xmin, 0);
    ++c[q];
  }
  s[0] = c[0];
  for (int i = 1; i < n; ++i) s[i] = s[i - 1] + c[i];
  for (int i = n - 1; i >= 0; --i) {
    lo = min(lo - 1, s[i]);
    hi = max(hi - 1, s[i]);
    if (lo > 0 && hi < p) ans.push_back(xmin + i);
  }
  reverse((ans).begin(), (ans).end());
  cout << ans.size() << '\n';
  for (int x : ans) cout << x << ' ';
  cout << '\n';
  return 0;
}
