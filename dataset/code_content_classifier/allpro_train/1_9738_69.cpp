#include <bits/stdc++.h>
using namespace std;
const int N = 4005;
char s[N];
long long dp[N], a;
map<long long, long long> cnt;
int main() {
  scanf("%lld", &a);
  scanf("%s", s);
  int len = strlen(s);
  dp[0] = s[0] - '0';
  for (int i = 1; i < len; i++) dp[i] = dp[i - 1] + (s[i] - '0');
  for (int i = 0; i < len; i++)
    for (int j = i; j < len; j++) {
      if (i > 0)
        cnt[dp[j] - dp[i - 1]]++;
      else if (i == 0)
        cnt[dp[j]]++;
    }
  long long ans = 0;
  if (a == 0) {
    for (map<long long, long long>::iterator it = cnt.begin(); it != cnt.end();
         it++)
      ans += 2 * cnt[0] * it->second;
    ans -= cnt[0] * cnt[0];
    printf("%lld\n", ans);
    return 0;
  }
  for (int i = 1; i * i <= a; i++) {
    if (i * i == a && cnt[i] > 0)
      ans += cnt[i] * cnt[i];
    else if (a % i == 0 && cnt[i] > 0 && cnt[a / i] > 0)
      ans += 2 * cnt[i] * cnt[a / i];
  }
  printf("%lld\n", ans);
  return 0;
}
