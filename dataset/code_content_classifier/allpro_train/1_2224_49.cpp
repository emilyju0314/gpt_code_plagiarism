#include <bits/stdc++.h>
using namespace std;
int f, T, t0;
int a1, t1, p1;
int a2, t2, p2;
bool read() {
  if (scanf("%d%d%d", &f, &T, &t0) < 3) {
    return 0;
  }
  scanf("%d%d%d", &a1, &t1, &p1);
  scanf("%d%d%d", &a2, &t2, &p2);
  return 1;
}
const long long INF = 1e18;
long long go(int T, int f) {
  if (T / t0 >= f) {
    return 0;
  }
  long long ans = INF;
  {
    long long c2 = (T + 1ll * a2 * t2 - 1) / (1ll * a2 * t2);
    long long got = T / t2;
    if (got >= f) {
      ans = min(ans, 1ll * c2 * p2);
    }
  }
  long long A = 1ll * a2 * t0 - 1ll * a2 * t2;
  long long B = 1ll * f * t0 - T;
  if (A <= 0) {
    return ans;
  }
  long long c2 = (B + A - 1) / A;
  if (c2 * a2 * t2 > T) {
    return ans;
  }
  long long got = c2 * a2;
  got += (T - c2 * a2 * t2) / t0;
  if (got >= f) {
    return min(ans, 1ll * p2 * c2);
  }
  return ans;
}
long long go(int c1) {
  if (1ll * c1 * t1 * a1 >= T) {
    long long got = T / t1;
    if (got >= f) {
      return 1ll * p1 * c1;
    } else {
      return INF;
    }
  }
  long long cur = go(T - c1 * t1 * a1, f - c1 * a1);
  if (cur >= INF) {
    return INF;
  }
  cur += 1ll * p1 * c1;
  return cur;
}
long long solve() {
  long long ans = INF;
  for (int it = 0; it < int(2); ++it) {
    for (int c1 = 0; c1 < int(f / a1 + 1); ++c1) {
      ans = min(ans, go(c1));
    }
    swap(a1, a2);
    swap(t1, t2);
    swap(p1, p2);
  }
  if (ans >= INF) {
    return -1;
  }
  return ans;
}
int main() {
  while (read()) {
    printf("%lld\n", solve());
  }
  return 0;
}
