#include <bits/stdc++.h>
using namespace std;
int read() {
  int X = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') X = X * 10 + c - '0', c = getchar();
  return X * w;
}
const int N = 200000 + 10, M = 447 + 10;
int n, m, Q, a[N], id[N];
bool cmp(int x, int y) { return a[x] > a[y]; }
int B, bl[N], L[M], R[M], w[N], addv[M], maxv[M];
int omaxv[M][M], lw[M][M], ql[N], qr[N], qlmax[N], qrmax[N];
int query(int l, int r, int w, int x) {
  int res = 0;
  for (int i = L[bl[l]]; i < l; ++i) w += (a[i + m] >= x) - (a[i] >= x);
  for (int i = l; i <= r; ++i)
    res = max(res, w), w += (a[i + m] >= x) - (a[i] >= x);
  return res;
}
int main() {
  n = read(), m = read();
  B = sqrt(n);
  for (int i = 1; i <= n; ++i) a[i] = read(), id[i] = i;
  sort(id + 1, id + n + 1, cmp);
  for (int i = 1; i <= n; ++i) bl[i] = (i - 1) / B + 1;
  for (int i = 1; i <= bl[n]; ++i) L[i] = (i - 1) * B + 1, R[i] = min(i * B, n);
  for (int i = 1; i <= n; ++i) {
    int l = ql[i] = max(1, id[i] - m + 1), r = qr[i] = id[i];
    if (bl[i] != bl[i - 1]) {
      for (int j = 1; j <= n; ++j) w[j] += addv[bl[j]];
      for (int j = 1; j <= bl[n]; ++j)
        omaxv[bl[i]][j] = maxv[j], lw[bl[i]][j] = w[L[j]], addv[j] = 0;
    }
    if (bl[l] == bl[r]) {
      for (int j = l; j <= r; ++j)
        ++w[j], maxv[bl[j]] = max(maxv[bl[j]], w[j] + addv[bl[j]]);
      qlmax[i] = maxv[bl[l]];
    } else {
      for (int j = L[bl[l]]; j <= R[bl[l]]; ++j) {
        if (j >= l) ++w[j];
        maxv[bl[j]] = max(maxv[bl[j]], w[j] + addv[bl[j]]);
      }
      for (int j = L[bl[r]]; j <= r; ++j)
        ++w[j], maxv[bl[j]] = max(maxv[bl[j]], w[j] + addv[bl[j]]);
      for (int j = bl[l] + 1; j <= bl[r] - 1; ++j) ++addv[j], ++maxv[j];
      for (int j = L[bl[l]]; j <= R[bl[l]]; ++j) qlmax[i] = max(qlmax[i], w[j]);
      for (int j = L[bl[r]]; j <= R[bl[r]]; ++j) qrmax[i] = max(qrmax[i], w[j]);
    }
  }
  Q = read();
  int lastans = 0;
  while (Q--) {
    int l = read(), r = read(), x = read() ^ lastans;
    a[0] = x;
    int p = upper_bound(id + 1, id + n + 1, 0, cmp) - id - 1;
    for (int i = 1; i <= bl[n]; ++i) addv[i] = 0, maxv[i] = omaxv[bl[p]][i];
    int llw = lw[bl[p]][bl[l]], lrw = lw[bl[p]][bl[r]];
    for (int i = L[bl[p]]; i <= p; ++i) {
      maxv[bl[ql[i]]] = qlmax[i];
      if (bl[ql[i]] != bl[qr[i]])
        maxv[bl[qr[i]]] = qrmax[i], ++addv[bl[ql[i]] + 1], --addv[bl[qr[i]]];
      if (ql[i] <= L[bl[l]] && L[bl[l]] <= qr[i]) ++llw;
      if (ql[i] <= L[bl[r]] && L[bl[r]] <= qr[i]) ++lrw;
    }
    for (int i = 1; i <= bl[n]; ++i) addv[i] += addv[i - 1];
    if (bl[l] == bl[r])
      printf("%d\n", lastans = m - query(l, r, llw, x));
    else {
      int ans = max(query(l, R[bl[l]], llw, x), query(L[bl[r]], r, lrw, x));
      for (int i = bl[l] + 1; i <= bl[r] - 1; ++i)
        ans = max(ans, maxv[i] + addv[i]);
      printf("%d\n", lastans = m - ans);
    }
  }
  return 0;
}
