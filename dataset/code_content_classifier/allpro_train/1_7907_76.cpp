#include <bits/stdc++.h>
int t[2][1024];
int s[2];
int main() {
  char s1[1024], s2[1024];
  int k;
  scanf("%s%s%d", s1, s2, &k);
  int l = strlen(s1);
  t[0][0] = 1;
  s[0] = 1;
  for (int i = 1; i <= k; i++) {
    s[i & 1] = 0;
    for (int j = 0; j < l; j++) {
      t[i & 1][j] =
          (s[(i - 1) & 1] + 1000000007 - t[(i - 1) & 1][j]) % 1000000007;
      s[i & 1] = (s[i & 1] + t[i & 1][j]) % 1000000007;
    }
  }
  int ans = 0;
  for (int i = 0; i < l; i++) {
    char s3[1024];
    strcpy(s3, s2 + i);
    strncat(s3, s2, i);
    if (strcmp(s1, s3) == 0) {
      ans = (ans + t[k & 1][i]) % 1000000007;
    }
  }
  printf("%d\n", ans);
  return 0;
}
