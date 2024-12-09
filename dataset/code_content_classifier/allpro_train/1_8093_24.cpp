#include <bits/stdc++.h>
using namespace std;
const int INTINF = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 55;
const int MAXM = (1 << 20) + 1;
long long dp[MAXM], C[MAXN][MAXN];
int n, m;
char a[MAXN][MAXN];
double ans = 0;
int count(long long x) {
  int res = 0;
  while (x) x &= (x - 1), res++;
  return res;
}
void init() {
  for (int i = 0; i <= m; i++)
    for (int j = C[i][0] = 1; j <= i; j++)
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%s", a[i]);
  m = strlen(a[0]);
  init();
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < i; j++) {
      int same_bit = 0;
      for (int k = 0; k < m; k++)
        if (a[i][k] == a[j][k]) same_bit |= 1 << k;
      dp[same_bit] |= (1ll << i) | (1ll << j);
    }
  for (int s = (1 << m) - 1; ~s; s--)
    for (int i = 0; i < m; i++)
      if ((1 << i) & s) dp[s ^ (1 << i)] |= dp[s];
  for (int s = 0; s < (1 << m); s++) {
    ans += (double)count(dp[s]) / n / C[m][count(s)];
  }
  printf("%.10lf\n", ans);
  return 0;
}
