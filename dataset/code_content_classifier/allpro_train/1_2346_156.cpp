#include <bits/stdc++.h>
using namespace std;
int main() {
  char trump[5], f[10], s[10];
  while (~scanf("%s", trump)) {
    scanf("%s%s", f, s);
    if (f[1] == trump[0] && s[1] != trump[0])
      printf("YES\n");
    else if (f[1] != trump[0] && s[1] == trump[0])
      printf("NO\n");
    else {
      if (f[1] == s[1]) {
        int a, b;
        if (f[0] == '6') a = 0;
        if (f[0] == '7') a = 1;
        if (f[0] == '8') a = 2;
        if (f[0] == '9') a = 3;
        if (f[0] == 'T') a = 4;
        if (f[0] == 'J') a = 5;
        if (f[0] == 'Q') a = 6;
        if (f[0] == 'K') a = 7;
        if (f[0] == 'A') a = 8;
        if (s[0] == '6') b = 0;
        if (s[0] == '7') b = 1;
        if (s[0] == '8') b = 2;
        if (s[0] == '9') b = 3;
        if (s[0] == 'T') b = 4;
        if (s[0] == 'J') b = 5;
        if (s[0] == 'Q') b = 6;
        if (s[0] == 'K') b = 7;
        if (s[0] == 'A') b = 8;
        if (a > b)
          printf("YES\n");
        else
          printf("NO\n");
      } else
        printf("NO\n");
    }
  }
  return 0;
}
