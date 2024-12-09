#include <bits/stdc++.h>
using namespace std;
char s[100005];
int main() {
  scanf("%s", s);
  int n = strlen(s);
  int flag1 = 0, flag2 = 0, flag = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] == 'A' && s[i - 1] == 'B') {
      if (flag1 == 1) {
        flag = 1;
        break;
      }
    }
    if (s[i] == 'B' && s[i - 1] == 'A') {
      if (flag2 == 1) {
        flag = 1;
        break;
      }
    }
    if (i > 1) {
      if (s[i - 1] == 'B' && s[i - 2] == 'A') flag1 = 1;
      if (s[i - 1] == 'A' && s[i - 2] == 'B') flag2 = 1;
    }
  }
  if (flag)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
