#include <bits/stdc++.h>
using namespace std;
char a;
bool p[100100];
int i, j, n, m, b, k, c[100100], q, r;
int main() {
  scanf("%d%d", &n, &m);
  getchar();
  for (i = 1; i <= m; ++i) {
    scanf("%c %d", &a, &b);
    getchar();
    if (a == '+') {
      if (p[b])
        puts("Already on");
      else {
        k = 0;
        bool f = 1;
        for (j = 2; j * j <= b; ++j)
          if (b % j == 0) {
            if (c[j]) {
              f = 0;
              k = c[j];
              break;
            }
            if (c[b / j]) {
              f = 0;
              k = c[b / j];
              break;
            }
          }
        if (b >= 2 && c[b]) f = 0, k = c[b];
        if (!f) {
          printf("Conflict with %d\n", k);
          continue;
        }
        puts("Success");
        for (j = 2; j * j <= b; ++j)
          if (b % j == 0) c[j] = c[b / j] = b;
        if (b >= 2) c[b] = b;
        p[b] = true;
      }
    } else {
      if (p[b]) {
        puts("Success");
        for (j = 2; j * j <= b; ++j)
          if (b % j == 0) c[j] = 0, c[b / j] = 0;
        if (b >= 2) c[b] = 0;
        p[b] = false;
      } else
        puts("Already off");
    }
  }
  return 0;
}