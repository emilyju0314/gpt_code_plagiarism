#include <bits/stdc++.h>
using namespace std;
int const N = 505;
int h, w, q;
long long L[N][N], C[N][N];
char s[N][N];
int main() {
  scanf("%d%d", &h, &w);
  for (int i = 0; i < (int)h + 1; i++)
    for (int j = 0; j < (int)w + 1; j++) s[i][j] = '*';
  for (int i = 1; i <= (int)h; i++)
    for (int j = 1; j <= (int)w; j++) scanf(" %c", &s[i][j]);
  for (int i = 1; i <= (int)h; i++)
    for (int j = 1; j <= (int)w; j++)
      L[i][j] = L[i][j - 1] + (s[i][j] == '.' && s[i][j - 1] == '.');
  for (int i = 1; i <= (int)w; i++)
    for (int j = 1; j <= (int)h; j++)
      C[j][i] = C[j - 1][i] + (s[j][i] == '.' && s[j - 1][i] == '.');
  scanf("%d", &q);
  while (q--) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    long long ans = 0;
    for (int i = a; i <= c; i++) ans += (L[i][d] - L[i][b]);
    for (int i = b; i <= d; i++) ans += (C[c][i] - C[a][i]);
    printf("%I64d\n", ans);
  }
}
