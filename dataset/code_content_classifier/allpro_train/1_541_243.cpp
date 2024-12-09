#include <bits/stdc++.h>
int f[200][200];
int main() {
  for (int i = 'a'; i <= 'z'; i++)
    for (int j = 'a'; j <= 'z'; j++) f[i][j] = -2000000000;
  int n;
  scanf("%d", &n);
  char st[15];
  int a, b;
  for (int j = 0; j < n; j++) {
    scanf("%s", st);
    int l = strlen(st);
    a = st[0];
    b = st[l - 1];
    for (int i = (int)'a'; i <= (int)'z'; i++) {
      if (f[i][a] + l > f[i][b]) f[i][b] = f[i][a] + l;
    }
    if (l > f[a][b]) f[a][b] = l;
  }
  int ans = 0;
  for (char s = 'a'; s <= 'z'; s++) {
    int a = s;
    if (f[a][a] > ans) ans = f[a][a];
  }
  printf("%d\n", ans);
  return 0;
}
