#include <bits/stdc++.h>
using namespace std;
int i, i0, n, m;
char s[5005], t[5005];
bool chk(int x) {
  for (int i = 1; i <= x; i++) t[n - x + i] = s[i];
  for (int i = x + 1; i <= n; i++) t[i - x] = s[i];
  bool f = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] != t[i]) f = 1;
  }
  if (!f) return 0;
  for (int i = 1; i <= n / 2; i++) {
    if (t[i] != t[n - i + 1]) return 0;
  }
  return 1;
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  if (n % 2) {
    for (i = 1; i <= n; i++) {
      if (i == n / 2 + 1) continue;
      if (s[i] != s[1]) {
        for (i = 2; i < n; i++) {
          if (chk(i)) {
            printf("1\n");
            return 0;
          }
        }
        printf("2\n");
        return 0;
      }
    }
    printf("Impossible\n");
    return 0;
  } else {
    for (i = 1; i <= n; i++) {
      if (s[i] != s[1]) {
        for (i = 2; i < n; i++) {
          if (chk(i)) {
            printf("1\n");
            return 0;
          }
        }
        printf("2\n");
        return 0;
      }
    }
    printf("Impossible\n");
    return 0;
  }
  return 0;
}
