#include <bits/stdc++.h>
using namespace std;
int a[120];
char s[200][60];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    memset(s, 'a', sizeof(s));
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= 50; j++) {
        if (j <= a[i])
          s[i][j] = s[i - 1][j];
        else {
          if (s[i - 1][j] == 'a')
            s[i][j] = 'z';
          else {
            s[i][j] = s[i - 1][j] - 1;
          }
        }
      }
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 1; j <= 50; j++) printf("%c", s[i][j]);
      printf("\n");
    }
  }
  return 0;
}
