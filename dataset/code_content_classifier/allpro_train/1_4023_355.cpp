#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const long long mod = 1000000007;
char s[N], t[N];
int nxt[N];
int n, m;
int pos[N];
void pre() {
  int i, j;
  j = nxt[0] = -1;
  i = 0;
  while (i < m) {
    while (-1 != j && t[i] != t[j]) j = nxt[j];
    nxt[++i] = ++j;
  }
}
void KMP() {
  int i, j;
  pre();
  i = j = 0;
  while (i < n) {
    while (-1 != j && s[i] != t[j]) j = nxt[j];
    i++;
    j++;
    if (j >= m) {
      pos[i] = i - m + 1;
      j = nxt[j];
    }
  }
}
long long dp[N], sum[N], dpp[N];
int main() {
  scanf("%s%s", s, t);
  n = strlen(s);
  m = strlen(t);
  memset(pos, 0, sizeof(pos));
  KMP();
  int now = 0;
  for (int i = 1; i <= n; i++)
    if (!pos[i])
      pos[i] = now;
    else
      now = pos[i];
  dp[0] = 0;
  sum[0] = 0;
  dpp[0] = 0;
  for (int i = 1; i <= n; i++) {
    int p = pos[i];
    if (p) {
      dp[i] = (dpp[p - 1] + p) % mod;
      dpp[i] = (dpp[i - 1] + sum[i - 1] + dp[i]) % mod;
      sum[i] = (sum[i - 1] + dp[i]) % mod;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans = (ans + dp[i]) % mod;
  printf("%I64d\n", ans);
  return 0;
}
