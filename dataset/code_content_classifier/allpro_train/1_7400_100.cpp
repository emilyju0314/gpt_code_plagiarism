#include <bits/stdc++.h>
using namespace std;
int n, k;
char name[110];
char yes[110];
char ans[110];
int main() {
  scanf("%d %d", &n, &k);
  scanf("%s", name);
  scanf("%s", yes);
  memset(ans, 0, sizeof(ans));
  for (int i = 0; yes[i]; i++) {
    if (yes[i] == '1') {
      for (int j = 0; name[j]; j++) {
        if (ans[i + j] > 0 && ans[i + j] != name[j]) {
          puts("No solution");
          return 0;
        }
        ans[i + j] = name[j];
      }
    }
  }
  for (int i = 0; yes[i]; i++) {
    if (yes[i] == '0') {
      for (int j = 0; name[j]; j++) {
        if (!ans[i + j]) {
          for (int t = 0; t < k; t++) {
            if ('a' + t != name[j]) {
              ans[i + j] = t + 'a';
            }
          }
        }
        if (!ans[i + j]) ans[i + j] = name[j];
        if (ans[i + j] != name[j]) break;
        if (ans[i + j] == name[j] && !name[j + 1]) {
          puts("No solution");
          return 0;
        }
      }
    }
  }
  for (int i = 0; i < n; i++)
    if (!ans[i]) ans[i] = 'a';
  puts(ans);
  return 0;
}