#include <bits/stdc++.h>
using namespace std;
int pd[110][4][4];
int us[110];
void mrk(int *us, int a, int b) {
  us[a] |= (1 << b);
  b = 1 - b;
  us[a] |= (1 << b);
  if (a) us[a - 1] |= (1 << b);
  us[a + 1] |= (1 << b);
}
int calc(int x, int a, int b) {
  int us[110], aux[3];
  if (pd[x][a][b] != -1) return pd[x][a][b];
  memset(us, 0, sizeof(us));
  us[0] = a;
  us[x - 1] = b;
  set<int> sr;
  for (int p = 0; p < x; p++)
    for (int q = 0; q < 2; q++)
      if (!(us[p] & (1 << q))) {
        for (int k = 0; k < 3; k++)
          if (p + k - 1 >= 0) aux[k] = us[p + k - 1];
        mrk(us, p, q);
        int op = 0, na;
        int res = 0;
        for (int i = 0; i < x; i++) {
          if (!op && us[i] != 3) {
            op = 1;
            na = i;
          }
          if (op && (i == x - 1 || us[i + 1] == 3)) {
            op = 0;
            res ^= calc(i - na + 1, us[na], us[i]);
          }
        }
        sr.insert(res);
        for (int k = 0; k < 3; k++)
          if (p + k - 1 >= 0) us[p + k - 1] = aux[k];
      }
  for (int i = 0;; i++)
    if (sr.find(i) == sr.end()) return (pd[x][a][b] = i);
}
int main() {
  int r, n;
  while (scanf("%d%d", &r, &n) == 2) {
    memset(us, 0, sizeof(us));
    for (int i = 0; i < n; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      mrk(us, x - 1, y - 1);
    }
    int res = 0;
    memset(pd, -1, sizeof(pd));
    int op = 0, a;
    for (int i = 0; i < r; i++) {
      if (!op && us[i] != 3) {
        op = 1;
        a = i;
      }
      if (op && (i == r - 1 || us[i + 1] == 3)) {
        op = 0;
        res ^= calc(i - a + 1, us[a], us[i]);
      }
    }
    if (res)
      printf("WIN\n");
    else
      printf("LOSE\n");
  }
  return 0;
}
