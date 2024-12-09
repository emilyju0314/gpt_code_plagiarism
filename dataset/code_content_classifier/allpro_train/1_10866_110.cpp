#include <bits/stdc++.h>
using namespace std;
const int MAXN = 700 + 10;
bool adj[MAXN][MAXN];
int n, e;
int deg[MAXN];
int same[MAXN][MAXN];
int main() {
  cin >> n >> e;
  for (int i = 1; i <= e; i++) {
    int e1, e2;
    cin >> e1 >> e2;
    adj[e1][e2] = adj[e2][e1] = true;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) deg[i] += adj[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        if (k != i && k != j && adj[i][k] && adj[j][k]) same[i][j]++;
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j)
        for (int k = 1; k <= n; k++)
          if (i != k && j != k && adj[j][k]) {
            if (adj[i][j]) same[i][k]--;
            if (adj[i][k]) same[i][j]--;
            ans += same[i][j] * same[i][k];
            if (adj[i][j]) same[i][k]++;
            if (adj[i][k]) same[i][j]++;
          }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        if (adj[i][j] && adj[i][k] && adj[j][k]) ans -= deg[i] - 2;
  cout << ans / 10 << endl;
  return 0;
}
