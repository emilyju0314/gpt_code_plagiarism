#include <bits/stdc++.h>
using namespace std;
long long cnt[9], m, ans = 0;
void dfs(long long d, long long cur) {
  if (d == 9) {
    ans = max(ans, cur);
    return;
  }
  long long r = min(cnt[d], (m - cur) / d);
  long long l = max(0LL, r - 7);
  for (long long i = l; i <= r; ++i) dfs(d + 1, cur + i * d);
}
int main(void) {
  scanf("%lld", &m);
  for (int i = 1; i <= 8; ++i) scanf("%lld", &cnt[i]);
  dfs(1, 0);
  printf("%lld\n", ans);
}
