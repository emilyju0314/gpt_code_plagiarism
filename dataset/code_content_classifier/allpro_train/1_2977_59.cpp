#include <bits/stdc++.h>
using namespace std;
const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = 111;
const int M = 20;
int m;
int a[N], num[M];
char cmd[M];
int d[(1 << M)], nd[(1 << M)];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  reverse(a, a + n);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf(" %c %d", &cmd[i], &num[i]);
  }
  for (int i = 0; i < (1 << m); i++) {
    d[i] = 0;
  }
  for (int i = m - 1; i >= 0; i--) {
    for (int j = 0; j < (1 << m); j++) {
      nd[j] = (num[i] == 1 ? -inf : inf);
      for (int z = 0; z < m; z++) {
        if ((j & (1 << z)) == 0) {
          int res = d[j | (1 << z)] +
                    (cmd[i] == 'p' ? (num[i] == 1 ? a[z] : -a[z]) : 0);
          nd[j] = (num[i] == 1 ? max(nd[j], res) : min(nd[j], res));
        }
      }
    }
    for (int j = 0; j < (1 << m); j++) {
      d[j] = nd[j];
    }
  }
  printf("%d\n", d[0]);
  return 0;
}
