#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const long long INF = (long long)1e17 + 10;
int n, m;
int d[2 * N];
int h[2 * N];
int nxt[2 * N][19];
long long dd[2 * N];
long long mx[2 * N][19], mn[2 * N][19];
long long dx[2 * N][19];
long long getmx(int a, int b) {
  if (a == b) return -INF;
  int p = b - a;
  for (int i = 18; i >= 0; --i) {
    if (p >> i & 1) {
      return max(mx[a][i], getmx(nxt[a][i], b));
    }
  }
}
long long solve(int a, int b) {
  if (a == b) return 0;
  int p = b - a;
  for (int i = 18; i >= 0; --i) {
    if (p >> i & 1) {
      long long t = getmx(nxt[a][i], b);
      return max(t - mn[a][i], max(dx[a][i], solve(nxt[a][i], b)));
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", d + i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", h + i);
  }
  for (int i = n; i < 2 * n; ++i) {
    d[i] = d[i - n];
    h[i] = h[i - n];
  }
  n *= 2;
  for (int i = 1; i < n; ++i) {
    dd[i] = dd[i - 1] + d[i - 1];
  }
  for (int i = 0; i < n; ++i) {
    nxt[i][0] = min(i + 1, n - 1);
    mx[i][0] = dd[i] + 2LL * h[i];
    mn[i][0] = dd[i] - 2LL * h[i];
  }
  for (int j = 1; j < 19; ++j) {
    for (int i = 0; i < n; ++i) {
      int t = nxt[i][j - 1];
      nxt[i][j] = nxt[t][j - 1];
      mx[i][j] = max(mx[i][j - 1], mx[t][j - 1]);
      mn[i][j] = min(mn[i][j - 1], mn[t][j - 1]);
      if (t != i) {
        dx[i][j] = max(dx[i][j - 1], dx[t][j - 1]);
        dx[i][j] = max(dx[i][j], mx[t][j - 1] - mn[i][j - 1]);
      }
    }
  }
  for (int i = 0, a, b; i < m; ++i) {
    scanf("%d%d", &a, &b);
    if (a <= b) {
      a += n / 2;
    }
    swap(a, b);
    b--;
    printf("%I64d\n", solve(a, b));
  }
  return 0;
}
