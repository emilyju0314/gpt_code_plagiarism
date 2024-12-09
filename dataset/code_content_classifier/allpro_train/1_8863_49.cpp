#include <bits/stdc++.h>
using namespace std;
const int N = 155000;
int n, m, p;
int pei[N];
struct node {
  node *fa, *lson, *rson;
  int minz, tot;
  int val, rank;
} tree[N];
node *root;
bool cmp(int x, int y) { return (x > y); }
int getint() {
  int res = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while ('0' <= ch && ch <= '9') {
    res = res * 10 + ch - '0';
    ch = getchar();
  }
  return res;
}
int erfen(int l, int r, int key) {
  if (l == r) return l;
  int mid = (l + r + 1) >> 1;
  if (key + pei[mid] >= p) return erfen(mid, r, key);
  return erfen(l, mid - 1, key);
}
void replace(node *x) {
  int lt;
  if (x->lson)
    lt = x->lson->tot;
  else
    lt = 0;
  x->tot = 1;
  x->minz = x->rank - lt;
  if (x->lson) {
    x->tot += x->lson->tot;
    x->minz = min(x->minz, x->lson->minz);
  }
  if (x->rson) {
    x->tot += x->rson->tot;
    x->minz = min(x->minz, x->rson->minz - lt - 1);
  }
}
void zig(node *x) {
  node *y = x->fa;
  if (y->fa) {
    if (y->fa->lson == y)
      y->fa->lson = x;
    else
      y->fa->rson = x;
  }
  if (x->rson) x->rson->fa = y;
  x->fa = y->fa;
  y->fa = x;
  y->lson = x->rson;
  x->rson = y;
  replace(y);
  replace(x);
}
void zag(node *x) {
  node *y = x->fa;
  if (y->fa) {
    if (y->fa->lson == y)
      y->fa->lson = x;
    else
      y->fa->rson = x;
  }
  if (x->lson) x->lson->fa = y;
  x->fa = y->fa;
  y->fa = x;
  y->rson = x->lson;
  x->lson = y;
  replace(y);
  replace(x);
}
void splay(node *x, node *key) {
  if (x == key) return;
  while (1) {
    node *y = x->fa;
    if (y == key) {
      if (y->lson == x)
        zig(x);
      else
        zag(x);
      return;
    }
    node *z = y->fa;
    if (z->lson == y) {
      if (y->lson == x) {
        zig(y);
        zig(x);
      } else {
        zag(x);
        zig(x);
      }
    } else {
      if (y->lson == x) {
        zig(x);
        zag(x);
      } else {
        zag(y);
        zag(x);
      }
    }
    if (z == key) return;
  }
}
void add(node *x, node *key) {
  if (x->val < key->val) {
    if (x->rson)
      add(x->rson, key);
    else {
      x->rson = key;
      key->fa = x;
    }
  } else {
    if (x->lson)
      add(x->lson, key);
    else {
      x->lson = key;
      key->fa = x;
    }
  }
  replace(x);
}
void insert(node *x) {
  add(root, x);
  splay(x, root);
  root = x;
}
void del(node *x) {
  splay(x, root);
  root = x;
  if (!(x->lson)) {
    root = x->rson;
    root->fa = 0;
    return;
  }
  if (!(x->rson)) {
    root = x->lson;
    root->fa = 0;
    return;
  }
  node *s = x->lson;
  while (s->rson) s = s->rson;
  splay(s, x->lson);
  node *t = x->rson;
  s->rson = t;
  s->fa = 0;
  t->fa = s;
  root = s;
  replace(s);
}
void GetData() {
  int i;
  n = getint();
  m = getint();
  p = getint();
  for (i = 1; i <= m; i++) pei[i] = getint();
  sort(pei + 1, pei + m + 1, cmp);
  for (i = 1; i <= n; i++) {
    tree[i].val = getint();
    tree[i].rank = erfen(0, m, tree[i].val);
    tree[i].minz = tree[i].rank;
    tree[i].tot = 1;
  }
  root = tree + 1;
  for (i = 2; i <= m; i++) insert(tree + i);
}
void Do() {
  int ans;
  if (root->minz > 0)
    ans = 1;
  else
    ans = 0;
  int i;
  for (i = m + 1; i <= n; i++) {
    insert(tree + i);
    del(tree + i - m);
    if (root->minz > 0) ans++;
  }
  printf("%d\n", ans);
}
int main() {
  GetData();
  Do();
  return 0;
}
