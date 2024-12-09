#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int i, c, C;
  char s[102];
  while (scanf("%s", s) != EOF) {
    c = 0;
    C = 0;
    for (i = 0; s[i] != '\0'; i++) {
      if (c == 5) {
        c = 0;
        C++;
      }
      if (c && i && s[i] != s[i - 1]) {
        c = 0;
        C++;
      }
      c++;
    }
    if (c) C++;
    printf("%d\n", C);
  }
  return 0;
}
