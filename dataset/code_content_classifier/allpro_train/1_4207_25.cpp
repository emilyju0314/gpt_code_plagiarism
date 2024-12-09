#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010, inf = 1e9;
int n, m, a[maxn], b[maxn], minn[maxn << 2][2], tag[maxn << 2][2];
void pushup(int o) {
  minn[o][0] = min(minn[o * 2][0], minn[o * 2 + 1][0]);
  minn[o][1] = min(minn[o * 2][1], minn[o * 2 + 1][1]);
}
void pushdown(int o) {
  for (int i = 0; i < 2; i++) {
    if (tag[o][i]) {
      minn[o * 2][i] += tag[o][i];
      minn[o * 2 + 1][i] += tag[o][i];
      tag[o * 2][i] += tag[o][i];
      tag[o * 2 + 1][i] += tag[o][i];
      tag[o][i] = 0;
    }
  }
}
void build(int o, int l, int r) {
  if (l == r) {
    minn[o][l & 1] = b[l];
    minn[o][l & 1 ^ 1] = inf;
    return;
  }
  int mid = (l + r) >> 1;
  build(o * 2, l, mid);
  build(o * 2 + 1, mid + 1, r);
  pushup(o);
}
void update(int o, int l, int r, int x, int y, int v, int id) {
  if (x > y) return;
  if (x <= l && r <= y) {
    tag[o][id] += v;
    minn[o][id] += v;
    return;
  }
  pushdown(o);
  int mid = (l + r) >> 1;
  if (x <= mid) update(o * 2, l, mid, x, y, v, id);
  if (y > mid) update(o * 2 + 1, mid + 1, r, x, y, v, id);
  pushup(o);
}
int query1(int o, int l, int r, int cur, int id) {
  if (cur == 0) return 0;
  if (l == r) return minn[o][id];
  pushdown(o);
  int mid = (l + r) >> 1;
  if (cur <= mid) return query1(o * 2, l, mid, cur, id);
  if (cur > mid) return query1(o * 2 + 1, mid + 1, r, cur, id);
}
int query2(int o, int l, int r, int x, int y, int id) {
  if (x <= l && r <= y) return minn[o][id];
  pushdown(o);
  int mid = (l + r) >> 1, res = inf;
  if (x <= mid) res = min(res, query2(o * 2, l, mid, x, y, id));
  if (y > mid) res = min(res, query2(o * 2 + 1, mid + 1, r, x, y, id));
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) b[i] = a[i] - b[i - 1];
  build(1, 1, n);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int id, a, b, k;
    scanf("%d", &id);
    if (id == 1) {
      scanf("%d%d%d", &a, &b, &k);
      a++;
      b++;
      update(1, 1, n, a, b, k, a & 1);
      if ((b - a + 1) & 1) {
        update(1, 1, n, b + 1, n, k, a & 1);
        update(1, 1, n, b + 1, n, -k, a & 1 ^ 1);
      }
    } else {
      scanf("%d%d", &a, &b);
      a++;
      b++;
      if ((b - a + 1) & 1) {
        int temp1 = query1(1, 1, n, a - 1, (a - 1) & 1);
        int temp2 = query2(1, 1, n, a, b, b & 1) + temp1;
        int temp3 = query2(1, 1, n, a, b, b & 1 ^ 1) - temp1;
        int temp4 = query1(1, 1, n, b, b & 1) + temp1;
        if (temp4 == 1 && temp2 >= 1 && temp3 >= 0)
          puts("1");
        else
          puts("0");
      } else {
        int temp1 = query1(1, 1, n, a - 1, (a - 1) & 1);
        int temp2 = query2(1, 1, n, a, b, b & 1) - temp1;
        int temp3 = query2(1, 1, n, a, b, b & 1 ^ 1) + temp1;
        int temp4 = query1(1, 1, n, b, b & 1) - temp1;
        if (temp4 == 0 && temp2 >= 0 && temp3 >= 1)
          puts("1");
        else
          puts("0");
      }
    }
  }
}
