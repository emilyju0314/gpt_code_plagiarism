#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    if (n == 1) {
      if (m == 2) {
        printf("0\n1 1\n1 2\n1 1\n");
        continue;
      }
      printf("1\n1 %d 1 1\n", m);
      for (int i = 1; i <= m; i++) printf("1 %d\n", i);
      printf("1 1\n");
      continue;
    } else if (m == 1) {
      if (n == 2) {
        printf("0\n1 1\n2 1\n1 1\n");
        continue;
      }
      printf("1\n%d 1 1 1\n", n);
      for (int i = 1; i <= n; i++) printf("%d 1\n", i);
      printf("1 1\n");
      continue;
    }
    if ((n & 1) == 0) {
      printf("0\n");
      printf("1 1\n");
      for (int i = 1; i <= n; i++) {
        if (i & 1) {
          for (int j = 2; j <= m; j++) printf("%d %d\n", i, j);
        } else {
          for (int j = m; j >= 2; j--) printf("%d %d\n", i, j);
        }
      }
      for (int i = n; i >= 1; i--) printf("%d 1\n", i);
    } else if ((m & 1) == 0) {
      printf("0\n1 1\n");
      for (int j = 1; j <= m; j++) {
        if (j & 1) {
          for (int i = 2; i <= n; i++) printf("%d %d\n", i, j);
        } else
          for (int i = n; i >= 2; i--) printf("%d %d\n", i, j);
      }
      for (int i = m; i >= 1; i--) printf("1 %d\n", i);
    } else {
      printf("1\n%d %d 1 1\n", n, m);
      for (int i = 1; i <= n; i++) {
        if (i & 1) {
          for (int j = 1; j <= m; j++) printf("%d %d\n", i, j);
        } else
          for (int j = m; j >= 1; j--) printf("%d %d\n", i, j);
      }
      printf("1 1\n");
    }
  }
  return 0;
}
