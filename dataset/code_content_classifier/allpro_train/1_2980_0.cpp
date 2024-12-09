#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Os")
using namespace std;
template <typename T, typename K>
inline void umax(T &a, K b) {
  a = max(a, (T)b);
}
template <typename T, typename K>
inline void umin(T &a, K b) {
  a = min(a, (T)b);
}
const int32_t N = 8e6;
const long long INF = 1e16 + 10;
const long double EPS = 1e-6;
const long long II = 1e9 + 10;
const long long MOD = 1e9 + 7;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  long long ll = 0, rr = n * m + 1;
  while (ll < rr) {
    long long mm = (ll + rr) >> 1LL;
    long long cnt = 0;
    for (long long i = 1; i <= n; i++) {
      cnt += min(m, mm / i);
    }
    if (cnt < k)
      ll = mm + 1;
    else
      rr = mm;
  }
  cout << ll << endl;
}
