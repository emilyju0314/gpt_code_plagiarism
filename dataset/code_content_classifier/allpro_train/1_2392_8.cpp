#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, ans = INT_MAX;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    ans = min(ans, (b - a + 1));
  }
  cout << ans << endl;
  int i = 0;
  while (i < n) {
    for (int j = 0; j < ans && i < n; j++, i++) cout << j << " ";
  }
  return 0;
}
