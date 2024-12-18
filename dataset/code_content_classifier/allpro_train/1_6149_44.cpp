#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200100;
const int A = 26;
char s[N];
int n, m, k;
int a[A];
bool dp[N];
int solve() {
  scanf("%d%d%d", &n, &m, &k);
  scanf("%s", s);
  for (int i = 0; i < A; i++) a[i] = 0;
  for (int i = 0; i < k; i++) a[(int)(s[i] - 'A')]++;
  int ans = n * m;
  for (int p = 0; p < A; p++) {
    for (int i = 0; i <= k; i++) dp[i] = 0;
    dp[0] = 1;
    for (int i = 0; i < A; i++) {
      if (i == p) continue;
      for (int j = k; j >= a[i]; j--) dp[j] |= dp[j - a[i]];
    }
    for (int i = 0; i <= k; i++) {
      if (!dp[i]) continue;
      int x = max(0, n - i);
      int y = max(0, m - (k - a[p] - i));
      if (x + y > a[p]) continue;
      ans = min(ans, x * y);
    }
  }
  return ans;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) printf("%d\n", solve());
  return 0;
}
