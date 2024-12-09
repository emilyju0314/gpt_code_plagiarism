#include <bits/stdc++.h>
char s[1024];
int p[26][1024];
int k[26];
int main() {
  gets(s);
  int l = strlen(s);
  for (int i = 0; i < l; i++) {
    const int j = s[i] - 'A';
    p[j][k[j]] = i;
    k[j]++;
  }
  int ans = 0;
  for (int i = 0; i < 26; i++) {
    if (k[i]) {
      int r = 1;
      int p_ = p[i][0];
      for (int j = 1; j < k[i]; j++) {
        if ((p[i][j] - p_ + 1) % 2 == 0) {
          r++;
          p_ = p[i][j];
        }
      }
      if (r > ans) {
        ans = r;
      }
    }
  }
  printf("%d", ans);
  return 0;
}
