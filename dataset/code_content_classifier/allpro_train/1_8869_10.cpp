#include <bits/stdc++.h>
using namespace std;
const int maxn = 410010;
const int inf = 2000000000;
const int maxm = 100000000;
int lft[maxn << 2], rht[maxn << 2], M[maxn << 2][4];
int lc[maxn << 2], rc[maxn << 2], a[maxn], cnt;
void build(int n, int l, int r) {
  lft[n] = l, rht[n] = r;
  for (int i = 0; i < 4; i++) M[n][i] = inf;
  if (l == r) return;
  int mid = (l + r) / 2;
  build(n << 1, l, mid);
  build((n << 1) + 1, mid + 1, r);
}
void upd(int n, int pos, int i, int k) {
  if (lft[n] == rht[n]) {
    M[n][i] = k;
    return;
  }
  int mid = (lft[n] + rht[n]) / 2;
  if (pos <= mid)
    upd(n << 1, pos, i, k);
  else
    upd((n << 1) + 1, pos, i, k);
  M[n][i] = min(M[n << 1][i], M[(n << 1) + 1][i]);
}
int get(int n, int l, int r, int i) {
  if (lft[n] == l && rht[n] == r) return M[n][i];
  int mid = (lft[n] + rht[n]) / 2;
  if (r <= mid)
    return get(n << 1, l, r, i);
  else if (l > mid)
    return get((n << 1) + 1, l, r, i);
  return min(get(n << 1, l, mid, i), get((n << 1) + 1, mid + 1, r, i));
}
struct NN {
  int bel, add, lx, rx, ly, ry;
  NN(int b = 0, int a = 0, int llx = 0, int rrx = 0, int lly = 0, int rry = 0) {
    bel = b;
    add = a;
    lx = llx;
    rx = rrx;
    ly = lly;
    ry = rry;
  }
};
vector<NN> V1[maxn];
vector<NN> V2[maxn];
vector<NN> V3[maxn];
vector<NN> V4[maxn];
vector<NN> V5[maxn];
vector<NN> V6[maxn];
vector<NN> V7[maxn];
vector<NN> V8[maxn];
int ans[maxn];
int q[maxn];
int gao(int n, int idx, NN k) {
  int i, j, l, r, mid, L, R;
  l = 1, r = n + 1;
  while (l < r) {
    mid = (l + r) / 2;
    if (q[mid] >= k.lx && a[q[mid]] >= k.ly)
      r = mid;
    else
      l = mid + 1;
  }
  L = l, l = 0, r = n;
  while (l < r) {
    mid = (l + r + 1) / 2;
    if (q[mid] <= k.rx && a[q[mid]] <= k.ry)
      l = mid;
    else
      r = mid - 1;
  }
  R = r;
  if (L > R || L > n || R < 1) return inf;
  int ret = get(1, L, R, idx);
  return ret;
}
void cal(int n) {
  int tail = 0, i, j;
  build(1, 1, n);
  for (i = 1; i <= n; i++) {
    while (tail && a[q[tail]] >= a[i]) tail--;
    q[++tail] = i;
    upd(1, tail, 0, -a[i] - i * 2);
    upd(1, tail, 1, a[i] - i * 2);
    upd(1, tail, 2, -a[i]);
    upd(1, tail, 3, a[i]);
    for (j = 0; j < V1[i].size(); j++) {
      NN tmp = V1[i][j];
      ans[tmp.bel] = min(ans[tmp.bel], gao(tail, 0, tmp) + tmp.add);
    }
    for (j = 0; j < V3[i].size(); j++) {
      NN tmp = V3[i][j];
      ans[tmp.bel] = min(ans[tmp.bel], gao(tail, 1, tmp) + tmp.add);
    }
    for (j = 0; j < V5[i].size(); j++) {
      NN tmp = V5[i][j];
      ans[tmp.bel] = min(ans[tmp.bel], gao(tail, 2, tmp) + tmp.add);
    }
    for (j = 0; j < V7[i].size(); j++) {
      NN tmp = V7[i][j];
      ans[tmp.bel] = min(ans[tmp.bel], gao(tail, 3, tmp) + tmp.add);
    }
  }
}
int R1[maxn], R2[maxn], C1[maxn], C2[maxn];
int main() {
  int n, i, j, k;
  scanf("%d", &n);
  build(1, 1, n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]), upd(1, i, 0, a[i]);
  int Q;
  scanf("%d", &Q);
  for (i = 1; i <= Q; i++) {
    int r1, r2, c1, c2;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    R1[i] = r1, C1[i] = c1;
    R2[i] = r2, C2[i] = c2;
    int miny = get(1, min(r1, r2), max(r1, r2), 0);
    c1 = min(c1, miny);
    ans[i] = min(abs(r1 - r2) + 1 + c2, abs(c1 - c2) + abs(r1 - r2));
    if (r1 <= r2) {
      if (c1 <= c2) {
        V1[r2].push_back(NN(i, r1 + r2 + c2 + 1, 1, r1, 1, c2));
        V3[r2].push_back(NN(i, r1 + r2 - c2 + 1, 1, r1, c2, maxm));
        V2[n - r2 + 1].push_back(
            NN(i, (n - r1 + 1) + (n - r2 + 1) + c2 + 1, 1, n - r2 + 1, 1, c2));
        V4[n - r2 + 1].push_back(NN(i, (n - r1 + 1) + (n - r2 + 1) - c2 + 1, 1,
                                    n - r2 + 1, c2, maxm));
        V5[r2].push_back(NN(i, r2 - r1 + c2 + 1, r1, r2, 1, c2));
        V7[r2].push_back(NN(i, r2 - r1 - c2 + 1, r1, r2, c2, maxm));
      } else {
        V1[r2].push_back(NN(i, r1 + r2 + c2, 1, r1, 1, c2));
        V3[r2].push_back(NN(i, r1 + r2 - c2, 1, r1, c2, c1));
        V2[n - r2 + 1].push_back(
            NN(i, (n - r1 + 1) + (n - r2 + 1) + c2, 1, n - r2 + 1, 1, c2));
        V4[n - r2 + 1].push_back(
            NN(i, (n - r1 + 1) + (n - r2 + 1) - c2, 1, n - r2 + 1, c2, c1));
        V1[r2].push_back(NN(i, r1 + r2 + c2 + 1, 1, r1, 1, c2));
        V3[r2].push_back(NN(i, r1 + r2 - c2 + 1, 1, r1, c2, maxm));
        V2[n - r2 + 1].push_back(
            NN(i, (n - r1 + 1) + (n - r2 + 1) + c2 + 1, 1, n - r2 + 1, 1, c2));
        V4[n - r2 + 1].push_back(NN(i, (n - r1 + 1) + (n - r2 + 1) - c2 + 1, 1,
                                    n - r2 + 1, c2, maxm));
        V5[r2].push_back(NN(i, r2 - r1 + c2 + 1, r1, r2, 1, c2));
        V7[r2].push_back(NN(i, r2 - r1 - c2 + 1, r1, r2, c2, maxm));
      }
    } else {
      r1 = n - r1 + 1;
      r2 = n - r2 + 1;
      if (c1 <= c2) {
        V2[r2].push_back(NN(i, r1 + r2 + c2 + 1, 1, r1, 1, c2));
        V4[r2].push_back(NN(i, r1 + r2 - c2 + 1, 1, r1, c2, maxm));
        V1[n - r2 + 1].push_back(
            NN(i, (n - r1 + 1) + (n - r2 + 1) + c2 + 1, 1, n - r2 + 1, 1, c2));
        V3[n - r2 + 1].push_back(NN(i, (n - r1 + 1) + (n - r2 + 1) - c2 + 1, 1,
                                    n - r2 + 1, c2, maxm));
        V6[r2].push_back(NN(i, r2 - r1 + c2 + 1, r1, r2, 1, c2));
        V8[r2].push_back(NN(i, r2 - r1 - c2 + 1, r1, r2, c2, maxm));
      } else {
        V2[r2].push_back(NN(i, r1 + r2 + c2, 1, r1, 1, c2));
        V4[r2].push_back(NN(i, r1 + r2 - c2, 1, r1, c2, c1));
        V1[n - r2 + 1].push_back(
            NN(i, (n - r1 + 1) + (n - r2 + 1) + c2, 1, n - r2 + 1, 1, c2));
        V3[n - r2 + 1].push_back(
            NN(i, (n - r1 + 1) + (n - r2 + 1) - c2, 1, n - r2 + 1, c2, c1));
        V2[r2].push_back(NN(i, r1 + r2 + c2 + 1, 1, r1, 1, c2));
        V4[r2].push_back(NN(i, r1 + r2 - c2 + 1, 1, r1, c2, maxm));
        V1[n - r2 + 1].push_back(
            NN(i, (n - r1 + 1) + (n - r2 + 1) + c2 + 1, 1, n - r2 + 1, 1, c2));
        V3[n - r2 + 1].push_back(NN(i, (n - r1 + 1) + (n - r2 + 1) - c2 + 1, 1,
                                    n - r2 + 1, c2, maxm));
        V6[r2].push_back(NN(i, r2 - r1 + c2 + 1, r1, r2, 1, c2));
        V8[r2].push_back(NN(i, r2 - r1 - c2 + 1, r1, r2, c2, maxm));
      }
    }
  }
  cal(n);
  for (i = 1; i * 2 <= n; i++) swap(a[i], a[n - i + 1]);
  for (i = 1; i <= n; i++) {
    V1[i] = V2[i];
    V3[i] = V4[i];
    V5[i] = V6[i];
    V7[i] = V8[i];
  }
  cal(n);
  for (i = 1; i <= Q; i++) printf("%d\n", ans[i]);
}
