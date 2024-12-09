#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long ans;
int n, a[N], b[N], v[N], Gcd[N];
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  cin >> n;
  for (int i = 0; i <= n - 1; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) Gcd[i] = gcd(i, n);
  for (int d = 1; d <= n; d++)
    if (n % d == 0) {
      for (int i = 0; i <= n - 1; i++) v[i] = b[i] = 0;
      for (int i = 0; i <= d - 1; i++)
        for (int k = 0; k <= n / d - 1; k++) b[i] = max(b[i], a[i + k * d]);
      for (int i = 0; i <= d - 1; i++)
        for (int k = 0; k <= n / d - 1; k++) b[i + k * d] = b[i];
      int l = 0, r = n - 1;
      while (l < n && a[l] >= b[l]) l++;
      if (l == n) {
        for (int i = 1; i <= n - 1; i++)
          if (Gcd[i] == d) ans += n;
        continue;
      }
      while (r >= 0 && a[r] >= b[r]) r--;
      for (int i = 1; i <= l + n - r - 1; i++)
        if (Gcd[i] == d) ans += l + n - r - i;
      while (l <= r) {
        int t = 0;
        if (a[l] < b[l]) {
          l++;
          continue;
        }
        while (l <= r && a[l] >= b[l]) l++, t++;
        for (int i = 1; i <= t; i++)
          if (Gcd[i] == d) ans += t - i + 1;
      }
    }
  cout << ans;
}
