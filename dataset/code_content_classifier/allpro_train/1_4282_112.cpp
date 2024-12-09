#include <bits/stdc++.h>
using namespace std;
bool vis[1010][1010];
int n, K;
void read(int &x) {
  char ch = getchar();
  int mark = 1;
  for (; ch != '-' && (ch < '0' || ch > '9'); ch = getchar())
    ;
  if (ch == '-') mark = -1, ch = getchar();
  for (x = 0; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - 48;
  x *= mark;
}
int main() {
  read(n);
  read(K);
  if (K > (n - 1) / 2)
    printf("-1\n");
  else {
    printf("%d\n", K * n);
    for (int i = 1; i <= n; i++) {
      int t = K;
      for (int j = 1; j <= n && t; j++)
        if (i != j && (!vis[i][j])) {
          vis[i][j] = 1;
          printf("%d %d\n", i, j);
          t--;
          vis[j][i] = 1;
        }
    }
  }
  return 0;
}
