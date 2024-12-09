#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const int LOG = 19;
int n, m;
int a[N], jl[LOG][N], jr[LOG][N];
int tr[LOG][N << 1], tl[LOG][N << 1];
void build(int id) {
  for (int i = 1; i <= m; i++) {
    tl[id][i + N] = jl[id][i];
    tr[id][i + N] = jr[id][i];
  }
  for (int i = N - 1; i >= 1; i--) {
    tl[id][i] = min(tl[id][i + i], tl[id][i + i + 1]);
    tr[id][i] = max(tr[id][i + i], tr[id][i + i + 1]);
  }
}
int getr(int id, int l, int r) {
  int res = 0;
  for (l += N, r += N; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
    if (l & 1) res = max(res, tr[id][l]);
    if (~r & 1) res = max(res, tr[id][r]);
  }
  return res;
}
int getl(int id, int l, int r) {
  int res = 1e9;
  for (l += N, r += N; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
    if (l & 1) res = min(res, tl[id][l]);
    if (~r & 1) res = min(res, tl[id][r]);
  }
  return res;
}
pair<int, int> cc(int id, int l, int r) {
  return pair<int, int>(getl(id, l, r), getr(id, l, r));
}
pair<int, int> calc(int id, int l, int r) {
  if (r - l + 1 >= n) return pair<int, int>(1, n);
  return cc(id, l, r);
}
int main() {
  scanf("%d", &n);
  m = 3 * n;
  for (int i = 1; i <= m; i++) {
    if (i <= n) {
      scanf("%d", a + i);
    } else
      a[i] = a[i - n];
    jr[0][i] = min(m, i + a[i]);
    jl[0][i] = max(1, i - a[i]);
  }
  if (n == 1) {
    puts("0");
    return 0;
  }
  for (int it = 1; it < LOG; it++) {
    build(it - 1);
    for (int i = 1; i <= m; i++) {
      auto x = calc(it - 1, jl[it - 1][i], jr[it - 1][i]);
      if (x.second - x.first + 1 >= n) x = pair<int, int>(1, n);
      tie(jl[it][i], jr[it][i]) = x;
    }
  }
  build(LOG - 1);
  for (int i = n + 1; i <= n + n; i++) {
    int ans = 0;
    int l = i, r = i;
    for (int j = LOG - 1; j >= 0; j--) {
      auto x = calc(j, l, r);
      if (x.second - x.first + 1 < n) {
        ans += 1 << j;
        tie(l, r) = x;
      }
    }
    printf("%d ", ans + 1);
  }
  puts("");
  return 0;
}
