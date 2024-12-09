#include <bits/stdc++.h>
using namespace std;
char s[1000010];
int ans = 0;
int main() {
  scanf("%s", s);
  int l = 0, n = 0, len = strlen(s);
  for (int i = 0; i < len; i++) {
    if (s[i] == '1')
      l++, n++;
    else if (i != strlen(s) - 1 && s[i + 1] == '1' && l != 0)
      l++;
    else {
      ans += min(n, l - n + 2);
      l = 0;
      n = 0;
    }
  }
  ans += min(n, l - n + 2);
  printf("%d\n", ans);
  return 0;
}
