#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
char s[maxn];
int main() {
  int i, j, len;
  while (gets(s)) {
    len = strlen(s);
    for (i = 0; i < len; i++) {
      if (s[i] == '\n') break;
      if (s[i] >= 'a' && s[i] <= 'z')
        printf("%c", s[i]);
      else if (s[i] == '.' || s[i] == ',' || s[i] == '!' || s[i] == '?')
        printf("%c ", s[i]);
      else {
        j = i;
        while (s[i] == ' ' && i < len) i++;
        if (i < len) {
          if (s[j] == ' ' && (s[j - 1] >= 'a' && s[j - 1] <= 'z') &&
              (s[i] != '.' && s[i] != ',' && s[i] != '!' && s[i] != '?'))
            printf(" ");
          i--;
        }
      }
    }
    printf("\n");
  }
  return 0;
}
