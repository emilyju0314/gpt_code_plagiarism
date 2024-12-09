#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int a[maxn], n;
char str[maxn];
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  scanf("%s", str);
  int len = strlen(str);
  reverse(a, a + n);
  reverse(str, str + len);
  int dp[2][2];
  memset(dp, -1, sizeof(dp));
  int pre = 0, cur = 1;
  dp[pre][0] = 0;
  for (int i = 0; i < len; ++i) {
    if (str[i] == '0') {
      dp[cur][0] = dp[pre][0];
      if (dp[pre][1] != -1) dp[cur][0] = max(dp[cur][0], dp[pre][1] + a[i]);
      if (dp[pre][1] != -1) dp[cur][1] = dp[pre][1] + a[i];
    } else {
      dp[cur][0] = dp[pre][0] + a[i];
      if (dp[pre][1] != -1) dp[cur][0] = max(dp[cur][0], dp[pre][1] + a[i]);
      if (dp[pre][1] != -1) dp[cur][1] = dp[pre][1] + a[i];
      dp[cur][1] = max(dp[cur][1], dp[pre][0]);
    }
    swap(cur, pre);
  }
  printf("%d\n", max(dp[pre][0], dp[pre][1]));
  return 0;
}
