#include <bits/stdc++.h>
using namespace std;
struct node {
  int id;
  double index, v;
  node() : id(0) {}
  bool operator<(const node& b) const {
    return fabs(index * b.v) == fabs(b.index * v)
               ? id > b.id
               : fabs(index * b.v) < fabs(b.index * v);
  }
  bool operator==(const node& b) const { return index == b.index && v == b.v; }
} arr[(int)1e5 + 10], sup[(int)1e5 + 10];
int a[(int)1e5 + 10], b[(int)1e5 + 10];
struct seg {
  int l, r;
  long long he, lazy, tag;
} t[(int)1e5 + 10 << 2];
void build(int root, int l, int r) {
  t[root].l = l, t[root].r = r;
  t[root].lazy = 0;
  t[root].tag = -1;
  if (l == r) {
    t[root].he = 0;
    return;
  }
  int m = (l + r) >> 1;
  build(root << 1, l, m);
  build(root << 1 | 1, m + 1, r);
  t[root].he = t[root << 1].he + t[root << 1 | 1].he;
}
void imptag(int root, long long change) {
  t[root].tag = change;
  t[root].he = (t[root].r - t[root].l + 1) * change;
  t[root].lazy = 0;
}
void implazy(int root, long long change) {
  t[root].lazy += change;
  t[root].he += (t[root].r - t[root].l + 1) * change;
}
void pushdown(int root) {
  long long temp1 = t[root].tag;
  if (temp1 != -1) {
    imptag(root << 1, temp1);
    imptag(root << 1 | 1, temp1);
    t[root].tag = -1;
  }
  long long temp2 = t[root].lazy;
  if (temp2) {
    implazy(root << 1, temp2);
    implazy(root << 1 | 1, temp2);
    t[root].lazy = 0;
  }
}
void assignment(int root, int l, int r, long long change) {
  if (r < t[root].l || l > t[root].r) return;
  if (l <= t[root].l && t[root].r <= r) {
    imptag(root, change);
    return;
  }
  pushdown(root);
  assignment(root << 1 | 1, l, r, change);
  assignment(root << 1, l, r, change);
  t[root].he = t[root << 1].he + t[root << 1 | 1].he;
}
void update(int root, int l, int r, long long change) {
  if (r < t[root].l || l > t[root].r) return;
  if (l <= t[root].l && t[root].r <= r) {
    implazy(root, change);
    return;
  }
  pushdown(root);
  update(root << 1 | 1, l, r, change);
  update(root << 1, l, r, change);
  t[root].he = t[root << 1].he + t[root << 1 | 1].he;
}
long long query(int root, int l, int r) {
  if (r < t[root].l || l > t[root].r) return 0;
  if (l <= t[root].l && t[root].r <= r) {
    return t[root].he;
  }
  pushdown(root);
  return query(root << 1 | 1, l, r) + query(root << 1, l, r);
}
int main(void) {
  int n;
  double w;
  scanf("%d%lf", &n, &w);
  int i;
  for (i = 0; i < n; i++) {
    double a, b;
    scanf("%lf%lf", &a, &b);
    arr[i].index = a, arr[i].v = b - w;
    sup[i] = arr[i];
  }
  sort(sup, sup + n);
  int m = unique(sup, sup + n) - sup;
  for (i = 0; i < n; i++) {
    arr[i].id = lower_bound(sup, sup + m, arr[i]) - sup;
    arr[i].v += 2 * w;
  }
  sort(arr, arr + n);
  for (i = 0; i < n; i++) {
    b[i] = arr[i].id;
  }
  build(1, 0, m - 1);
  long long res = 0;
  for (i = 0; i < n; i++) {
    res += query(1, b[i], m - 1);
    update(1, b[i], b[i], 1);
  }
  printf("%lld", res);
}
