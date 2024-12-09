#include <bits/stdc++.h>
using namespace std;
void getint(int &v) {
  char ch, fu = 0;
  for (ch = '*'; (ch < '0' || ch > '9') && ch != '-'; ch = getchar())
    ;
  if (ch == '-') fu = 1, ch = getchar();
  for (v = 0; ch >= '0' && ch <= '9'; ch = getchar()) v = v * 10 + ch - '0';
  if (fu) v = -v;
}
int n, m, t, q, L[1000010], R[1000010], T[1000010], a[1000010], ans[1000010];
void upd(int l, int r, int rt, int L, int R, int x) {
  if (l >= L && r <= R) {
    T[rt] = x;
    return;
  }
  int m = l + r >> 1;
  if (L <= m) upd(l, m, rt << 1, L, R, x);
  if (R > m) upd(m + 1, r, rt << 1 | 1, L, R, x);
}
int que(int l, int r, int rt, int x) {
  if (l == r) return T[rt];
  int m = l + r >> 1;
  if (x <= m)
    return max(que(l, m, rt << 1, x), T[rt]);
  else
    return max(que(m + 1, r, rt << 1 | 1, x), T[rt]);
}
int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) getint(a[i]);
  for (int i = 1; i <= n; i++)
    if (a[i] == 0) {
      t = i;
    }
  if (!t) {
    for (int i = 1; i <= n; i++)
      if (a[i] > a[t]) t = i;
  }
  if (a[t] && a[t] < q) return puts("NO"), 0;
  for (int i = 1; i <= q; i++) L[i] = n + 1, R[i] = 0;
  for (int i = 1; i <= n; i++)
    L[a[i]] = min(L[a[i]], i), R[a[i]] = max(R[a[i]], i);
  upd(1, n, 1, 1, n, 1);
  for (int i = 2; i <= q; i++) {
    if (L[i] > n) {
      upd(1, n, 1, t, t, i);
    } else {
      upd(1, n, 1, L[i], R[i], i);
    }
  }
  for (int i = 1; i <= n; i++) ans[i] = que(1, n, 1, i);
  for (int i = 1; i <= n; i++)
    if (a[i] && ans[i] != a[i]) return puts("NO"), 0;
  puts("YES");
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
