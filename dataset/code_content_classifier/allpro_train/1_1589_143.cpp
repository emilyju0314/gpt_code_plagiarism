#include <bits/stdc++.h>
using namespace std;
int n, r[500005];
int f[24][500005];
int Min[500005 * 8], key[500005];
void insert(int now, int l, int r, int pos, int val) {
  if (pos > r || pos < l) return;
  if (l == r) {
    Min[now] = l;
    key[l] = val;
    return;
  }
  int mid = (l + r) >> 1;
  insert(now << 1, l, mid, pos, val);
  insert(now << 1 | 1, mid + 1, r, pos, val);
  Min[now] = key[Min[now << 1]] < key[Min[now << 1 | 1]] ? Min[now << 1]
                                                         : Min[now << 1 | 1];
}
int Query(int now, int l, int r, int ql, int qr) {
  if (qr < ql) return 0;
  if (r < ql || l > qr) return 0;
  if (ql <= l && r <= qr) return Min[now];
  int mid = (l + r) >> 1;
  int pos1 = Query(now << 1, l, mid, ql, qr),
      pos2 = Query(now << 1 | 1, mid + 1, r, ql, qr);
  return key[pos1] < key[pos2] ? pos1 : pos2;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &r[i]), r[i + n] = r[i];
  memset(Min, 0, sizeof Min);
  memset(key, 0x3f, sizeof key);
  for (int i = 1; i <= 2 * n; i++) {
    int pos1 = Query(1, 1, 2 * n, max(max(1, i - r[i]), i - n + 1), i);
    f[0][i] = pos1;
    insert(1, 1, 2 * n, i, i - r[i]);
  }
  for (int j = 1; j < 24; j++)
    for (int i = 1; i <= 2 * n; i++) f[j][i] = f[j - 1][f[j - 1][i]];
  long long ans = 0;
  for (int i = 2 * n; i > n; i--) {
    int u = i;
    for (int j = 24 - 1; j >= 0; j--) {
      if (f[j][u] - r[f[j][u]] > i - n + 1) u = f[j][u], ans += (1 << j);
    }
    if (u - r[u] <= i - n + 1)
      ans++;
    else
      ans += 2;
  }
  printf("%I64d", ans);
}
