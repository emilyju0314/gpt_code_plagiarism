#include <bits/stdc++.h>
using namespace std;
struct FastHull {
  vector<int> id;
  vector<long long> A, B, P;
  int c;
  int qpos;
  FastHull(int n) {
    c = qpos = 0;
    A.resize(n);
    B.resize(n);
    P.resize(n);
  }
  long long monotonicQuery(int x) {
    while (qpos + 1 < c && P[qpos + 1] <= x) ++qpos;
    return A[qpos] * x + B[qpos];
  }
  long long query(int x) {
    int pos = upper_bound(P.begin(), P.begin() + c, x) - P.begin() - 1;
    return A[pos] * x + B[pos];
  }
  long long divideCeil(long long p, long long q) {
    if (p >= 0) return (p + q - 1) / q;
    return -((-p) / q);
  }
  void insertLine(long long a, long long b) {
    for (; c; --c) {
      if (A[c - 1] == a) {
        if (B[c - 1] >= b) return;
        continue;
      }
      long long pt = divideCeil(B[c - 1] - b, a - A[c - 1]);
      if (pt > P[c - 1]) break;
    }
    P[c] = c ? divideCeil(B[c - 1] - b, a - A[c - 1]) : LLONG_MIN;
    A[c] = a;
    B[c] = b;
    ++c;
  }
};
long long F[1000005];
int main() {
  int n;
  scanf("%d", &n);
  vector<pair<pair<int, int>, long long>> rects;
  for (int i = 0; i < n; ++i) {
    int x, y;
    long long a;
    scanf("%d%d%lld", &x, &y, &a);
    rects.push_back({{x, y}, a});
  }
  sort(rects.begin(), rects.end());
  FastHull hull(n + 1);
  hull.insertLine(0, 0);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int x = rects[i].first.first;
    int y = rects[i].first.second;
    F[i + 1] = hull.query(-y) + (long long)y * x - rects[i].second;
    hull.insertLine(x, F[i + 1]);
    ans = max(ans, F[i + 1]);
  }
  printf("%lld\n", ans);
}
