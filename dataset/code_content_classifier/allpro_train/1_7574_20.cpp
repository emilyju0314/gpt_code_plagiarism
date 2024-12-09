#include <bits/stdc++.h>
using namespace std;
const int maxn = 1200 + 10;
char s[maxn];
int a[maxn];
int main() {
  while (~scanf("%s", s)) {
    memset(a, 0, sizeof(a));
    int len = strlen(s);
    int cnt = 0;
    int m;
    scanf("%d", &m);
    if (len % m == 0) {
      int cur = len / m;
      int sign = 1;
      for (int i = 0; i < len; i += cur) {
        for (int j = i, k = i + cur - 1; j < k; j++, k--) {
          if (s[j] != s[k]) {
            sign = 0;
            break;
          }
        }
        if (sign == 0) break;
      }
      if (sign) cnt = 1;
    }
    if (cnt)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
