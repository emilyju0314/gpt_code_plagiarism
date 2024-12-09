#include <bits/stdc++.h>
using namespace std;
unsigned int las = 2333333;
int n, m, t;
long long C, add;
struct eve {
  long long x;
  int t;
} a[800100];
bool cmp(eve a, eve b) { return a.x < b.x; }
void read(long long& n) {
  n = 0;
  char c;
  for (; (c = getchar()) < 48 || c > 57;)
    ;
  for (; c > 47 && c < 58; c = getchar()) n = n * 10 + c - 48;
}
unsigned int nw() {
  las ^= las << 4;
  las ^= las << 8;
  las ^= las >> 5;
  las ^= las >> 10;
  return las;
}
struct treap {
  treap *l, *r;
  long long x, y, adx, ady;
  unsigned int key;
  treap(long long _x = 0, long long _y = 0) {
    adx = ady = 0;
    x = _x;
    y = _y;
    key = nw();
    l = r = 0;
  }
  void upd(long long u, long long v) {
    adx += u;
    x += u;
    ady += v;
    y += v;
  }
  void down() {
    if (!adx && !ady) return;
    if (l) l->upd(adx, ady);
    if (r) r->upd(adx, ady);
    adx = ady = 0;
  }
};
void lturn(treap* x) {
  treap* y = x->r;
  x->r = y->l;
  y->l = x;
  x = y;
}
void rturn(treap* x) {
  treap* y = x->l;
  x->l = y->r;
  y->r = x;
  x = y;
}
treap* merge(treap* a, treap* b) {
  if (!a || !b) return a ? a : b;
  if (a->key < b->key) {
    a->down();
    a->r = merge(a->r, b);
    return a;
  }
  b->down();
  b->l = merge(a, b->l);
  return b;
}
void split(treap* a, long long L, treap*& lf, treap*& rg) {
  if (!a) {
    lf = rg = 0;
    return;
  }
  a->down();
  if (a->x - a->y >= L)
    rg = a, split(a->l, L, lf, rg->l);
  else
    lf = a, split(a->r, L, lf->r, rg);
}
treap* left(treap* a) {
  if (!a) return 0;
  a->down();
  if (!a->l) return a;
  return left(a->l);
}
treap* right(treap* a) {
  if (!a) return 0;
  a->down();
  if (!a->r) return a;
  return right(a->r);
}
void del(treap*& a) {
  a->down();
  if (!a->l)
    a = a->r;
  else
    del(a->l);
}
void der(treap*& a) {
  a->down();
  if (!a->r)
    a = a->l;
  else
    der(a->r);
}
int main() {
  cin >> n >> m >> C;
  for (int i = 1; i <= n + n; ++i) read(a[++t].x), a[t].t = 1;
  for (int i = 1; i <= m + m; ++i) read(a[++t].x), a[t].t = 2;
  sort(a + 1, a + t + 1, cmp);
  int st = 0;
  treap* root = new treap(0, 0);
  for (int i = 1; i < t; ++i) {
    st ^= a[i].t;
    if (!st) continue;
    long long T = a[i + 1].x - a[i].x;
    if (!T) continue;
    if (st == 1)
      root->upd(T, 0);
    else if (st == 2)
      root->upd(0, T);
    else {
      add += T;
      treap *t1 = 0, *t2 = 0, *t3 = 0;
      split(root, -C, t1, t2);
      split(t2, C, t2, t3);
      long long rx = 0, ry = -C, lx = -C, ly = 0;
      if (t1) {
        lx = (right(t1))->x;
        ly = lx + C;
      }
      if (t3) {
        ry = (left(t3))->y;
        rx = ry + C;
      }
      if (lx > rx || ly > ry) {
        treap* L = new treap(lx, ly);
        if (!t2)
          t2 = L;
        else {
          treap* tmp = left(t2);
          if (lx > tmp->x || ly > tmp->y) t2 = merge(L, t2);
        }
      }
      if (rx > lx || ry > ly || (rx == lx && ry == ly)) {
        treap* R = new treap(rx, ry);
        if (!t2)
          t2 = R;
        else {
          treap* tmp = right(t2);
          if (rx > tmp->x || ry > tmp->y) t2 = merge(t2, R);
        }
      }
      t2->upd(T, T);
      treap *l = left(t2), *r = right(t2);
      while (t1) {
        treap* tmp = right(t1);
        if (tmp->x <= l->x && tmp->y <= l->y)
          der(t1);
        else
          break;
      }
      while (t3) {
        treap* tmp = left(t3);
        if (tmp->x <= r->x && tmp->y <= r->y)
          del(t3);
        else
          break;
      }
      root = merge(merge(t1, t2), t3);
    }
  }
  cout << add + (right(root))->x;
}
