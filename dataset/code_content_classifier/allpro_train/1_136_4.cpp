#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100, inf = 1e9 + 100;
int tree[4 * N];
int a[N];
int n;
void build(int cn, int b, int e) {
  if (b == e) {
    tree[cn] = b;
    return;
  }
  int lc = 2 * cn, rc = lc + 1, mid = (b + e) / 2;
  build(lc, b, mid);
  build(rc, mid + 1, e);
  if (a[tree[lc]] > a[tree[rc]])
    tree[cn] = tree[lc];
  else
    tree[cn] = tree[rc];
}
int query(int cn, int b, int e, int i, int j) {
  if (b > j or e < i) return 0;
  if (b >= i and e <= j) {
    return tree[cn];
  }
  int lc = 2 * cn, rc = lc + 1, mid = (b + e) / 2;
  int idx1 = query(lc, b, mid, i, j), idx2 = query(rc, mid + 1, e, i, j);
  if (a[idx1] > a[idx2]) return idx1;
  return idx2;
}
const int LOG = 20;
int rmq[N][LOG];
int lg[N];
void preprocess() {
  for (int i = 1; i <= n; i++) rmq[i][0] = a[i];
  for (int j = 1; j < LOG; j++) {
    for (int i = 1; i <= n; i++) {
      if (i + (1 << j) - 1 <= n) {
        rmq[i][j] = rmq[i][j - 1] | rmq[i + (1 << (j - 1))][j - 1];
      } else
        break;
    }
  }
  for (int i = 2; i < N; i++) {
    lg[i] = lg[i / 2] + 1;
  }
}
int query(int i, int j) {
  int k = lg[j - i + 1];
  int ans = rmq[i][k] | rmq[j - (1 << k) + 1][k];
  return ans;
}
long long ans;
void solve(int l, int r) {
  if (l > r) return;
  int mid = query(1, 1, n, l, r);
  solve(l, mid - 1);
  solve(mid + 1, r);
  int lo = l, hi = mid;
  while (hi > lo) {
    int m = (lo + hi) / 2;
    if (query(m, mid) == a[mid]) {
      hi = m;
    } else {
      lo = m + 1;
    }
  }
  int L = mid - lo + 1;
  lo = mid, hi = r;
  while (hi > lo) {
    int m = (hi + lo + 1) / 2;
    if (query(mid, m) == a[mid]) {
      lo = m;
    } else {
      hi = m - 1;
    }
  }
  int R = lo - mid + 1;
  ans += 1ll * L * R;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  a[0] = -inf;
  preprocess();
  build(1, 1, n);
  solve(1, n);
  ans = 1ll * n * (n + 1) / 2 - ans;
  cout << ans;
  return 0;
}
