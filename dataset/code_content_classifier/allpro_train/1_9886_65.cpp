#include <bits/stdc++.h>
using namespace std;
const int MN = 3e5 + 5;
struct nd {
  int k, p, sz, mn;
  nd *l, *r, *pr;
  nd(int v) : k(v), p(rand()), sz(1), mn(v), l(0), r(0), pr(0) {}
} * rt;
inline int mn(nd *n) { return n ? n->mn : 1 << 30; }
inline int sz(nd *n) { return n ? n->sz : 0; }
inline nd *pr(nd *n) { return n ? n->pr : NULL; }
inline void upd(nd *&n) {
  if (!n) return;
  n->sz = sz(n->l) + sz(n->r) + 1;
  n->mn = min(mn(n->l), min(n->k, mn(n->r)));
}
void split(nd *n, nd *&l, nd *&r, int k) {
  if (!n)
    l = r = NULL;
  else if (sz(n->l) + 1 > k)
    split(n->l, l, n->l, k), n->pr = pr(r), r = n;
  else
    split(n->r, n->r, r, k - sz(n->l) - 1), n->pr = pr(l), l = n;
  upd(n);
}
void mrg(nd *&n, nd *l, nd *r) {
  if (!l || !r)
    n = l ? l : r;
  else if (l->p > r->p)
    r->pr = l, mrg(l->r, l->r, r), n = l;
  else
    l->pr = r, mrg(r->l, l, r->l), n = r;
  upd(n);
}
int pos(nd *n) {
  if (n == rt) return 0;
  if (n->pr->r == n)
    return sz(n->pr->l) + 1 + pos(n->pr);
  else
    return pos(n->pr);
}
int t, n, i, x, f, a[MN], b[MN];
queue<nd *> heh[MN];
nd *l, *r, *tmp;
int main() {
  for (scanf("%d", &t); t; t--) {
    for (scanf("%d", &n), i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (i = 1; i <= n; i++) scanf("%d", &b[i]);
    rt = NULL;
    f = 0;
    for (i = 1; i <= n; i++) {
      heh[a[i]].push(new nd(a[i]));
      mrg(rt, rt, heh[a[i]].back());
    }
    for (i = 1; i <= n; i++) {
      if (heh[b[i]].empty()) {
        f = 1;
        break;
      }
      nd *nxt = heh[b[i]].front();
      heh[b[i]].pop();
      int idx = pos(nxt) + sz(nxt->l) + 1;
      split(rt, l, r, idx);
      if (l->mn < b[i]) {
        f = 1;
        break;
      }
      split(l, l, tmp, idx - 1);
      mrg(rt, l, r);
    }
    printf("%s\n", f ? "NO" : "YES");
    for (i = 1; i <= n; i++) {
      while (heh[a[i]].size()) heh[a[i]].pop();
    }
  }
  return 0;
}
