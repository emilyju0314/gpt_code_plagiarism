#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N], b[N], n, k;
long long ans[N], x, t;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    x += 1LL * a[i] * i, b[i] = 1, ans[i] = ans[i - 1] + a[i];
  }
  for (int i = 0; i < 10; i++) {
    k = 1, t = 0;
    for (int j = 1; j <= n; j++) {
      if (b[j] && 11LL * a[j] * k + ans[n] - ans[j] < 0) b[j] = 0;
      if (!b[j] && 1LL * a[j] * k + ans[n] - ans[j] >= 0) b[j] = 1;
      if (b[j])
        ans[j] = ans[j - 1] + a[j], t += 1LL * a[j] * k, k++;
      else
        ans[j] = ans[j - 1];
    }
    x = std::max(x, t);
  }
  printf("%lld\n", x);
  return 0;
}
