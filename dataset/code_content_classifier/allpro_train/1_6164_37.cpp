#include <bits/stdc++.h>
using namespace std;
namespace io {
const int size = 1 << 22 | 1;
char iBuf[size], *iS, *iT, c;
char getc() {
  if (iS == iT) {
    iS = iBuf;
    iT = iBuf + fread(iBuf, 1, size, stdin);
  }
  if (iS == iT) return EOF;
  return *iS++;
}
template <class T>
void qread(T &x) {
  int f = 1;
  for (c = getc(); c < '0' || c > '9'; c = getc())
    if (c == '-') f = -1;
  for (x = 0; c >= '0' && c <= '9'; c = getc())
    x = (x << 3) + (x << 1) + (c & 15);
  x *= f;
}
}  // namespace io
const int maxn = 500005;
const int INF = 0x3f3f3f3f;
int T, n, cnt;
int a[maxn], last[maxn], val[maxn];
namespace Segtree {
int mn[maxn * 4], tag[maxn * 4];
void pushup(int cur) {
  mn[cur] = min(mn[cur << 1], mn[cur << 1 | 1]) + tag[cur];
}
void build(int cur, int l, int r) {
  tag[cur] = 0;
  if (l == r) {
    mn[cur] = l;
    return;
  }
  int mid = l + r >> 1;
  build(cur << 1, l, mid);
  build(cur << 1 | 1, mid + 1, r);
  pushup(cur);
}
void update(int cur, int l, int r, int vl, int vr, int val) {
  if (vl > vr) return;
  if (l >= vl && r <= vr) {
    mn[cur] += val;
    tag[cur] += val;
    return;
  }
  int mid = l + r >> 1;
  if (mid >= vl) update(cur << 1, l, mid, vl, vr, val);
  if (mid < vr) update(cur << 1 | 1, mid + 1, r, vl, vr, val);
  pushup(cur);
}
int query(int cur, int l, int r, int vl, int vr) {
  if (l >= vl && r <= vr) return mn[cur];
  int mid = l + r >> 1;
  int sl = mid >= vl ? query(cur << 1, l, mid, vl, vr) : INF;
  int sr = mid < vr ? query(cur << 1 | 1, mid + 1, r, vl, vr) : INF;
  return min(sl, sr) + tag[cur];
}
}  // namespace Segtree
bool check(int t) {
  for (int i = 1; i <= n; i++) val[i] = 0;
  int c = 0;
  for (int i = 1; i <= n && c < t; i++)
    if (!a[i]) c++, val[i] = c;
  c = 0;
  for (int i = n; i >= 1 && c < t; i--)
    if (!a[i]) val[i] = 2 * t - c, c++;
  for (int i = 1; i <= n; i++) last[i] = 0;
  Segtree::build(1, 1, t);
  int lst = 0;
  for (int i = 1; i <= n; i++) {
    if (val[i] >= 1 && val[i] <= t)
      lst = val[i];
    else if (val[i] > t && val[i] <= 2 * t) {
      if (Segtree::query(1, 1, t, 1, val[i] - t) < val[i] - t + 1) return false;
    } else if (a[i] > 0) {
      Segtree::update(1, 1, t, last[a[i]] + 1, lst, 1);
      last[a[i]] = lst;
    }
  }
  return true;
}
int main() {
  io::qread(T);
  while (T--) {
    cnt = 0;
    io::qread(n);
    for (int i = 1; i <= n; i++) {
      io::qread(a[i]);
      cnt += (a[i] == 0);
    }
    int l = 0, r = cnt / 2;
    while (l < r) {
      int mid = l + r + 1 >> 1;
      if (check(mid))
        l = mid;
      else
        r = mid - 1;
    }
    printf("%d\n", l);
  }
  return 0;
}
