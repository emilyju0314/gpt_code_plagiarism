#include <bits/stdc++.h>
using namespace std;
int N, R;
long long K, A[500004], B[500004];
inline int f(long long xx) {
  int i, l, r, ret = 1;
  long long a = 0, b, kk = K;
  for (i = 0; i <= R && i < N; i++) a += A[i];
  if (a < xx) {
    b = xx - a;
    if (b > kk) return 0;
    kk -= b;
    a += b;
    B[R] = b;
  }
  for (i = 1; i < N; i++) {
    l = max(i - R, 0);
    r = min(i + R, N);
    if (l > 0) {
      a -= A[l - 1] + B[l - 1];
      B[l - 1] = 0;
    }
    if (r < N) {
      a += A[r];
    }
    if (a >= xx) continue;
    b = xx - a;
    if (b > kk) {
      for (int j = i; j <= i + R && j < N; j++) B[j] = 0;
      return 0;
    }
    kk -= b;
    a += b;
    B[r] = b;
  }
  for (i = N - R; i < N; i++) B[i] = 0;
  return 1;
}
int main() {
  int i;
  long long lo, hi, mid;
  cin >> N >> R >> K;
  for (i = 0; i < N; i++) scanf("%lld", A + i);
  lo = 0;
  hi = (long long)2e18;
  while (lo < hi - 1) {
    mid = (lo + hi) / 2;
    if (f(mid))
      lo = mid;
    else
      hi = mid;
  }
  cout << lo;
}
