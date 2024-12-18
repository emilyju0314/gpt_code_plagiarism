#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int maxn = 2005;
int n, m;
long long ans = 0;
int h[maxn][maxn], d[maxn][maxn], cou1[maxn], cou2[maxn], cou3[maxn],
    cou4[maxn];
char mp[maxn][maxn];
void slove() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) h[i][j] = h[i][j - 1] + (mp[i][j] == '#');
  for (int j = 1; j <= m; j++)
    for (int i = 1; i <= n; i++) d[i][j] = d[i - 1][j] + (mp[i][j] == '#');
  for (int i = 2; i < n; i++) ans += (h[i][m] == 0);
  for (int i = 2; i < m; i++) ans += (d[n][i] == 0);
  for (int i = 2; i < n; i++)
    for (int j = 2; j < m; j++) {
      if (mp[i][j] == '#') continue;
      if (h[i][j] == 0) {
        if (d[i][j] == 0) ans++;
        if (d[n][j] == d[i - 1][j]) ans++;
      }
      if (h[i][m] == h[i][j - 1]) {
        if (d[i][j] == 0) ans++;
        if (d[n][j] == d[i - 1][j]) ans++;
      }
    }
  int l1 = 0, l2 = 0;
  for (int i = 2; i < n; i++)
    for (int j = 2; j < m; j++) {
      if (mp[i][j - 1] != '#' && d[i][j] == 0) ans += cou1[j - 2];
      cou1[j] = (mp[i][j] == '#' ? 0 : cou1[j - 1] + (d[i][j] == 0));
      if (mp[i][j - 1] != '#' && d[i - 1][j] == d[n][j]) ans += cou2[j - 2];
      cou2[j] = (mp[i][j] == '#' ? 0 : cou2[j - 1] + (d[i - 1][j] == d[n][j]));
      if (mp[i][j - 1] != '#' && d[i - 1][j] == d[n][j]) ans += cou3[j - 1];
      cou3[j] = (mp[i][j] == '#' ? 0 : cou3[j - 1] + (d[i][j] == 0));
      if (mp[i][j - 1] != '#' && d[i][j] == 0) ans += cou4[j - 1];
      cou4[j] = (mp[i][j] == '#' ? 0 : cou4[j - 1] + (d[i - 1][j] == d[n][j]));
    }
  for (int j = 2; j < m; j++)
    for (int i = 2; i < n; i++) {
      if (mp[i - 1][j] != '#' && h[i][j] == 0) ans += cou1[i - 2];
      cou1[i] = (mp[i][j] == '#' ? 0 : cou1[i - 1] + (h[i][j] == 0));
      if (mp[i - 1][j] != '#' && h[i][j - 1] == h[i][m]) ans += cou2[i - 2];
      cou2[i] = (mp[i][j] == '#' ? 0 : cou2[i - 1] + (h[i][j - 1] == h[i][m]));
      if (mp[i - 1][j] != '#' && h[i][j - 1] == h[i][m]) ans += cou3[i - 1];
      cou3[i] = (mp[i][j] == '#' ? 0 : cou3[i - 1] + (h[i][j] == 0));
      if (mp[i - 1][j] != '#' && h[i][j] == 0) ans += cou4[i - 1];
      cou4[i] = (mp[i][j] == '#' ? 0 : cou4[i - 1] + (h[i][j - 1] == h[i][m]));
    }
}
int main(void) {
  int i;
  for (scanf("%d%d", &n, &m), i = 1; i <= n; i++) scanf("%s", &mp[i][1]);
  slove();
  printf("%I64d\n", ans);
  return 0;
}
