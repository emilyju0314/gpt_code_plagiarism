#include <bits/stdc++.h>
using namespace std;
char s[16];
const char p[8][16] = {"vaporeon", "jolteon", "flareon", "espeon",
                       "umbreon",  "leafeon", "glaceon", "sylveon"};
int main() {
  int n, j;
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; i < 8; ++i) {
    if (strlen(p[i]) == n) {
      for (j = 0; j < n; ++j)
        if (s[j] != '.' && s[j] != p[i][j]) break;
      if (j == n) {
        printf("%s\n", p[i]);
        break;
      }
    }
  }
  return 0;
}
