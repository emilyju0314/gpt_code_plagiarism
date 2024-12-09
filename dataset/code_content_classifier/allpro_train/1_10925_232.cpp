#include <bits/stdc++.h>
const int N = 200010;
bool a[2][N];
int n, q;
int ans;
int main(void) {
  std::cin >> n >> q;
  for (register int i = 1, x, y; i <= q; ++i) {
    std::cin >> x >> y;
    --x;
    a[x][y] = !a[x][y];
    if (a[x][y]) {
      for (register int j = std::max(1, y - 1); j <= std::min(n, y + 1); ++j) {
        if (a[x ^ 1][j]) {
          ++ans;
        }
      }
    } else {
      for (register int j = std::max(1, y - 1); j <= std::min(n, y + 1); ++j) {
        if (a[x ^ 1][j]) {
          --ans;
        }
      }
    }
    if (!ans) {
      puts("Yes");
    } else {
      puts("No");
    }
  }
  return 0;
}
