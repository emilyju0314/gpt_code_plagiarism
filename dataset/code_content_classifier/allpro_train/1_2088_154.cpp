#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6, MAXV = 1 << 20;
struct node {
  int sum, msuf;
};
int N, M, Q;
int a[MAXN], b[MAXN];
node tree[2 * MAXV];
void merge(int i) {
  tree[i].sum = tree[2 * i].sum + tree[2 * i + 1].sum;
  tree[i].msuf =
      max(tree[2 * i + 1].msuf, tree[2 * i].msuf + tree[2 * i + 1].sum);
}
void add(int i, int x) {
  tree[MAXV + i].sum += x;
  tree[MAXV + i].msuf += x;
  for (int j = (MAXV + i) / 2; j >= 1; j /= 2) {
    merge(j);
  }
}
int query() {
  if (tree[1].msuf <= 0) {
    return -1;
  }
  int n = 1, sum = 0;
  while (n < MAXV) {
    if (tree[2 * n + 1].msuf + sum > 0) {
      n = 2 * n + 1;
    } else {
      sum += tree[2 * n + 1].sum;
      n = 2 * n;
    }
  }
  return n - MAXV;
}
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &a[i]);
    add(a[i], 1);
  }
  for (int i = 1; i <= M; i++) {
    scanf("%d", &b[i]);
    add(b[i], -1);
  }
  scanf("%d", &Q);
  for (int q = 0, t, i, x; q < Q; q++) {
    scanf("%d%d%d", &t, &i, &x);
    if (t == 1) {
      add(a[i], -1);
      a[i] = x;
      add(a[i], 1);
    } else {
      add(b[i], 1);
      b[i] = x;
      add(b[i], -1);
    }
    printf("%d\n", query());
  }
}
