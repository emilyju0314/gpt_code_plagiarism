#include <bits/stdc++.h>
using namespace std;
int len, i, m = 1000000007, k, n;
long long dp[2][2015][1015];
char s1[1015], s2[1015];
long long cal1(int f, int a, int b) {
  if (dp[f][a][b] != -1) return dp[f][a][b];
  if (b == 0) return f;
  long long ret = 0;
  for (int i = 0; i < 10; i++) {
    if (i == 4 || i == 7)
      ret += cal1(f | (a <= k), 1, b - 1);
    else
      ret += cal1(f, a + 1, b - 1);
  }
  return dp[f][a][b] = ret % m;
}
long long cal2(char* s) {
  len = strlen(s);
  int d = k + 1, f = 0;
  long long ans = 0;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < s[i] - '0'; j++) {
      if (j == 4 || j == 7)
        ans += cal1(f | (d <= k), 1, len - i - 1);
      else
        ans += cal1(f, d + 1, len - i - 1);
    }
    if (s[i] == '4' || s[i] == '7') {
      f |= (d <= k);
      d = 1;
    } else
      d++;
  }
  return ans % m;
}
bool check(char* s) {
  int len = strlen(s), d = k + 1, f = 0;
  for (int i = 0; i < len; i++) {
    if (s[i] == '4' || s[i] == '7') {
      f |= (d <= k);
      d = 1;
    } else
      d++;
  }
  return f;
}
int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%s%s", s1, s2);
    printf("%I64d\n", ((cal2(s2) - cal2(s1) + check(s2)) % m + m) % m);
  }
  return 0;
}
