#include <bits/stdc++.h>
using namespace std;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
template <typename T, typename U>
static void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static void amax(T &x, U y) {
  if (x < y) x = y;
}
struct DynamicRMQ {
  int n;
  vector<long long> d;
  void init(int nmin) {
    for (n = 1; n < nmin; n *= 2)
      ;
    d.assign(n * 2, -INFL);
  }
  void update(int i, long long x) {
    d[n + i] = x;
    for (int k = (n + i) / 2; k > 0; k >>= 1)
      d[k] = max(d[k * 2], d[k * 2 + 1]);
  }
  long long get(int i) const { return d[n + i]; }
  long long query(int l, int r) const {
    long long m = -INFL;
    for (; l && l + (l & -l) <= r; l += l & -l)
      m = max(m, d[(n + l) / (l & -l)]);
    for (; l < r; r -= r & -r) m = max(m, d[(n + r) / (r & -r) - 1]);
    return m;
  }
};
int main() {
  int N;
  long long C;
  while (~scanf("%d%lld", &N, &C)) {
    vector<int> A(N * 2 - 1);
    for (int i = 0; i < N * 2 - 1; ++i) scanf("%d", &A[i]);
    vector<long long> psum(A.size() + 1);
    for (int(i) = 0; (i) < (int)(A.size()); ++(i)) psum[i + 1] = psum[i] + A[i];
    DynamicRMQ rmq0, rmq1;
    rmq0.init(N + 1);
    rmq1.init(N + 1);
    rmq0.update(0, 0);
    rmq1.update(0, 0);
    int curL = 0;
    for (int(R) = 0; (R) < (int)(N * 2 - 1); ++(R)) {
      for (; psum[R + 1] - psum[curL] > C; ++curL)
        ;
      long long x = 0;
      if (0 < curL) {
        long long t = rmq0.query(0, (curL - 1) / 2 + 1);
        amax(x, t + C);
      }
      if (curL <= R) {
        int bL = curL / 2 + 1, bR = R / 2 - 1;
        long long t = -INFL;
        if (bL <= bR) amax(t, rmq1.query(bL, bR + 1));
        for (int(L) = (int)(curL); (L) < (int)(bL * 2); ++(L))
          if (curL <= L && L <= R) amax(t, rmq0.get(L / 2) - psum[L]);
        for (int(L) = (int)(bR * 2); (L) <= (int)(R); ++(L))
          if (curL <= L && L <= R) amax(t, rmq0.get(L / 2) - psum[L]);
        amax(x, t + psum[R + 1]);
      }
      int i = (R + 1) / 2 + 1;
      rmq0.update(i, max(rmq0.get(i), x));
      for (int(L) = (int)(max(0, R - 2)); (L) <= (int)(R + 2); ++(L))
        rmq1.update(L / 2, max(rmq1.get(L / 2), rmq0.get(L / 2) - psum[L]));
    }
    long long ans = rmq0.get(N);
    printf("%lld\n", ans);
  }
  return 0;
}
