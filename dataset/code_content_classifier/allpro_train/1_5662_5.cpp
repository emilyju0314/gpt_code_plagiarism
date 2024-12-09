#include <bits/stdc++.h>
int main() {
  char s[200];
  int x, i, j = 0;
  scanf("%s", s);
  x = strlen(s);
  for (i = 0; i < x; i++) {
    if (s[i] == '-' && s[i + 1] == '.') {
      s[j] = '1';
      j++;
      i++;
    } else if (s[i] == '-' && s[i + 1] == '-') {
      s[j] = '2';
      j++;
      i++;
    } else {
      s[j] = '0';
      j++;
    }
  }
  s[j] = '\0';
  printf("%s", s);
  return 0;
}
