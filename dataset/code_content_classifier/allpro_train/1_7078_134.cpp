#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, j, k, l, n, q;
  scanf("%lld", &n);
  ll dp[n][3], cnt[n];
  char s[n + 10];
  scanf("%s%lld", s, &q);
  cnt[0] = s[0] == 'M' ? 1 : 0;
  for(i = 1; i < n; ++i) cnt[i] = cnt[i - 1] + (s[i] == 'M' ? 1 : 0); 
  for(l = 0; l < q; ++l) {
    scanf("%lld", &k);
    for(i = 0; i < n; ++i) for(j = 0; j < 3; ++j) dp[i][j] = 0;
    if(s[0] == 'D') dp[0][0] = 1;
    for(i = 1; i < n; ++i) {
      if(i >= k && s[i - k] == 'D') dp[i][0]--, dp[i - 1][1] -= cnt[i] - cnt[i - k];
      for(j = 0; j < 3; ++j) dp[i][j] += dp[i - 1][j];
      if(s[i] == 'D') dp[i][0]++;
      if(s[i] == 'M') dp[i][1] += dp[i - 1][0];
      if(s[i] == 'C') dp[i][2] += dp[i - 1][1];
    }
    printf("%lld\n", dp[n - 1][2]);
  }
  return 0;
}