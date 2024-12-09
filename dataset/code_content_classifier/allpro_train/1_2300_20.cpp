#include <bits/stdc++.h>
using namespace std;
int num[3][200005 << 2];
int n, k, a, b, q;
void Update(int v, int l, int r, int p, int d) {
  if (l == r) {
    num[0][v] += d;
    if (num[0][v] > b) num[1][v] = num[0][v] - b;
    if (num[0][v] > a) num[2][v] = num[0][v] - a;
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid)
    Update(v << 1, l, mid, p, d);
  else
    Update(v << 1 | 1, mid + 1, r, p, d);
  for (int i = 0; i < 3; i++) num[i][v] = num[i][v << 1] + num[i][v << 1 | 1];
}
void Query(int v, int L, int R, int l, int r, int *h) {
  if (l == L && R == r) {
    for (int i = 0; i < 3; i++) h[i] += num[i][v];
    return;
  }
  int mid = (L + R) >> 1;
  if (r <= mid)
    Query(v << 1, L, mid, l, r, h);
  else if (l > mid)
    Query(v << 1 | 1, mid + 1, R, l, r, h);
  else {
    Query(v << 1, L, mid, l, mid, h);
    Query(v << 1 | 1, mid + 1, R, mid + 1, r, h);
  }
}
int main() {
  scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
  int t, k1, k2;
  while (q--) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d%d", &k1, &k2);
      Update(1, 1, n, k1, k2);
    } else {
      scanf("%d", &k2);
      int ans = 0;
      if (k2 - 1 >= 1) {
        int h[3] = {0};
        Query(1, 1, n, 1, k2 - 1, h);
        ans = h[0] - h[1];
      }
      if (k2 + k <= n) {
        int h[3] = {0};
        Query(1, 1, n, k2 + k, n, h);
        ans += h[0] - h[2];
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
