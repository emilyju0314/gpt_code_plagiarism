#include <bits/stdc++.h>
using namespace std;
int t;
void work() {
  int n, x, y, ans = 0, a[10002];
  cin >> n >> x;
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; ++i) {
    cin >> y;
    a[y] = 1;
  }
  while (true) {
    ans++;
    if (!a[ans])
      if (x)
        x--;
      else if (!x)
        break;
  }
  cout << ans - 1 << "\n";
}
int main() {
  cin >> t;
  for (int i = 0; i < t; ++i) work();
  return 0;
}
