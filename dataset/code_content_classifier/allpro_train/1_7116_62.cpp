#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, n, m;
    cin >> x >> n >> m;
    if (x <= m * 10) {
      printf("YES\n");
      continue;
    }
    for (int i = 0; i < n; i++) {
      x = x / 2 + 10;
    }
    x = x - m * 10;
    if (x <= 0)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
