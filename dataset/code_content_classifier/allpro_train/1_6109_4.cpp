#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int INF = 2e9;
const long long INFLL = 1e18;
const int MAX_N = 1;
long long A, H, W;
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
int main() {
  scanf("%lld%lld%lld", &A, &H, &W);
  if (H < W) {
    long long tmp = H;
    H = W;
    W = tmp;
  }
  long long g = gcd(H - W, W + A);
  long long T = (H + A) / g;
  long long s = 1, e = g, m;
  while (s < e) {
    m = (s + e) / 2 + 1;
    if (H + A - A * (T * m) >= 0) {
      s = m;
    } else {
      e = m - 1;
    }
  }
  if (0) cout << s << endl;
  if (0) cout << T << endl;
  if (H + A - A * T * s < 0) {
    printf("-1");
    return 0;
  }
  if (0) cout << T * s - 1 << endl;
  long long K = (H - W) / g;
  K *= s;
  if (0) cout << T * s - 1 - K << endl;
  if (T * s - 1 <= 0) {
    printf("-1");
    return 0;
  }
  if (W != H) {
    if (T * s - 1 - K <= 0) {
      printf("-1");
      return 0;
    }
  }
  long double d = (long double)g / (long double)s - (long double)A;
  printf("%Lf", d);
  return 0;
}
