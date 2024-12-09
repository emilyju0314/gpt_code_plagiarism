#include <bits/stdc++.h>
using namespace std;
int n, m, q, mp[12][100005], pre[1000005], tot;
bool flag;
struct node {
  int num;
  int L[12], R[12];
} a[100005 << 2], ans;
void init(int x) {
  for (int i = 0; i <= x; ++i) pre[i] = i;
}
int Find(int x) { return pre[x] == x ? x : pre[x] = Find(pre[x]); }
void Union(int a, int b) {
  int x = Find(a), y = Find(b);
  if (x != y) pre[x] = y;
}
void push_up(int x, int mid) {
  int l = x << 1, r = x << 1 | 1;
  a[x].num = a[l].num + a[r].num;
  for (int i = 0; i < n; ++i) {
    if (mp[i][mid] == mp[i][mid + 1]) {
      if (Find(a[l].R[i]) != Find(a[r].L[i])) {
        a[x].num--;
        Union(a[l].R[i], a[r].L[i]);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    a[x].L[i] = Find(a[l].L[i]);
    a[x].R[i] = Find(a[r].R[i]);
  }
}
void build(int x, int l, int r) {
  if (l == r) {
    a[x].num = 1;
    a[x].L[0] = a[x].R[0] = ++tot;
    for (int i = 1; i < n; ++i) {
      if (mp[i][r] == mp[i - 1][r]) {
        a[x].L[i] = a[x].R[i] = tot;
      } else {
        tot++, a[x].num++;
        a[x].L[i] = a[x].R[i] = tot;
      }
    }
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  push_up(x, mid);
}
void query(int x, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) {
    if (flag) {
      flag = 0;
      ans = a[x];
      return;
    } else {
      ans.num += a[x].num;
      for (int i = 0; i < n; ++i) {
        pre[ans.R[i]] = ans.R[i];
        pre[a[x].L[i]] = a[x].L[i];
        pre[a[x].R[i]] = a[x].R[i];
      }
      for (int i = 0; i < n; ++i) {
        if (mp[i][l - 1] == mp[i][l]) {
          if (Find(ans.R[i]) != Find(a[x].L[i])) {
            ans.num--;
            Union(ans.R[i], a[x].L[i]);
          }
        }
      }
      for (int i = 0; i < n; ++i) ans.R[i] = Find(a[x].R[i]);
      return;
    }
  }
  int mid = (l + r) >> 1;
  if (ql <= mid) query(x << 1, l, mid, ql, qr);
  if (mid < qr) query(x << 1 | 1, mid + 1, r, ql, qr);
}
int main(void) {
  scanf("%d%d%d", &n, &m, &q);
  init(n * m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) scanf("%d", &mp[i][j]);
  build(1, 0, m - 1);
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    flag = 1;
    query(1, 0, m - 1, x, y);
    printf("%d\n", ans.num);
  }
}
