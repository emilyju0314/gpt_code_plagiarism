#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1100;
int n, a[MAXN][MAXN], b[MAXN][MAXN], ansx[MAXN * MAXN], ansy[MAXN * MAXN], tot1,
    tot2;
int main() {
  cin >> n;
  for (int i = 1; i <= n - 3; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    a[u][v] = a[v][u] = 1;
  }
  for (int i = 1; i <= n - 3; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    b[u][v] = b[v][u] = 1;
  }
  for (int i = 1; i <= n; i++) {
    a[i][i % n + 1] = 1;
    a[i % n + 1][i] = 1;
    b[i][i % n + 1] = 1;
    b[i % n + 1][i] = 1;
  }
  for (int i = 3; i <= n - 1; i++)
    while (!a[1][i]) {
      int fu = i - 1, fv, eu = -1, ev;
      for (int j = i + 1; j <= n; j++)
        if (a[1][j]) {
          fv = j;
          break;
        }
      for (int j = 1; j <= n; j++)
        if (a[fu][j] && a[fv][j]) {
          if (eu == -1)
            eu = j;
          else
            ev = j;
        }
      ansx[++tot1] = fu;
      ansy[tot1] = fv;
      a[fu][fv] = a[fv][fu] = 0;
      a[eu][ev] = a[ev][eu] = 1;
    }
  for (int i = 3; i <= n - 1; i++)
    while (!b[1][i]) {
      int fu = i - 1, fv, eu = -1, ev;
      for (int j = i + 1; j <= n; j++)
        if (b[1][j]) {
          fv = j;
          break;
        }
      for (int j = 1; j <= n; j++)
        if (b[fu][j] && b[fv][j]) {
          if (eu == -1)
            eu = j;
          else
            ev = j;
        }
      ansx[++tot2 + tot1] = eu;
      ansy[tot2 + tot1] = ev;
      b[fu][fv] = b[fv][fu] = 0;
      b[eu][ev] = b[ev][eu] = 1;
    }
  cout << tot1 + tot2 << endl;
  for (int i = 1; i <= tot1; i++) printf("%d %d\n", ansx[i], ansy[i]);
  for (int i = tot2; i >= 1; i--)
    printf("%d %d\n", ansx[i + tot1], ansy[i + tot1]);
}
