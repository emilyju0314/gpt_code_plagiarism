#include <bits/stdc++.h>
using namespace std;
const int N = 4000 + 1;
const int sq = 100;
const long long int mod = 1e9 + 7;
const long long int inf = 4000 + 1;
unordered_map<long long int, int> dp;
int ps[N], n;
inline int get(int l, int r) { return ps[r] - ps[l]; }
int solve(int l, int r, int k, bool bol) {
  if (r - l < k || l >= r || r > n || l < 0) return 0;
  if (r - l == k && bol) return get(l, r);
  if (r - l == k) return -get(l, r);
  long long int key = l * N * sq * 2 + r * sq * 2 + k * 2 + bol;
  if (dp.count(key)) return dp[key];
  int ans, x, y;
  if (bol) {
    x = solve(l + k, r, k, 0) + get(l, l + k);
    y = solve(l + k + 1, r, k + 1, 0) + get(l, l + k + 1);
    ans = max(x, y);
  } else {
    x = solve(l, r - k, k, 1) - get(r - k, r);
    y = solve(l, r - k - 1, k + 1, 1) - get(r - k - 1, r);
    ans = min(x, y);
  }
  return dp[key] = ans;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  dp.rehash(16e6);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    ps[i + 1] = ps[i] + x;
  }
  printf("%d \n", solve(0, n, 1, 1));
  return 0;
}
