#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int sz = 3e4 + 1;
int t, n;
int ar[sz], tree[sz * 4];
void build(int node, int b, int e) {
  if (b == e) {
    tree[node] = b;
    return;
  }
  int mid = (b + e) >> 1;
  int left = node << 1;
  int right = left | 1;
  build(left, b, mid);
  build(right, mid + 1, e);
  if (ar[tree[left]] < ar[tree[right]]) {
    tree[node] = tree[left];
  } else
    tree[node] = tree[right];
}
int qu(int node, int b, int e, int i, int j) {
  if (i > e || j < b) return -1;
  if (b >= i && e <= j) return tree[node];
  int mid = (b + e) >> 1;
  int left = node << 1;
  int right = left | 1;
  int p1, p2;
  p1 = qu(left, b, mid, i, j);
  p2 = qu(right, mid + 1, e, i, j);
  if (p1 == -1) return p2;
  if (p2 == -1) return p1;
  if (ar[p1] < ar[p2]) return p1;
  return p2;
}
int solve(int b, int e, int h = 0) {
  if (b > e) return 0;
  int mn = qu(1, 0, n - 1, b, e);
  int ans = min(e - b + 1, solve(b, mn - 1, ar[mn]) + solve(mn + 1, e, ar[mn]) +
                               ar[mn] - h);
  return ans;
}
int main() {
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; i++) scanf("%d", &ar[i]);
    build(1, 0, n - 1);
    printf("%d\n", solve(0, n - 1));
    cerr << "------------\n";
  }
  return 0;
}
