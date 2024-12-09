#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0, w = 1, ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = (s << 3) + (s << 1) + ch - 48;
    ch = getchar();
  }
  return s * w;
}
const int maxn = 3e5 + 50, mod = 1e9;
int n, m, a[maxn], fib[maxn];
struct mat {
  int a[3][3];
  mat() { memset(a, 0, sizeof(a)); }
  int* operator[](int x) { return a[x]; }
  mat operator+(mat b) const {
    mat c;
    for (int i = 0; i <= 1; i++)
      for (int j = 0; j <= 1; j++) c[i][j] = (a[i][j] + b[i][j]) % mod;
    return c;
  }
  mat operator*(mat b) const {
    mat c;
    for (int i = 0; i <= 1; i++)
      for (int j = 0; j <= 1; j++)
        for (int k = 0; k <= 1; k++)
          c[i][j] = (c[i][j] + a[i][k] * 1ll * b[k][j] * 1ll % mod) % mod;
    return c;
  }
  mat operator*(int b) const {
    mat c;
    for (int i = 0; i <= 1; i++)
      for (int j = 0; j <= 1; j++) c[i][j] = a[i][j] * 1ll * b % mod;
    return c;
  }
} TR, E, OO, pw[maxn];
void DEBUG(int x) {
  if (x < 0) cout << "WDNMD" << endl, exit(0);
}
void init() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  fib[0] = 1;
  fib[1] = 1;
  for (int i = 2; i <= n; i++) fib[i] = fib[i - 1] + fib[i - 2], fib[i] %= mod;
  for (int i = 1; i <= n; i++) fib[i] = fib[i - 1] + fib[i], fib[i] %= mod;
  TR[0][0] = 0;
  TR[0][1] = 1;
  TR[1][0] = 1;
  TR[1][1] = 1;
  E[0][0] = E[1][1] = 1;
  pw[0] = E;
  pw[1] = TR;
  for (int i = 2; i <= n; i++) pw[i] = TR * pw[i - 1];
}
inline void add(int& x, int y) {
  y %= mod;
  x += y;
  x %= mod;
}
namespace SEG {
struct node {
  int l, r, tag;
  mat sum;
} tree[maxn * 4];
void addtag(int x, int t) {
  add(tree[x].tag, t);
  add(tree[x].sum[0][0], t * 1ll * fib[tree[x].r - tree[x].l] % mod);
  add(tree[x].sum[1][0],
      t * 1ll * (fib[tree[x].r - tree[x].l + 1] - 1 + mod) % mod);
}
void pushdown(int x) {
  if (tree[x].tag != 0) {
    int t = tree[x].tag;
    tree[x].tag = 0;
    addtag(x << 1, t);
    addtag(x << 1 | 1, t);
  }
}
void pushup(int x) {
  tree[x].sum = tree[x << 1].sum +
                pw[tree[x << 1].r - tree[x << 1].l + 1] * tree[x << 1 | 1].sum;
}
void build(int x, int l, int r) {
  tree[x].l = l;
  tree[x].r = r;
  tree[x].tag = 0;
  if (l == r) {
    tree[x].sum[0][0] = a[l];
    tree[x].sum[1][0] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  pushup(x);
}
void cover(int x, int pos, int val) {
  if (tree[x].l > pos || tree[x].r < pos) return;
  if (tree[x].l == tree[x].r) {
    tree[x].tag = 0;
    tree[x].sum[0][0] = val;
    tree[x].sum[1][0] = val;
    return;
  }
  pushdown(x);
  cover(x << 1, pos, val);
  cover(x << 1 | 1, pos, val);
  pushup(x);
}
void modify(int x, int l, int r, int val) {
  if (tree[x].l > r || tree[x].r < l) return;
  if (tree[x].l >= l && tree[x].r <= r) {
    addtag(x, val);
    return;
  }
  pushdown(x);
  if (l <= tree[x << 1].r) modify(x << 1, l, r, val);
  if (r >= tree[x << 1 | 1].l) modify(x << 1 | 1, l, r, val);
  pushup(x);
}
mat query(int x, int l, int r) {
  if (tree[x].l >= l && tree[x].r <= r) {
    return pw[tree[x].l - l] * tree[x].sum;
  }
  if (tree[x].l > r || tree[x].r < l) return OO;
  pushdown(x);
  return query(x << 1, l, r) + query(x << 1 | 1, l, r);
}
};  // namespace SEG
signed main() {
  init();
  SEG::build(1, 1, n);
  int M = m;
  while (M--) {
    int op = read(), x = read(), y = read(), z;
    if (op == 1) {
      SEG::cover(1, x, y);
    }
    if (op == 2) {
      mat res = SEG::query(1, x, y);
      printf("%d\n", res[0][0]);
    }
    if (op == 3) {
      z = read();
      SEG::modify(1, x, y, z);
    }
  }
  return 0;
}
