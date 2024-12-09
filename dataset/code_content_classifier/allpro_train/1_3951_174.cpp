#include <bits/stdc++.h>
using namespace std;
int main(void) {
  long long n, k;
  cin >> n >> k;
  long long m = k * (k + 1) / 2;
  if (k >= 150000 || m > n) {
    printf("-1");
    return 0;
  }
  long long sn = sqrt(n), ans = 0;
  for (long long i = 1; i <= sn; ++i)
    if (n % i == 0) {
      if (n / i >= m) ans = max(ans, i);
      if (i >= m) ans = max(ans, n / i);
    }
  n /= ans;
  for (long long i = 1; i < k; ++i) {
    cout << ans * i << " ";
    n -= i;
  }
  cout << ans * n;
  return 0;
}
