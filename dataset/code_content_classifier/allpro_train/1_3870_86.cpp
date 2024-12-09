#include <bits/stdc++.h>
using namespace std;
long long dp[300300];
int a[300300], h[300300], d[300300];
vector<int> ans;
inline void calc(int i) {
  int mn = min(a[i], a[i + 1]);
  if (!mn) return;
  ans.push_back(i);
  a[i] -= mn, a[i + 1] -= mn;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= 2; i++) dp[i] = a[i], d[i] = 1;
  for (int i = 3; i <= n; i++) {
    if (dp[i - 2] + a[i] < dp[i - 3] + max(a[i], a[i - 1]))
      dp[i] = dp[i - 2] + a[i], d[i] = 1;
    else
      dp[i] = dp[i - 3] + max(a[i], a[i - 1]), d[i] = 2;
  }
  for (int i = n - (dp[n] >= dp[n - 1]); i > 0; i -= d[i] + 1) {
    h[i] = h[i - d[i] + 1] = 1;
  }
  for (int i = 1; i <= n; i++)
    if (h[i]) {
      if (h[i + 1]) calc(i);
      calc(i - 1), calc(i);
    }
  printf("%d\n", ans.size());
  for (int x : ans) printf("%d\n", x);
}
