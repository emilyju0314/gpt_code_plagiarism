#include <bits/stdc++.h>
using namespace std;
const int N = 101010;
int n, s, l;
int a[N], mi[N][22], ma[N][22], st[N][22];
int Min(int l, int r) {
  int _ = log2(r - l + 1);
  return min(mi[l][_], mi[r - (1 << _) + 1][_]);
}
int Max(int l, int r) {
  int _ = log2(r - l + 1);
  return max(ma[l][_], ma[r - (1 << _) + 1][_]);
}
int ST(int l, int r) {
  if (l == 0) return 0;
  int _ = log2(r - l + 1);
  return min(st[r][_], st[l + (1 << _) - 1][_]);
}
bool check(int mid, int i) { return Max(mid, i) - Min(mid, i) <= s; }
int get(int i) {
  if (i < l) return -1;
  int L = 1, R = i - l + 1, p = -1;
  while (L <= R) {
    int mid = L + R >> 1;
    if (check(mid, i)) {
      p = mid;
      R = mid - 1;
    } else {
      L = mid + 1;
    }
  }
  return p;
}
int main() {
  while (~scanf("%d%d%d", &n, &s, &l)) {
    for (int i = (1); i < (n + 1); i++)
      scanf("%d", a + i), ma[i][0] = mi[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; ++j) {
      for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
        mi[i][j] = min(mi[i][j - 1], mi[i + (1 << (j - 1))][j - 1]);
        ma[i][j] = max(ma[i][j - 1], ma[i + (1 << (j - 1))][j - 1]);
      }
    }
    memset(st, 0x3f, sizeof(st));
    for (int i = (1); i < (n + 1); i++) {
      int p = get(i);
      if (p == -1) {
      } else {
        st[i][0] = min(ST(p - 1, i - l) + 1, st[i][0]);
      }
      for (int j = 1; (1 << j) <= i; ++j)
        st[i][j] = min(st[i][j - 1], st[i - (1 << (j - 1))][j - 1]);
    }
    int ans = st[n][0];
    if (ans == st[N - 1][0]) ans = -1;
    printf("%d\n", ans);
  }
  return 0;
}
