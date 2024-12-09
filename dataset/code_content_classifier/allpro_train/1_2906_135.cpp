#include <bits/stdc++.h>
int main() {
  char s[32];
  int n, k, r(0);
  std::scanf("%s%d", s, &k);
  n = std::strlen(s);
  for (int i(n - 1); 0 <= i; --i) {
    k -= s[i] == '0';
    if (k == 0) break;
    r += s[i] != '0';
  }
  if (0 < k) r = n - 1;
  std::printf("%d\n", r);
  return 0;
}
