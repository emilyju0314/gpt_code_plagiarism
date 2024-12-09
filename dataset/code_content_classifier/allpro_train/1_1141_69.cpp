#include <bits/stdc++.h>
using namespace std;
void solve(int n, int m) {
  int upLinha = 0;
  int upCol = 0;
  int downLinha = n - 1;
  int downCol = m - 1;
  int lado = 0;
  while (upLinha < downLinha) {
    printf("%d %d\n", upLinha + 1, upCol + 1);
    upCol++;
    if (upCol == m) {
      upLinha++;
      upCol = 0;
    }
    printf("%d %d\n", downLinha + 1, downCol + 1);
    downCol--;
    if (downCol < 0) {
      downCol = m - 1;
      downLinha--;
    }
  }
  if (upLinha == downLinha) {
    int u, v;
    u = 0;
    v = m - 1;
    while (1) {
      if (u > v) break;
      printf("%d %d\n", upLinha + 1, u + 1);
      u++;
      if (u > v) break;
      printf("%d %d\n", upLinha + 1, v + 1);
      v--;
    }
  }
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  solve(n, m);
}
