#include <bits/stdc++.h>
using namespace std;
char G[8][8];
int main() {
  int n, m;
  cin >> n >> m;
  if (n < 7) {
    cout << m;
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    G[x][y] = G[y][x] = 1;
  }
  int best = 69;
  for (int i = 1; i <= 7; i++)
    for (int j = 1; j <= 7; j++)
      if (j != i) {
        int alt = 0;
        for (int k = 1; k <= 7; k++) alt += G[i][k] & G[j][k];
        best = min(best, alt);
      }
  cout << m - best;
}
