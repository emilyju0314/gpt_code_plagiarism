#include <bits/stdc++.h>
using namespace std;
int nextInt() {
  char c = 0;
  int a = 0, s = 0;
  while (c > '9' || c < '0') {
    if (c == '-') s = 1 - s;
    c = getchar();
  }
  while (c <= '9' && c >= '0') {
    a = a * 10 + c - '0';
    c = getchar();
  }
  if (s) a = -a;
  return a;
}
int main() {
  int n = nextInt(), s = nextInt(), ans = -1, a;
  for (int i = 0; i < n; i++) {
    a = nextInt();
    if (a < s)
      ans = max(ans, (100 - nextInt()) % 100);
    else if (a == s) {
      if (nextInt() == 0) ans = max(ans, 0);
    } else
      nextInt();
  }
  printf("%d", ans);
}
