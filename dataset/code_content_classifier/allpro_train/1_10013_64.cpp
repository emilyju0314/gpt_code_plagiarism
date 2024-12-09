#include <bits/stdc++.h>
using namespace std;
struct info {
  vector<long long> d = vector<long long>(10);
  vector<char> c = vector<char>(10);
  bool hasCarry = 0;
};
info createN(int val) {
  info r;
  r.d = vector<long long>(10);
  r.c = vector<char>(10);
  for (int i = 0; i < 10; i++) r.c[i] = i;
  int p = 1;
  while (val) {
    r.d[val % 10] += p;
    p *= 10;
    val /= 10;
  }
  r.hasCarry = 0;
  return r;
}
void updateR(info &p, int u, int v) {
  for (int i = 0; i < 10; i++) {
    if (p.c[i] == u) {
      p.c[i] = v;
    }
  }
  long long d = p.d[u];
  p.d[u] = 0;
  p.d[v] += d;
  p.hasCarry = 1;
}
void updateR(info &p, const vector<char> &c) {
  vector<char> tc(10);
  for (int i = 0; i < 10; i++) {
    tc[i] = c[p.c[i]];
  }
  p.c = tc;
  vector<long long> d(10);
  for (int i = 0; i < 10; i++) {
    d[c[i]] += p.d[i];
  }
  p.d = d;
  p.hasCarry = 1;
}
void join(info &p, const info &l, const info &r) {
  for (int i = 0; i < 10; i++) {
    p.d[i] = l.d[i] + r.d[i];
    p.c[i] = i;
  }
  p.hasCarry = 0;
}
info st[400000];
int N, a[100010];
void create(int n = 1, int l = 0, int r = N - 1) {
  if (l == r) {
    st[n] = createN(a[r]);
  } else {
    int m = (l + r) / 2;
    create(2 * n, l, m);
    create(2 * n + 1, m + 1, r);
    join(st[n], st[2 * n], st[2 * n + 1]);
  }
}
long long query(int x, int y, int n = 1, int l = 0, int r = N - 1) {
  if (x <= l && r <= y) {
    long long g = 0;
    for (int i = 1; i < 10; i++) g += st[n].d[i] * i;
    return g;
  } else {
    int m = (l + r) / 2;
    if (st[n].hasCarry) {
      updateR(st[2 * n], st[n].c);
      updateR(st[2 * n + 1], st[n].c);
      join(st[n], st[2 * n], st[2 * n + 1]);
      st[n].hasCarry = 0;
    }
    long long g = 0;
    if (x <= m) g += query(x, y, 2 * n, l, m);
    if (y > m) g += query(x, y, 2 * n + 1, m + 1, r);
    return g;
  }
}
void update(int x, int y, int u, int v, int n = 1, int l = 0, int r = N - 1) {
  if (x <= l && r <= y) {
    updateR(st[n], u, v);
  } else {
    int m = (l + r) / 2;
    if (st[n].hasCarry) {
      updateR(st[2 * n], st[n].c);
      updateR(st[2 * n + 1], st[n].c);
      st[n].hasCarry = 0;
    }
    if (x <= m) update(x, y, u, v, 2 * n, l, m);
    if (y > m) update(x, y, u, v, 2 * n + 1, m + 1, r);
    join(st[n], st[2 * n], st[2 * n + 1]);
  }
}
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  N = n;
  create();
  while (q--) {
    int op, l, r;
    scanf("%d%d%d", &op, &l, &r);
    l--, r--;
    if (op == 1) {
      int u, v;
      scanf("%d%d", &u, &v);
      update(l, r, u, v);
    } else {
      printf("%I64d\n", query(l, r));
    }
  }
}
