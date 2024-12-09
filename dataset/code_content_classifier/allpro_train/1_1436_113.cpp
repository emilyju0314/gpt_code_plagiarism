#include <bits/stdc++.h>
struct val {
  long long x;
  int y, d;
  val *p, *l, *r;
} g1[100001], g2[100001], *rt1[100001], *rt2[100001], *nil = g1;
struct node {
  long long x;
  int y;
  bool operator<(const node &b) const { return x < b.x; }
} a[100001];
struct vale {
  long long x;
  int y;
  bool operator<(const vale &b) const { return x > b.x; }
} c[100001];
using namespace std;
int n, g[100001], h[100001], fa[100001], d[100001], wt, ss[19];
char fl[1 << 23], *A = fl;
long long f[100001], e[100001], b[100001];
void read(int &x) {
  char c;
  for (x = 0; '0' > (c = *A++) || c > '9';)
    ;
  while ('0' <= c && c <= '9') x = (x << 3) + (x << 1) + c - 48, (c = *A++);
}
void read(long long &x) {
  char c;
  for (x = 0; '0' > (c = *A++) || c > '9';)
    ;
  while ('0' <= c && c <= '9') x = (x << 3) + (x << 1) + c - 48, (c = *A++);
}
void print(long long x) {
  if (!x)
    putchar(48);
  else {
    for (wt = 0; x; ss[++wt] = x % 10, x /= 10)
      ;
    for (; wt; putchar(ss[wt--] + 48))
      ;
  }
}
val *mg1(val *x, val *y) {
  return x == nil
             ? y
             : (y == nil
                    ? x
                    : (x->x < y->x
                           ? ((x->r = mg1(x->r, y))->p = x,
                              x->l->d < x->r->d ? (swap(x->l, x->r), 0) : 0,
                              x->d = x->l->d + 1, x)
                           : ((y->r = mg1(y->r, x))->p = y,
                              y->l->d < y->r->d ? (swap(y->l, y->r), 0) : 0,
                              y->d = y->l->d + 1, y)));
}
val *mg2(val *x, val *y) {
  return x == nil
             ? y
             : (y == nil
                    ? x
                    : (x->x > y->x
                           ? ((x->r = mg2(x->r, y))->p = x,
                              x->l->d < x->r->d ? (swap(x->l, x->r), 0) : 0,
                              x->d = x->l->d + 1, x)
                           : ((y->r = mg2(y->r, x))->p = y,
                              y->l->d < y->r->d ? (swap(y->l, y->r), 0) : 0,
                              y->d = y->l->d + 1, y)));
}
void fix_min(long long t1, int z) {
  int tmp, x, LIA;
  if (a[x = g[z]].x != t1)
    if (a[x].x = t1, x > 1 && a[x] < a[x >> 1])
      for (; x > 1 && a[x] < a[x >> 1];
           swap(a[x], a[x >> 1]), swap(g[a[x].y], g[a[x >> 1].y]), x >>= 1)
        ;
    else
      for (; (x << 1) <= n;) {
        if (a[tmp = x << 1] < a[LIA = x]) LIA = tmp;
        if ((tmp |= 1) <= n && a[tmp] < a[LIA]) LIA = tmp;
        if (LIA != x)
          swap(a[LIA], a[x]), swap(g[a[LIA].y], g[a[x].y]), x = LIA;
        else
          break;
      }
}
void fix_max(long long t1, int z) {
  int tmp, x, LIA;
  if (c[x = h[z]].x != t1)
    if (c[x].x = t1, x > 1 && c[x] < c[x >> 1])
      for (; x > 1 && c[x] < c[x >> 1];
           swap(c[x], c[x >> 1]), swap(h[c[x].y], h[c[x >> 1].y]), x >>= 1)
        ;
    else
      for (; (x << 1) <= n;) {
        if (c[tmp = x << 1] < c[LIA = x]) LIA = tmp;
        if ((tmp |= 1) <= n && c[tmp] < c[LIA]) LIA = tmp;
        if (LIA != x)
          swap(c[LIA], c[x]), swap(h[c[LIA].y], h[c[x].y]), x = LIA;
        else
          break;
      }
}
void fix(int x) {
  if (g1[x].p == nil)
    (rt1[fa[x]] = mg1(g1[x].l, g1[x].r))->p = nil;
  else if (g1[x].p->l == &g1[x])
    (g1[x].p->l = mg1(g1[x].l, g1[x].r))->p = g1[x].p;
  else
    (g1[x].p->r = mg1(g1[x].l, g1[x].r))->p = g1[x].p;
  g1[x].x = f[x], g1[x].l = g1[x].r = nil,
  (rt1[fa[x]] = mg1(rt1[fa[x]], &g1[x]))->p = nil;
  if (g2[x].p == nil)
    (rt2[fa[x]] = mg2(g2[x].l, g2[x].r))->p = nil;
  else if (g2[x].p->l == &g2[x])
    (g2[x].p->l = mg2(g2[x].l, g2[x].r))->p = g2[x].p;
  else
    (g2[x].p->r = mg2(g2[x].l, g2[x].r))->p = g2[x].p;
  g2[x].x = f[x], g2[x].l = g2[x].r = nil,
  (rt2[fa[x]] = mg2(rt2[fa[x]], &g2[x]))->p = nil;
}
void alter(int z, int x, int y, int LAx, int LAy) {
  long long t1 = e[x], t3 = e[y];
  int t2 = b[x] % d[x], t4 = b[y] % d[y];
  f[y] += b[y] % (++d[y]) + e[z] - t4, e[y] = b[y] / d[y], f[LAy] += e[y] - t3,
                                       f[y] += e[y] - t3;
  f[x] += b[x] % (--d[x]) - e[z] - t2, e[x] = b[x] / d[x], f[LAx] += e[x] - t1,
                                       f[x] += e[x] - t1;
  if (LAx == LAy) {
    if (e[y] + e[x] != t1 + t3) fix(LAx);
  } else {
    if (e[y] != t3) fix(LAy);
    if (e[x] != t1) fix(LAx);
  }
  fix(x), fix(y);
  if (g1[z].p == nil)
    (rt1[x] = mg1(g1[z].l, g1[z].r))->p = nil;
  else if (g1[z].p->l == &g1[z])
    (g1[z].p->l = mg1(g1[z].l, g1[z].r))->p = g1[z].p;
  else
    (g1[z].p->r = mg1(g1[z].l, g1[z].r))->p = g1[z].p;
  g1[z].x = f[z], g1[z].l = g1[z].r = nil,
  (rt1[fa[z] = y] = mg1(rt1[y], &g1[z]))->p = nil;
  if (g2[z].p == nil)
    (rt2[x] = mg2(g2[z].l, g2[z].r))->p = nil;
  else if (g2[z].p->l == &g2[z])
    (g2[z].p->l = mg2(g2[z].l, g2[z].r))->p = g2[z].p;
  else
    (g2[z].p->r = mg2(g2[z].l, g2[z].r))->p = g2[z].p;
  g2[z].x = f[z], g2[z].l = g2[z].r = nil,
  (rt2[y] = mg2(rt2[y], &g2[z]))->p = nil;
  fix_max(e[fa[LAx]] + rt2[fa[LAx]]->x, rt2[fa[LAx]]->y);
  fix_max(e[fa[LAy]] + rt2[fa[LAy]]->x, rt2[fa[LAy]]->y);
  fix_max(rt2[LAx]->x + e[LAx], rt2[LAx]->y);
  fix_max(rt2[LAy]->x + e[LAy], rt2[LAy]->y);
  if (rt2[x] != nil) fix_max(rt2[x]->x + e[x], rt2[x]->y);
  fix_max(rt2[y]->x + e[y], rt2[y]->y);
  fix_min(e[fa[LAx]] + rt1[fa[LAx]]->x, rt1[fa[LAx]]->y);
  fix_min(e[fa[LAy]] + rt1[fa[LAy]]->x, rt1[fa[LAy]]->y);
  fix_min(rt1[LAx]->x + e[LAx], rt1[LAx]->y);
  fix_min(rt1[LAy]->x + e[LAy], rt1[LAy]->y);
  if (rt1[x] != nil) fix_min(rt1[x]->x + e[x], rt1[x]->y);
  fix_min(rt1[y]->x + e[y], rt1[y]->y);
}
void dfs(int x) {
  long long t1 = e[fa[a[x].y]] + f[a[x].y];
  int tmp = a[x].y;
  if (a[x].x != t1) {
    if ((x << 1) <= n) dfs(x << 1);
    if ((x << 1 | 1) <= n) dfs(x << 1 | 1);
    fix_min(t1, tmp);
  }
}
void vfs(int x) {
  long long t1 = e[fa[c[x].y]] + f[c[x].y];
  int tmp = c[x].y;
  if (c[x].x != t1) {
    if ((x << 1) <= n) vfs(x << 1);
    if ((x << 1 | 1) <= n) vfs(x << 1 | 1);
    fix_max(t1, tmp);
  }
}
int main() {
  int test, i, x, y, tmp, LIA;
  for (*(fl + fread(fl, 1, 1 << 23, stdin)) = EOF, read(n), read(test), i = 1;
       i <= n; d[i] = 2, rt1[i] = rt2[i] = nil, read(b[i++]))
    ;
  for (i = 1; i <= n; read(fa[i]), d[fa[i]]++, i++)
    ;
  for (i = 1; i <= n;
       f[i] += b[i] % d[i] + (e[i] = b[i] / d[i]), f[fa[i]] += e[i], i++)
    ;
  for (i = 1; i <= n; g1[i] = g2[i] = (val){f[i], i, 1, nil, nil, nil},
      (rt1[fa[i]] = mg1(rt1[fa[i]], &g1[i]))->p = nil,
      (rt2[fa[i]] = mg2(rt2[fa[i]], &g2[i]))->p = nil,
      a[i] = (node){f[i] + e[fa[i]], i}, c[i] = (vale){f[i] + e[fa[i]], i}, i++)
    ;
  for (sort(a + 1, a + n + 1), sort(c + 1, c + n + 1), i = 1; i <= n;
       g[a[i].y] = i, h[c[i].y] = i, i++)
    ;
  for (; test--;) switch (read(x), x) {
      case 1:
        if (read(x), read(y), fa[x] != y) alter(x, fa[x], y, fa[fa[x]], fa[y]);
        break;
      case 2:
        read(x), print(e[fa[x]] + f[x]), putchar('\n');
        break;
      case 3:
        long long t1;
        for (; (t1 = e[fa[a[1].y]] + f[a[1].y]) != a[1].x;)
          for (a[x = 1].x = t1; (x << 1) <= n;) {
            if (a[tmp = x << 1] < a[LIA = x]) LIA = tmp;
            if ((tmp |= 1) < n && a[tmp] < a[LIA]) LIA = tmp;
            if (LIA != x)
              swap(a[LIA], a[x]), swap(g[a[LIA].y], g[a[x].y]), x = LIA;
            else
              break;
          }
        for (; (t1 = e[fa[c[1].y]] + f[c[1].y]) != c[1].x;)
          for (c[x = 1].x = t1; (x << 1) <= n;) {
            if (c[tmp = x << 1] < c[LIA = x]) LIA = tmp;
            if ((tmp |= 1) < n && c[tmp] < c[LIA]) LIA = tmp;
            if (LIA != x)
              swap(c[LIA], c[x]), swap(h[c[LIA].y], h[c[x].y]), x = LIA;
            else
              break;
          }
        print(a[1].x), putchar(' '), print(c[1].x), putchar('\n');
        break;
    }
}
