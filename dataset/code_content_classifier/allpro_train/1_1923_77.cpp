#include <bits/stdc++.h>
using namespace std;
int dfs(int x, int y) {
  if (x == 1 && y == 1) return 0;
  if (x <= 0 || y <= 0 || x == y) return 1000000;
  if (x > y) {
    return 1 + dfs(x - y, y);
  } else
    return 1 + dfs(x, y - x);
}
int main() {
  int n, i, ans = 1000000;
  cin >> n;
  for (i = 1; i <= n; i++) {
    ans = min(ans, dfs(i, n));
  }
  cout << ans << endl;
  return 0;
}
