#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[105];
  int k, i, j, l, n, d;
  scanf("%d %d", &n, &k);
  scanf("%s", s);
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] == 'G') l = i;
    if (s[i] == 'T') j = i;
  }
  if (l < j) {
    for (i = l; i <= j; i = i + k) {
      if (s[i] == '#') {
        d = 0;
        i = j + 1;
      } else if (s[i] == '.')
        d = 0;
      else if (s[i] == 'T')
        d = 1;
    }
  } else {
    for (i = l; i >= j; i = i - k) {
      if (s[i] == '#') {
        d = 0;
        i = j - 1;
      } else if (s[i] == '.')
        d = 0;
      else if (s[i] == 'T')
        d = 1;
    }
  }
  if (d == 1)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
