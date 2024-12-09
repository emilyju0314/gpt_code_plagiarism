#include <bits/stdc++.h>
const int maxn = 100010;
int n, m;
int aBs(int x) { return x < 0 ? -x : x; }
void denew(int &x, int y) {
  if (x > y) x = y;
}
void innew(int &x, int y) {
  if (x < y) x = y;
}
struct Random {
  long long gy;
  int hq, mf, qq;
  Random() {
    gy = 617;
    hq = 1102;
    mf = 228;
    qq = 1992122981;
  }
  int get() { return gy = (gy * mf + hq) % qq; }
} R;
struct node {
  int siz, l, r, giv, val, cov, ll, rr;
  node *s[2];
  node() {}
  node(int l, int r, int val) : l(l), r(r), val(val) {
    s[0] = s[1] = 0;
    giv = R.get();
    siz = r - l + 1;
    cov = 0;
    ll = l;
    rr = r;
  }
  void cover(int x) {
    val = x;
    cov = 1;
  }
  void update() {
    siz = r - l + 1;
    ll = l;
    rr = r;
    if (s[0]) {
      siz += s[0]->siz;
      denew(ll, s[0]->ll);
    }
    if (s[1]) {
      siz += s[1]->siz;
      innew(rr, s[1]->rr);
    }
  }
  void pushdown() {
    if (cov) {
      if (s[0]) s[0]->cover(val);
      if (s[1]) s[1]->cover(val);
      cov = 0;
    }
  }
};
struct Mem {
  node *st[maxn], pond[maxn];
  int top;
  Mem() {
    top = maxn - 1;
    for (int i = 0; i <= maxn; i++) st[i] = &pond[i];
  }
  void dispose(node *p) { st[++top] = p; }
  node *nwnode(int l, int r, int val) {
    node *p = st[top--];
    if (p->s[0]) dispose(p->s[0]);
    if (p->s[1]) dispose(p->s[1]);
    return &(*p = node(l, r, val));
  }
} M;
struct Segtree {
  struct node {
    int l, r, siz;
    long long dta, sum;
    node *s[2];
    node() {}
    node(int l, int r) : l(l), r(r) {
      s[0] = s[1] = 0;
      sum = dta = 0;
      siz = r - l + 1;
    }
    void plus(long long x) {
      dta += x;
      sum += siz * x;
    }
    void update() { sum = (s[0] ? s[0]->sum : 0) + (s[1] ? s[1]->sum : 0); }
    void pushdown() {
      if (dta) {
        if (s[0]) s[0]->plus(dta);
        if (s[1]) s[1]->plus(dta);
        dta = 0;
      }
    }
  } * root;
  void build(node *p, int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (l <= mid) build(p->s[0] = new node(l, mid), l, mid);
    if (mid < r) build(p->s[1] = new node(mid + 1, r), mid + 1, r);
  }
  void preset() { build(root = new node(1, n), 1, n); }
  void add(node *p, int l, int r, long long x) {
    if (l <= p->l && p->r <= r) {
      p->plus(x);
      return;
    }
    p->pushdown();
    int mid = (p->l + p->r) >> 1;
    if (l <= mid) add(p->s[0], l, r, x);
    if (r > mid) add(p->s[1], l, r, x);
    p->update();
  }
  void add(int l, int r, long long x) { add(root, l, r, x); }
  long long getsum(node *p, int l, int r) {
    if (l <= p->l && p->r <= r) return p->sum;
    int mid = (p->l + p->r) >> 1;
    long long res = 0;
    p->pushdown();
    if (l <= mid) res += getsum(p->s[0], l, r);
    if (r > mid) res += getsum(p->s[1], l, r);
    p->update();
    return res;
  }
  long long getsum(int l, int r) { return (getsum(root, l, r)); }
} tree;
struct treap {
  node *root, *st[maxn];
  int top;
  node *merge(node *p, node *q) {
    if (!p) return q;
    if (!q) return p;
    p->pushdown();
    q->pushdown();
    if (p->giv > q->giv) {
      p->s[1] = merge(p->s[1], q);
      p->update();
      return p;
    } else {
      q->s[0] = merge(p, q->s[0]);
      q->update();
      return q;
    }
  }
  void split(node *p, int w, node *&p1, node *&p2) {
    if (!p) {
      p1 = p2 = 0;
      return;
    }
    p->pushdown();
    int sum = (p->s[0] ? p->s[0]->siz : 0) + 1;
    if (w < sum) {
      p2 = p;
      split(p->s[0], w, p1, p2->s[0]);
      p2->update();
    } else {
      p1 = p;
      split(p->s[1], w - sum, p1->s[1], p2);
      p1->update();
    }
  }
  void preset() {
    tree.preset();
    top = 0;
    for (int i = 1; i <= n; i++) {
      node *p = M.nwnode(i, i, i);
      while (top >= 2 && st[top - 1]->giv > p->giv) {
        st[top - 1]->s[1] = st[top];
        st[top--]->update();
      }
      if (top && p->giv < st[top]->giv) {
        p->s[0] = st[top];
        st[top--]->update();
      }
      st[++top] = p;
    }
    while (top >= 2) {
      st[top - 1]->s[1] = st[top];
      st[top--]->update();
    }
    st[1]->update();
    root = st[1];
  }
  void change(node *p, int x) {
    if (p->cov) {
      tree.add(p->ll, p->rr, aBs(p->val - x));
      return;
    }
    p->pushdown();
    tree.add(p->l, p->r, aBs(p->val - x));
    if (p->s[1]) change(p->s[1], x);
    if (p->s[0]) change(p->s[0], x);
  }
  void cover(int l, int r, int x) {
    node *p1, *p2, *p3;
    split(root, r, p2, p3);
    split(p2, l - 1, p1, p2);
    change(p2, x);
    p2->cover(x);
    root = merge(p1, merge(p2, p3));
  }
} trp;
int main() {
  scanf("%d%d", &n, &m);
  trp.preset();
  for (int i = 1; i <= m; i++) {
    int sgn;
    scanf("%d", &sgn);
    if (sgn == 1) {
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);
      trp.cover(l, r, x);
    }
    if (sgn == 2) {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%I64d\n", tree.getsum(l, r));
    }
  }
  return 0;
}
