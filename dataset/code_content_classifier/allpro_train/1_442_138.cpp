#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, a[N], b[N], T, K, ans;
inline int solve(int x) {
  int cnt = 0;
  for (int i = x + 1; i <= n - (K - x); i++) b[++cnt] = a[i];
  int res = m - K - 1;
  int ans = 1e9;
  for (int i = 0; i <= res; i++)
    ans = min(ans, max(b[i + 1], b[cnt - (res - i)]));
  return ans;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    K = min(K, m - 1);
    ans = -1e9;
    for (int i = 0; i <= K; i++) ans = max(ans, solve(i));
    printf("%d\n", ans);
    ans = 0;
  }
  return 0;
}
