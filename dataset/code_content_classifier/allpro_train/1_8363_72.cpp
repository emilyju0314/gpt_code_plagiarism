#include <bits/stdc++.h>
using namespace std;
const int RLEN = 1 << 20 | 1;
inline char gc() {
  static char ibuf[RLEN], *ib, *ob;
  (ib == ob) && (ob = (ib = ibuf) + fread(ibuf, 1, RLEN, stdin));
  return (ib == ob) ? EOF : *ib++;
}
inline int read() {
  char ch = gc();
  int res = 0;
  bool f = 1;
  while (!isdigit(ch)) f ^= ch == '-', ch = gc();
  while (isdigit(ch)) res = (res + (res << 2) << 1) + (ch ^ 48), ch = gc();
  return f ? res : -res;
}
inline long long readll() {
  char ch = gc();
  long long res = 0;
  bool f = 1;
  while (!isdigit(ch)) f ^= ch == '-', ch = gc();
  while (isdigit(ch)) res = (res + (res << 2) << 1) + (ch ^ 48), ch = gc();
  return f ? res : -res;
}
inline int readstring(char *s) {
  int top = 0;
  char ch = gc();
  while (isspace(ch)) ch = gc();
  while (!isspace(ch) && ch != EOF) s[++top] = ch, ch = gc();
  s[top + 1] = '\0';
  return top;
}
template <typename tp>
inline void chemx(tp &a, tp b) {
  a = max(a, b);
}
template <typename tp>
inline void chemn(tp &a, tp b) {
  a = min(a, b);
}
const int N = 100005;
const long long INF = 1e18;
int n, K, g[N], w[N];
long long a[N], b[N], c[N], d[N];
namespace Seg {
const int N = ::N << 2;
long long tag[N], mxd[N], mx[N];
inline void pushnow(int u, long long k) { tag[u] += k, mx[u] += k; }
inline void pushdown(int u) {
  if (!tag[u]) return;
  pushnow((u << 1), tag[u]);
  pushnow(((u << 1) | 1), tag[u]);
  tag[u] = 0;
}
inline void pushup(int u) { mx[u] = max(mx[(u << 1)], mx[((u << 1) | 1)]); }
void build(int u, int l, int r) {
  mx[u] = mxd[u] = -INF;
  if (l == r) {
    return;
  }
  build((u << 1), l, ((l + r) >> 1)),
      build(((u << 1) | 1), ((l + r) >> 1) + 1, r);
}
int st, des, p;
long long k;
void insert(int u, int l, int r) {
  if (l == r) {
    mx[u] = mxd[u] = k;
    return;
  }
  pushdown(u);
  if (p <= ((l + r) >> 1))
    insert((u << 1), l, ((l + r) >> 1));
  else
    insert(((u << 1) | 1), ((l + r) >> 1) + 1, r);
  pushup(u);
  mxd[u] = max(mxd[(u << 1)], mxd[((u << 1) | 1)]);
}
void upd(int u, int l, int r) {
  if (st <= l && r <= des) return pushnow(u, k);
  pushdown(u);
  if (st <= ((l + r) >> 1)) upd((u << 1), l, ((l + r) >> 1));
  if (((l + r) >> 1) < des) upd(((u << 1) | 1), ((l + r) >> 1) + 1, r);
  pushup(u);
}
int query(int u, int l, int r, long long premx) {
  if (l == r) return l;
  pushdown(u);
  if (des <= ((l + r) >> 1)) return query((u << 1), l, ((l + r) >> 1), premx);
  if (((l + r) >> 1) < st)
    return query(((u << 1) | 1), ((l + r) >> 1) + 1, r, premx);
  if (max(mx[(u << 1)], premx) <= mxd[((u << 1) | 1)] + K)
    return query(((u << 1) | 1), ((l + r) >> 1) + 1, r,
                 max(premx, mx[(u << 1)]));
  return query((u << 1), l, ((l + r) >> 1), premx);
}
void write(int u, int l, int r) {
  if (l == r) {
    cout << mx[u] << " ";
    return;
  }
  pushdown(u);
  write((u << 1), l, ((l + r) >> 1)),
      write(((u << 1) | 1), ((l + r) >> 1) + 1, r);
}
inline void insert(int _p, long long _k) {
  p = _p, k = _k;
  insert(1, 1, n);
}
inline void update(int _st, int _des, long long _k) {
  st = _st, des = _des, k = _k;
  upd(1, 1, n);
}
inline int query(int _st, int _des) {
  st = _st, des = _des;
  return query(1, 1, n, -INF);
}
}  // namespace Seg
int stk[N], top;
int main() {
  n = read(), K = read();
  for (int i = 1; i < n; i++) w[i] = read(), b[i] = b[i - 1] + w[i];
  for (int i = 1; i <= n; i++) g[i] = read(), a[i] = a[i - 1] + g[i];
  for (int i = 1; i <= n; i++)
    c[i] = a[i - 1] - b[i - 1], d[i] = a[i] - b[i - 1];
  Seg::build(1, 1, n);
  int ans = 0;
  for (int i = n; i; i--) {
    while (top > 0 && c[stk[top]] >= c[i]) {
      if (top > 1)
        Seg::update(stk[top - 1] - 1, n, -(c[stk[top]] - c[stk[top - 1]]));
      top--;
    }
    stk[++top] = i, Seg::insert(i, d[i]);
    if (top > 1)
      Seg::update(stk[top - 1] - 1, n, c[stk[top]] - c[stk[top - 1]]);
    int l = 1, r = top, res = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (c[i] - c[stk[mid]] > K)
        res = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    if (res == -1)
      res = n;
    else
      res = stk[res] - 1;
    chemx(ans, Seg::query(i, res) - i + 1);
  }
  cout << ans << '\n';
}
