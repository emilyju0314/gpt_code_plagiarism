#include <bits/stdc++.h>
using namespace std;
int pre[105];
int n, m;
int main() {
  cin >> n >> m;
  int ans = m;
  memset(pre, 0, sizeof(pre));
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    for (int j = x; j <= y; j++) {
      if (pre[j] == 0) {
        ans--;
      }
      pre[j] = 1;
    }
  }
  cout << ans << endl;
  for (int i = 1; i <= m; i++) {
    if (pre[i] == 0) {
      ans--;
      printf("%d%c", i, ans == 0 ? '\n' : ' ');
    }
  }
  return 0;
}
