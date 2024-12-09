#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10, inf = 1e9 + 10;
int v[MAXN], c[MAXN];
int seg[2][MAXN * 4], n, k, a[MAXN];
double dp[MAXN];
inline void update(int ind) {
  seg[0][ind] = min(seg[0][((ind)*2)], seg[0][(((ind)*2) + 1)]);
  seg[1][ind] = max(seg[1][((ind)*2)], seg[1][(((ind)*2) + 1)]);
}
void add(int s, int e, int ind, int x, int val, int type) {
  if (s > x or e <= x) return;
  if (s + 1 == e) {
    seg[type][ind] = val;
    return;
  }
  int mid = (s + e) / 2;
  add(s, mid, ((ind)*2), x, val, type);
  add(mid, e, (((ind)*2) + 1), x, val, type);
  update(ind);
}
int fin_min(int s, int e, int ind, int x, int y) {
  if (s >= y or e <= x) return inf;
  if (s >= x and e <= y) return seg[0][ind];
  int mid = (s + e) / 2;
  return min(fin_min(s, mid, ((ind)*2), x, y),
             fin_min(mid, e, (((ind)*2) + 1), x, y));
}
int fin_max(int s, int e, int ind, int x, int y) {
  if (s >= y or e <= x) return 0;
  if (s >= x and e <= y) return seg[1][ind];
  int mid = (s + e) / 2;
  return max(fin_max(s, mid, ((ind)*2), x, y),
             fin_max(mid, e, (((ind)*2) + 1), x, y));
}
int main() {
  memset(seg[0], 127, sizeof seg[0]);
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    v[i] *= 100;
    add(0, n, 1, i, v[i], 1);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
    add(0, n, 1, i, c[i], 0);
  }
  double ans = 0;
  a[n - 1] = min(v[n - 1], c[n - 1]);
  for (int i = n - 2; i >= 0; i--) a[i] = min(max(a[i + 1], v[i]), c[i]);
  sort(a, a + n);
  double p = double(k) / double(n);
  for (int i = 0; i < n; i++) {
    if (i + k > n) break;
    ans += p * a[i];
    int x = n - i - 1;
    p /= x;
    p *= x - k + 1;
  }
  printf("%.12lf\n", ans);
  return 0;
}
