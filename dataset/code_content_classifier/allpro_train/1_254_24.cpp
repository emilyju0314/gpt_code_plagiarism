#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, w = 0;
  char ch = getchar();
  while (!isdigit(ch)) w |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
  return w ? -x : x;
}
long long a[500000], sum[500000], b[500000], ans;
inline long long calc(long long k) {
  long long res = 0;
  for (; k; k &= k - 1) ++res;
  return res;
}
signed main() {
  long long n = read();
  for (long long i = 1; i <= n; ++i)
    a[i] = calc(read()), sum[i] = sum[i - 1] + a[i];
  b[0] = 1;
  for (long long i = 1; i <= n; ++i) {
    ans += b[sum[i] & 1]++;
    ans -= ((sum[i] & 1) == (sum[i - 1] & 1));
  }
  for (long long i = 1; i <= n; ++i) {
    long long mx = a[i];
    for (long long j = i - 1; j >= max(1ll, i - 64); --j) {
      mx = max(mx, a[j]);
      long long t = sum[i] - sum[j - 1];
      if (!(t & 1) && mx > t - mx) --ans;
    }
  }
  cout << ans;
  return 0;
}
