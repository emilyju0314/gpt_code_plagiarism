#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double Pi = acos(-1.0);
const int mod = 1000000007;
const int N = 210;
int main() {
  int T;
  while (~scanf("%d", &T)) {
    while (T--) {
      int n, k, b[205];
      scanf("%d%d", &n, &k);
      for (int i = 0; i < k; i++) scanf("%d", &b[i]);
      int ans = 0;
      for (int i = 1; i < k; i++) {
        int s = b[i] - b[i - 1] + 1;
        ans = max(s, ans);
      }
      if (ans & 1)
        ans = ans / 2 + 1;
      else
        ans = ans / 2;
      ans = max(ans, max(b[0], n - b[k - 1] + 1));
      printf("%d\n", ans);
    }
  }
}
