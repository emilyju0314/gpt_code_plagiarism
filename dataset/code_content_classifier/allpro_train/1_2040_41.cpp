#include <bits/stdc++.h>
using namespace std;
int n, q;
int nu[100100];
long long pw[22];
struct SEG {
  long long lev[1000100];
  long long dis[1000100];
  long long laz[1000100];
  bool eq[1000100];
  void up(int rt) {
    int ls = rt * 2, rs = rt * 2 + 1;
    dis[rt] = max(dis[ls], dis[rs]);
    lev[rt] = max(lev[ls], lev[rs]);
    eq[rt] = (eq[ls] && eq[rs] && lev[ls] == lev[rs] && dis[ls] == dis[rs] &&
              laz[ls] == laz[rs]);
  }
  void build(int rt, int l, int r) {
    if (l == r) {
      lev[rt] = 1;
      while (lev[rt] < nu[l]) lev[rt] *= 42;
      dis[rt] = nu[l] - lev[rt];
      eq[rt] = 1;
      return;
    }
    int mid = (l + r) / 2;
    build(rt * 2, l, mid);
    build(rt * 2 + 1, mid + 1, r);
    up(rt);
  }
  void pd(int rt) {
    if (!eq[rt]) {
      dis[rt] += laz[rt];
      laz[rt * 2] += laz[rt];
      laz[rt * 2 + 1] += laz[rt];
      laz[rt] = 0;
      return;
    } else {
      long long nv = dis[rt] + lev[rt] + laz[rt];
      while (lev[rt] < nv) lev[rt] *= 42;
      dis[rt] = nv - lev[rt];
      laz[rt] = laz[rt * 2] = laz[rt * 2 + 1] = 0;
      eq[rt * 2] = eq[rt * 2 + 1] = 1;
      dis[rt * 2] = dis[rt * 2 + 1] = dis[rt];
      lev[rt * 2] = lev[rt * 2 + 1] = lev[rt];
    }
  }
  void change(int rt, int l, int r, int st, int ed, int val) {
    pd(rt);
    if (l > ed || r < st) return;
    if (l >= st && r <= ed) {
      eq[rt] = 1;
      lev[rt] = 1;
      while (lev[rt] < val) lev[rt] *= 42;
      dis[rt] = val - lev[rt];
      laz[rt] = 0;
      return;
    }
    int mid = (l + r) / 2;
    change(rt * 2, l, mid, st, ed, val);
    change(rt * 2 + 1, mid + 1, r, st, ed, val);
    up(rt);
  }
  void add(int rt, int l, int r, int st, int ed, int val) {
    pd(rt);
    if (l > ed || r < st) return;
    if (l >= st && r <= ed) {
      laz[rt] += val;
      pd(rt);
      return;
    }
    int mid = (l + r) / 2;
    add(rt * 2, l, mid, st, ed, val);
    add(rt * 2 + 1, mid + 1, r, st, ed, val);
    up(rt);
  }
  void upgrade(int rt, int l, int r) {
    pd(rt);
    if (dis[rt] <= 0) return;
    if (l == r) {
      long long nv = lev[rt] + dis[rt];
      while (lev[rt] < nv) lev[rt] *= 42;
      dis[rt] = nv - lev[rt];
      return;
    }
    int mid = (l + r) / 2;
    upgrade(rt * 2, l, mid);
    upgrade(rt * 2 + 1, mid + 1, r);
    up(rt);
    return;
  }
  long long ask(int rt, int l, int r, int p) {
    pd(rt);
    if (l == r) return lev[rt] + dis[rt];
    int mid = (l + r) / 2;
    if (mid >= p)
      return ask(rt * 2, l, mid, p);
    else
      return ask(rt * 2 + 1, mid + 1, r, p);
  }
  void print(int rt, int l, int r, int sym) {
    pd(rt);
    if (l == r) {
      if (sym == 0)
        cout << lev[rt] << " ";
      else if (sym == 1)
        cout << dis[rt] << " ";
      else if (sym == 2)
        cout << lev[rt] + dis[rt] << " ";
      return;
    }
    int mid = (l + r) / 2;
    print(rt * 2, l, mid, sym);
    print(rt * 2 + 1, mid + 1, r, sym);
  }
} seg;
int main() {
  pw[0] = 1;
  for (int i = 1; i <= 10; ++i) pw[i] = pw[i - 1] * 42;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", &nu[i]);
  seg.build(1, 1, n);
  int sym, x, y, c;
  while (q--) {
    scanf("%d%d", &sym, &x);
    if (sym == 1) {
      printf("%lld\n", seg.ask(1, 1, n, x));
      continue;
    } else if (sym == 2) {
      scanf("%d%d", &y, &c);
      seg.change(1, 1, n, x, y, c);
      continue;
    } else if (sym == 3) {
      scanf("%d%d", &y, &c);
      seg.add(1, 1, n, x, y, c);
      seg.upgrade(1, 1, n);
      while (seg.dis[1] == 0) {
        seg.add(1, 1, n, x, y, c);
        seg.upgrade(1, 1, n);
      }
    }
  }
  return 0;
}
