#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, Minn;
const int inf = 1e9;
const int MAXN = 5000;
int s[MAXN][MAXN];
int Count[MAXN];
int main() {
  scanf("%d%d", &n, &m);
  memset(Count, 0, sizeof(Count));
  memset(s, 0, sizeof(s));
  Minn = inf;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &a, &b);
    s[a][b] = 1;
    s[b][a] = 1;
    Count[a]++;
    Count[b]++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (s[i][j]) {
        for (int k = j + 1; k <= n; k++) {
          if (s[i][k] && s[j][k]) {
            Minn = min(Minn, Count[i] + Count[j] + Count[k] - 6);
          }
        }
      }
    }
  }
  if (Minn != inf)
    printf("%d\n", Minn);
  else
    printf("-1\n");
  return 0;
}
