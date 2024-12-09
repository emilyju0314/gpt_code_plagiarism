#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5;
const int Inf = 1 << 30;
int cnt[105], pos[105];
int main() {
  int a, b, n, m, c, pp, ans, len;
  while (~scanf("%d %d", &n, &m)) {
    for (int i = 1; i <= n; i++) pos[i] = Inf, cnt[i] = 0;
    for (int i = 1; i <= m; i++) {
      scanf("%d %d", &a, &b);
      cnt[a]++;
      pos[a] = min(pos[a], (b - a + n) % n);
    }
    c = 0;
    for (int i = 1; i <= n; i++) c = max(c, cnt[i]);
    for (int i = 1; i <= n; i++) {
      ans = 0;
      for (int j = 0; j < n; j++) {
        pp = (i + j) % n;
        if (pp == 0) pp = n;
        if (cnt[pp] == c)
          ans = max(ans, pos[pp] + j + (c - 1) * n);
        else if (c != 1 && cnt[pp] == c - 1) {
          ans = max(ans, pos[pp] + j + (c - 2) * n);
        }
      }
      printf("%d", ans);
      if (i == n)
        printf("\n");
      else
        printf(" ");
    }
  }
  return 0;
}
