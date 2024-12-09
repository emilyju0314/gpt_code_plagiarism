#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 55;
const int mod = 1e9 + 7;
inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int mul(int x, int y) { return (long long)x * y % mod; }
inline int fe(int x, int k) {
  int res = 1;
  while (k) {
    if (k & 1) res = mul(res, x);
    x = mul(x, x);
    k >>= 1;
  }
  return res;
}
inline int dv(int x, int k) { return mul(x, fe(k, mod - 2)); }
int n, k;
int a[N];
int L[N], R[N], pre[N];
int f(int l, int r, int R) {
  swap(l, r);
  l = R - l;
  r = R - r;
  return add(pre[r], mod - pre[l - 1]);
}
int main() {
  scanf("%d %d", &n, &k);
  k--;
  for (int i = 1; i <= n + 22; i++) {
    pre[i] = add(pre[i - 1], i / k);
  }
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    while (v.size() and a[v.back()] <= a[i]) v.pop_back();
    L[i] = v.empty() ? 1 : v.back() + 1;
    v.push_back(i);
  }
  v.clear();
  for (int i = n; i >= 1; i--) {
    while (v.size() and a[v.back()] < a[i]) v.pop_back();
    R[i] = v.empty() ? n : v.back() - 1;
    v.push_back(i);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int l = L[i];
    int r = min(R[i] - k, i);
    if (l <= r) {
      int res = f(l, r, R[i]);
      if (r == i) r--;
      if (l <= r) res = add(res, mod - f(l, r, i - 1));
      ans = add(ans, mul(res, a[i]));
    }
  }
  printf("%d\n", ans);
  return 0;
}
