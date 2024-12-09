#include <bits/stdc++.h>
using namespace std;
int n, n1;
struct node {
  long long s;
  int m;
  int j;
};
node tree[400000];
void update(int node) {
  if (!node) return;
  int i = node;
  tree[i].s = tree[i * 2].s + tree[i * 2 + 1].s;
  if (tree[i * 2].m >= tree[i * 2 + 1].m) {
    tree[i].m = tree[i * 2].m;
    tree[i].j = tree[i * 2].j;
  } else {
    tree[i].m = tree[i * 2 + 1].m;
    tree[i].j = tree[i * 2 + 1].j;
  }
  update(node / 2);
}
int maximum(int l, int r, int left, int right, int node) {
  if (l == left && r == right) return tree[node].j;
  int m = (left + right) / 2;
  if (r <= m) {
    return maximum(l, r, left, m, node * 2);
  }
  if (m < l) return maximum(l, r, m + 1, right, node * 2 + 1);
  int m1 = maximum(l, m, left, m, node * 2),
      m2 = maximum(m + 1, r, m + 1, right, node * 2 + 1);
  if (tree[n1 + m1 - 1].m > tree[n1 + m2 - 1].m) return m1;
  return m2;
}
long long sum(int l, int r, int left, int right, int node) {
  if (l == left && r == right) return tree[node].s;
  int m = (left + right) / 2;
  if (r <= m) {
    return sum(l, r, left, m, node * 2);
  }
  if (m < l) return sum(l, r, m + 1, right, node * 2 + 1);
  return sum(l, m, left, m, node * 2) +
         sum(m + 1, r, m + 1, right, node * 2 + 1);
}
int main() {
  int q;
  scanf("%d%d", &n, &q);
  int i, J;
  n1 = 1;
  while (n1 < n) n1 *= 2;
  for (i = 0; i < n; ++i) {
    scanf("%lld", &J);
    tree[n1 + i].s = 1ll * J;
    tree[n1 + i].m = J;
    tree[n1 + i].j = 1 + i;
  }
  for (i = n1 - 1; i > 0; --i) {
    tree[i].s = tree[i * 2].s + tree[i * 2 + 1].s;
    if (tree[i * 2].m >= tree[i * 2 + 1].m) {
      tree[i].m = tree[i * 2].m;
      tree[i].j = tree[i * 2].j;
    } else {
      tree[i].m = tree[i * 2 + 1].m;
      tree[i].j = tree[i * 2 + 1].j;
    }
  }
  int t, a, b, c, x;
  while (q--) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d%d", &a, &b);
      printf("%lld\n", sum(a, b, 1, n1, 1));
    }
    if (t == 2) {
      scanf("%d%d%d", &a, &b, &c);
      x = maximum(a, b, 1, n1, 1);
      while (tree[n1 + x - 1].m >= c) {
        tree[n1 + x - 1].m %= c;
        tree[n1 + x - 1].s %= c;
        update((n1 + x - 1) / 2);
        x = maximum(a, b, 1, n1, 1);
      }
    }
    if (t == 3) {
      scanf("%d%d", &a, &b);
      tree[n1 + a - 1].m = b;
      tree[n1 + a - 1].s = 1ll * b;
      update((n1 + a - 1) / 2);
    }
  }
  return 0;
}
