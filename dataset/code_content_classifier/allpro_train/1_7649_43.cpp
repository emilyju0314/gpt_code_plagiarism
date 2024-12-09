#include <bits/stdc++.h>
int f[200], i, j, m, k, ans;
long long n;
int mod = 1000000007;
char s[100];
struct point {
  int s[52][52];
  point operator*(const point &b) const {
    int i, j, k;
    point ans;
    memset(ans.s, 0, sizeof(ans.s));
    for (i = 0; i < m; i++)
      for (j = 0; j < m; j++)
        for (k = 0; k < m; k++)
          ans.s[i][j] = ((long long)s[i][k] * b.s[k][j] + ans.s[i][j]) % mod;
    return ans;
  }
} p, q;
int main() {
  for (i = 'a'; i <= 'z'; i++) {
    f[i] = i - 'a';
  }
  for (i = 'A'; i <= 'Z'; i++) {
    f[i] = i - 'A' + 26;
  }
  while (scanf("%I64d%d%d", &n, &m, &k) == 3) {
    for (i = 0; i < m; i++)
      for (j = 0; j < m; j++) {
        p.s[i][j] = 1;
        if (i == j)
          q.s[i][j] = 1;
        else
          q.s[i][j] = 0;
      }
    while (k--) {
      scanf("%s", s);
      p.s[f[s[0]]][f[s[1]]] = 0;
    }
    n--;
    while (n) {
      if (n & 1) q = q * p;
      p = p * p;
      n = n >> 1;
    }
    ans = 0;
    for (i = 0; i < m; i++)
      for (j = 0; j < m; j++) ans = (ans + q.s[i][j]) % mod;
    printf("%d\n", ans);
  }
  return 0;
}
