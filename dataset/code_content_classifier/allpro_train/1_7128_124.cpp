#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, s;
  long long int ans;
  cin >> n;
  cin >> m;
  cin >> s;
  ans = 0;
  for (int i = 1; i <= n; i += 2)
    for (int j = 1; j <= m; j += 2) {
      if (i * j > s)
        continue;
      else if (i * j == s) {
        ans += (n - i / 2 * 2) * (m - j / 2 * 2) *
               (((i / 2 + 1) * (j / 2 + 1) - 1) * 2 + 1);
      } else {
        for (int len = 1; len < i; len += 2) {
          if ((s - i * j) % len == 0) {
            int wide = (s - i * j) / (len) + j;
            if (wide <= m && (wide & 1))
              ans += (n - i / 2 * 2) * (m - wide / 2 * 2) * 2;
          }
        }
      }
    }
  printf("%lld\n", ans);
  return 0;
}
