#include <bits/stdc++.h>
using namespace std;
const double PI = 2.0 * acos(0.0);
const double EPS = 1e-9;
const int MOD = 1000000009;
const int INF = 1000000000;
const long long LINF = 1000000000000000000LL;
int main() {
  int t, n, p, x;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &p);
    x = 2 * n + p;
    for (int i = int(1); i <= int(n); i++)
      if (x)
        for (int j = 1; j + i <= n; j++) {
          if (x)
            printf("%d %d\n", j, j + i), x--;
          else
            break;
        }
  }
  return 0;
}
