#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    ;
  for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
  return x;
}
int n;
char s[100][100];
vector<long long> dp[15][1 << 14];
vector<int> cond[15];
int main() {
  n = read();
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 0; i < (1 << n); i++) {
    int tot = 0;
    for (int j = 1; j <= n; j++) tot += ((i >> j - 1) & 1);
    cond[tot].push_back(i);
  }
  for (int i = 2; i <= n; i++) {
    for (int j = cond[i].size() - 1; j >= 0; j--) {
      int msk = cond[i][j];
      for (int u = 1; u <= n; u++)
        if ((msk >> u - 1) & 1) {
          dp[u][msk].resize(1 << i - 1);
          for (int v = 1; v <= n; v++)
            if (((msk >> v - 1) & 1) && v != u) {
              int t = s[u][v] & 1;
              if (i == 2) {
                dp[u][msk][t]++;
                continue;
              }
              for (int msk2 = 0; msk2 < (1 << i - 2); msk2++) {
                dp[u][msk][msk2 << 1 | t] += dp[v][msk ^ (1 << u - 1)][msk2];
              }
            }
        }
    }
    for (int j = cond[i - 1].size() - 1; j >= 0; j--) {
      int msk = cond[i - 1][j];
      for (int u = 1; u <= n; u++)
        if ((msk >> u - 1) & 1) vector<long long>().swap(dp[u][msk]);
    }
  }
  for (int i = 0; i < (1 << n - 1); i++) {
    long long ans = 0;
    for (int j = 1; j <= n; j++) {
      ans += dp[j][(1 << n) - 1][i];
    }
    printf("%I64d ", ans);
  }
  puts("");
  return 0;
}
