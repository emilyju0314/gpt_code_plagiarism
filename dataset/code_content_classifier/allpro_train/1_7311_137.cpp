#include <bits/stdc++.h>
using namespace std;
template <typename __ll>
inline void read(__ll &m) {
  __ll x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  m = x * f;
}
int dis[2001][2001], n;
int main() {
  int i, j;
  read(n);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) read(dis[i][j]);
  if (n == 1 && !dis[1][1]) {
    puts("YES");
    return 0;
  }
  for (i = 1; i <= n; i++)
    if (dis[i][i] != 0) {
      puts("NO");
      return 0;
    }
  for (i = 1; i <= n; i++)
    for (j = i + 1; j <= n; j++) {
      if (dis[i][j] != dis[j][i] || (dis[i][j] == 0)) {
        puts("NO");
        return 0;
      }
    }
  int flag = 1;
  for (i = 1; i <= n && flag; i++) {
    int minn = 0x3f3f3f3f, k;
    for (j = 1; j <= n; j++)
      if (i != j && minn > dis[i][j]) minn = dis[i][j], k = j;
    for (j = 1; j <= n; j++)
      if (i != j && j != k && abs(dis[i][j] - dis[j][k]) != minn) {
        flag = 0;
        break;
      }
  }
  puts(flag == 0 ? "NO" : "YES");
}
