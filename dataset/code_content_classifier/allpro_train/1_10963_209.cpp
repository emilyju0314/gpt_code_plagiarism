#include <bits/stdc++.h>
using namespace std;
static const int SEED = 103;
static const int MAXN = 5000000;
long long f[MAXN + 10];
int dp[MAXN + 10];
char s[MAXN + 10];
int main() {
  scanf("%s", s);
  int len = strlen(s);
  f[0] = 1;
  for (int i = 1; i < len; i++) f[i] = f[i - 1] * SEED;
  long long pre = 0, tail = 0, ans = 0;
  for (int i = 0; i < len; i++) {
    pre = pre * SEED + s[i];
    tail = tail + f[i] * s[i];
    if (pre == tail) {
      dp[i + 1] = dp[i + 1 >> 1] + 1;
      ans += dp[i + 1];
    }
  }
  cout << ans << endl;
  return 0;
}
