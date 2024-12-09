#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double pi = acos(-1.0);
const int N = 1e5 + 10;
const int mod = 100;
long long a[500010];
int main() {
  int q, i, j;
  while (scanf("%d", &q) == 1) {
    long long sum = 0;
    int n = 0;
    int cnt = 0;
    while (q--) {
      int op, x;
      scanf("%d", &op);
      if (op == 1) {
        n++;
        scanf("%d", &a[n]);
        while (cnt < n && sum + a[n] > a[cnt + 1] * (cnt + 1)) {
          cnt++;
          sum += a[cnt];
        }
      } else {
        double ans = a[n] - 1.0 * (sum + a[n]) / (cnt + 1);
        printf("%.6f\n", ans);
      }
    }
  }
  return 0;
}
