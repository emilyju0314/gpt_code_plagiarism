#include <bits/stdc++.h>
using namespace std;
const int MAXn = 1000 * 100, mod = 1000 * 1000 * 1000 + 7;
int a[MAXn + 5], b[MAXn + 5];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n / k; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n / k; i++) scanf("%d", &b[i]);
  int num = 1;
  for (int i = 0; i < k - 1; i++) num *= 10;
  long long ans = 1;
  for (int i = 0; i < n / k; i++) {
    long long val, t;
    if (b[i] == 0)
      val = (num - 1) / a[i] + 1;
    else {
      val = (long long)((long long)(b[i] + 1) * num - 1) / a[i];
      val -= ((long long)b[i] * num - 1) / a[i];
    }
    t = ((long long)num * 10 - 1) / a[i] + 1;
    ans = ((long long)ans * (t - val)) % mod;
  }
  cout << ans << endl;
  return 0;
}
