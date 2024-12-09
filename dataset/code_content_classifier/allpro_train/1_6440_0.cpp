#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const double PI = 3.141592653589793;
int n, k, i, j, e, f, m, q, l, tab[300][300];
char t[5][5];
int main() {
  ifstream ifile("input.txt");
  if (ifile) freopen("input.txt", "rt", stdin);
  if (ifile) freopen("output.txt", "wt", stdout);
  scanf("%d %d", &n, &k);
  q = 1;
  for (i = 0; i < k; i++) q *= n;
  for (i = 0; i < n; i++) scanf("%s", &t[i]);
  for (i = 0; i < k; i++) {
    l = 1;
    for (j = 0; j < k - i - 1; j++) l *= n;
    for (j = 0; j < q; j += l)
      for (m = 0; m < q; m += l)
        if (t[(j / l) % n][(m / l) % n] == '*')
          for (e = j; e < j + l; e++)
            for (f = m; f < m + l; f++) tab[e][f] = 1;
  }
  for (i = 0; i < q; i++) {
    for (j = 0; j < q; j++)
      if (tab[i][j])
        printf("*");
      else
        printf(".");
    printf("\n");
  }
  return 0;
}
