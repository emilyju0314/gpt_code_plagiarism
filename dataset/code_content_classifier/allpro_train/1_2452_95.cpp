#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
namespace fastIO {
bool IOerror = 0;
inline char nc() {
  static char buf[100000], *p1 = buf + 100000, *pend = buf + 100000;
  if (p1 == pend) {
    p1 = buf;
    pend = buf + fread(buf, 1, 100000, stdin);
    if (pend == p1) {
      IOerror = 1;
      return -1;
    }
  }
  return *p1++;
}
inline bool blank(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
template <class T>
inline bool read(T &x) {
  bool sign = 0;
  char ch = nc();
  x = 0;
  for (; blank(ch); ch = nc())
    ;
  if (IOerror) return false;
  if (ch == '-') sign = 1, ch = nc();
  for (; ch >= '0' && ch <= '9'; ch = nc()) x = (x << 1) + (x << 3) + (ch ^ 48);
  if (sign) x = -x;
  return true;
}
inline bool read(double &x) {
  bool sign = 0;
  char ch = nc();
  x = 0;
  for (; blank(ch); ch = nc())
    ;
  if (IOerror) return false;
  if (ch == '-') sign = 1, ch = nc();
  for (; ch >= '0' && ch <= '9'; ch = nc()) x = x * 10.0 + (ch ^ 48);
  if (ch == '.') {
    double tmp = 1;
    ch = nc();
    for (; ch >= '0' && ch <= '9'; ch = nc()) tmp /= 10.0, x += tmp * (ch ^ 48);
  }
  if (sign) x = -x;
  return true;
}
inline bool read(char *s) {
  char ch = nc();
  for (; blank(ch); ch = nc())
    ;
  if (IOerror) return false;
  for (; !blank(ch) && !IOerror; ch = nc()) *s++ = ch;
  *s = 0;
  return true;
}
template <class T, class... U>
bool read(T &h, U &...t) {
  return read(h) && read(t...);
}
};  // namespace fastIO
using namespace fastIO;
const int maxn = 1e6 + 10;
int n, m, a[maxn];
template <class T>
inline void chkmax(T &x, const T &y) {
  if (y > x) x = y;
  return;
}
struct Node {
  int lazy;
  int up, down, cnt[2];
} tree[maxn << 2];
inline void pushdown(int k) {
  for (register int i = 0; i < 2; ++i) {
    tree[k].cnt[i] = tree[k << 1].cnt[i] + tree[k << 1 | 1].cnt[i];
  }
  tree[k].up = max(tree[k << 1].up + tree[k << 1 | 1].cnt[1],
                   tree[k << 1].cnt[0] + tree[k << 1 | 1].up);
  chkmax(tree[k].up, tree[k << 1].cnt[0] + tree[k << 1 | 1].cnt[1]);
  tree[k].down = max(tree[k << 1].down + tree[k << 1 | 1].cnt[0],
                     tree[k << 1].cnt[1] + tree[k << 1 | 1].down);
  chkmax(tree[k].down, tree[k << 1].cnt[1] + tree[k << 1 | 1].cnt[0]);
}
inline void push(int k) {
  tree[k].lazy = !tree[k].lazy;
  swap(tree[k].cnt[1], tree[k].cnt[0]);
  swap(tree[k].down, tree[k].up);
}
void update(int l, int r, int L, int R, int i) {
  if (r < L || l > R) return;
  if (r <= R && l >= L) {
    push(i);
    return;
  }
  if (tree[i].lazy) {
    tree[i].lazy = false;
    push(i << 1);
    push(i << 1 | 1);
  }
  int mid = (l + r) >> 1;
  if (mid >= r) {
    update(l, mid, L, R, i << 1);
  } else if (l > mid) {
    update(mid + 1, r, L, R, i << 1 | 1);
  } else {
    update(l, mid, L, R, i << 1);
    update(mid + 1, r, L, R, i << 1 | 1);
  }
  pushdown(i);
}
void build(int k, int l, int r) {
  if (l == r) {
    tree[k].up = tree[k].down = 1;
    tree[k].cnt[a[l]] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(k << 1, l, mid);
  build(k << 1 | 1, mid + 1, r);
  pushdown(k);
}
char str[maxn];
int main() {
  read(n, m, str);
  for (register int i = 0; i < n; ++i) a[i + 1] = str[i] == '7' ? 1 : 0;
  build(1, 1, n);
  while (m--) {
    read(str);
    if (str[0] == 'c') {
      printf("%d\n", tree[1].up);
    } else {
      int l, r;
      read(l, r);
      update(1, n, l, r, 1);
    }
  }
}
