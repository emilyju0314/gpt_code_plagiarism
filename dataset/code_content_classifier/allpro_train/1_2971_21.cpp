#include <bits/stdc++.h>
using namespace std;
const int iinf = 0x3f3f3f3f;
const long long linf = 0x3f3f3f3f3f3f3f3f;
const int N = 80;
int n;
long long fib[N];
void math_init() {
  fib[0] = fib[1] = 1;
  for (int i = 2; i < N; ++i) fib[i] = fib[i - 1] + fib[i - 2];
}
pair<int, int> dp(long long u, int k, int d = iinf) {
  if (k <= 1) return make_pair(0, 0);
  if (u < fib[k - 1]) {
    auto p = dp(u, k - 1, 2);
    return make_pair(
        p.first, min(min(p.first, p.second) + 1 + (k - 2) / 2, p.first + d));
  } else {
    auto p = dp(u - fib[k - 1], k - 2, d + 1);
    return make_pair(min(p.first + 1, p.second + d), p.second);
  }
}
int solve(long long u, long long v, int k, int d = iinf) {
  if (u == 0 && v == fib[k] - 1) return min(d, k / 2);
  if (v < fib[k - 1]) return solve(u, v, k - 1, 2);
  if (u >= fib[k - 1])
    return solve(u - fib[k - 1], v - fib[k - 1], k - 2, d + 1);
  auto ud = dp(u, k - 1, 2), vd = dp(v - fib[k - 1], k - 2, d + 1);
  return min(min(ud.first, ud.second) + 1 + vd.first, ud.first + d + vd.second);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  math_init();
  int m;
  cin >> m >> n, n = min(n + 1, N - 1);
  while (m--) {
    long long u, v;
    cin >> u >> v, --u, --v;
    if (u > v) swap(u, v);
    cout << solve(u, v, n) << '\n';
  }
  return 0;
}
