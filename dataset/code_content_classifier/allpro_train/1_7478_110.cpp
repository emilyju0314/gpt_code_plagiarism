#include <bits/stdc++.h>
using namespace std;
int main() {
  int num[3003];
  int n, m, i;
  memset(num, 0, sizeof(num));
  while (scanf("%d%d", &n, &m) == 2) {
    for (i = 0; i < m; i++) {
      scanf("%d", &num[i]);
    }
    sort(num, num + m);
    for (i = 2; i < m; i++) {
      if (num[i] - num[i - 1] == 1 && num[i - 1] - num[i - 2] == 1) {
        printf("NO\n");
        return 0;
      }
    }
    if (num[0] != 1 && num[m - 1] != n) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
