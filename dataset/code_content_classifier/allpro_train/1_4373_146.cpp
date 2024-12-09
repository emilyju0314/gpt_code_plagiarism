#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
int cnt[26][MAXN * 4 + 5], ass[MAXN * 4 + 5];
int a[MAXN + 5];
int n, q;
void pushup(int i, int x) { cnt[i][x] = cnt[i][x << 1] + cnt[i][x << 1 | 1]; }
void pushdown(int x, int tmp1, int tmp2) {
  if (ass[x] != -1) {
    for (int i = 0; i < 26; i++) cnt[i][x << 1] = cnt[i][x << 1 | 1] = 0;
    cnt[ass[x]][x << 1] = tmp1;
    cnt[ass[x]][x << 1 | 1] = tmp2;
    ass[x << 1] = ass[x << 1 | 1] = ass[x];
    ass[x] = -1;
  }
}
void build(int i, int l, int r, int x) {
  if (l == r) {
    cnt[i][x] = (a[l] == i);
    ass[x] = -1;
    return;
  } else {
    int mid = (l + r) / 2;
    build(i, l, mid, x << 1);
    build(i, mid + 1, r, x << 1 | 1);
    ass[x] = -1;
    pushup(i, x);
  }
}
int query(int i, int l, int r, int x, int ql, int qr) {
  if (l == ql && r == qr) return cnt[i][x];
  int mid = (l + r) >> 1;
  pushdown(x, mid - l + 1, r - mid);
  if (qr <= mid)
    return query(i, l, mid, x << 1, ql, qr);
  else if (ql > mid)
    return query(i, mid + 1, r, x << 1 | 1, ql, qr);
  else
    return query(i, l, mid, x << 1, ql, mid) +
           query(i, mid + 1, r, x << 1 | 1, mid + 1, qr);
}
void update(int l, int r, int x, int ul, int ur, int k) {
  if (l == ul && r == ur) {
    for (int i = 0; i < 26; i++) cnt[i][x] = 0;
    cnt[k][x] = r - l + 1;
    ass[x] = k;
    return;
  }
  if (l == r) return;
  int mid = (l + r) >> 1;
  pushdown(x, mid - l + 1, r - mid);
  if (ur <= mid)
    update(l, mid, x << 1, ul, ur, k);
  else if (ul > mid)
    update(mid + 1, r, x << 1 | 1, ul, ur, k);
  else {
    update(l, mid, x << 1, ul, mid, k);
    update(mid + 1, r, x << 1 | 1, mid + 1, ur, k);
  }
  for (int i = 0; i < 26; i++) {
    pushup(i, x);
  }
}
int main() {
  scanf("%d%d", &n, &q);
  getchar();
  for (int i = 1; i <= n; i++) {
    char c;
    scanf("%c", &c);
    a[i] = c - 'a';
  }
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < 26; i++) {
    build(i, 1, n, 1);
  }
  int t[26];
  for (int i = 1; i <= q; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    int tot = 0;
    for (int j = 0; j < 26; j++) t[j] = query(j, 1, n, 1, x, y);
    for (int j = 0; j < 26; j++) {
      if (t[j]) {
        if (z)
          update(1, n, 1, x + tot, x + tot + t[j] - 1, j);
        else
          update(1, n, 1, y - tot - t[j] + 1, y - tot, j);
        tot += t[j];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 26; j++) {
      if (query(j, 1, n, 1, i, i)) {
        printf("%c", 'a' + j);
        break;
      }
    }
  }
  printf("\n");
  return 0;
}
