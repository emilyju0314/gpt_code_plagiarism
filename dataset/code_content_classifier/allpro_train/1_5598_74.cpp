#include <bits/stdc++.h>
const int kMaxN = 200000, kMaxL = 20, kMaxNode = 1 << kMaxL;
const int kINF = 1000000000;
int *dp[kMaxL + 1];
char str[kMaxN][kMaxL + 1];
int m;
inline int GetBit(char *p) {
  int ret = 0;
  for (int i = 0; i < m; ++i) {
    ret = (ret << 1) + (p[i] == '1');
  }
  return ret;
}
inline int CommonStr(char *p, char *q) {
  int bp = GetBit(p), bq = GetBit(q);
  for (int i = m; i > 0; --i) {
    if ((bp & ((1 << i) - 1)) == (bq >> (m - i))) return i;
  }
  return 0;
}
int main() {
  int n, ret, next;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", str[i]);
    if (i == 0) {
      ret = m = strlen(str[i]);
      for (int j = 0; j <= m; ++j) {
        dp[j] = new int[1 << j];
        for (int k = 0, l = 1 << j; k < l; ++k) {
          dp[j][k] = kINF;
        }
      }
      dp[0][0] = 0;
      continue;
    }
    next = ret + m - CommonStr(str[i - 1], str[i]);
    int minval = kINF, b = GetBit(str[i]);
    for (int j = 0; j <= m; ++j) {
      minval = std::min(minval, ret + dp[j][b >> (m - j)] + m - j);
    }
    if (minval < kINF) {
      int val = minval - next;
      b = GetBit(str[i - 1]);
      for (int j = 0; j <= m; ++j) {
        int state = b % (1 << j);
        dp[j][state] = std::min(dp[j][state], val);
      }
    }
    ret = next;
  }
  int extra = kINF;
  for (int i = 0; i <= m; ++i) {
    for (int j = 0, l = 1 << i; j < l; ++j) {
      extra = std::min(extra, dp[i][j]);
    }
  }
  printf("%d\n", ret + extra);
  for (int i = 0; i <= m; ++i) delete[] dp[i];
  return 0;
}
