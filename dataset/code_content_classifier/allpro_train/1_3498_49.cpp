#include <bits/stdc++.h>
int mmp[101][101];
int s[101];
int t[101];
int main() {
  int n, m, ans, k, i, j;
  while (scanf("%d %d", &n, &k) != EOF) {
    ans = 0;
    for (i = 0; i < n / k; i++) {
      for (j = 0; j < k; j++) scanf("%d", &mmp[i][j]);
    }
    if (n != k) {
      for (i = 0; i < k; i++) {
        s[i] = 0;
        t[i] = 0;
        for (j = 0; j < n / k; j++) {
          if (mmp[j][i] == 1)
            s[i]++;
          else if (mmp[j][i] == 2)
            t[i]++;
        }
      }
      for (i = 0; i < k; i++) {
        if (s[i] > t[i])
          ans = ans + t[i];
        else
          ans = ans + s[i];
      }
      printf("%d\n", ans);
    } else
      printf("0\n");
  }
}
