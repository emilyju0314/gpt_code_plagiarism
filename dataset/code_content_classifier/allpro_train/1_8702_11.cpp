#include <bits/stdc++.h>
using namespace std;
const int M = 2 * (1000000007 - 1);
int n, cnt[200005], a[200005];
int pmod(int a, int n) {
  int ans = 1;
  while (n) {
    if (n & 1) ans = (1ll * ans * a) % 1000000007;
    a = (1ll * a * a) % 1000000007;
    n >>= 1;
  }
  return ans;
}
int main() {
  cin >> n;
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    ans = (1ll * ans * a[i]) % 1000000007;
    cnt[a[i]]++;
  }
  int x = 1;
  bool ok = 1;
  for (int i = 1; i < 200005; i++) {
    x = (1ll * x * (cnt[i] + 1)) % M;
    if (cnt[i] & 1) ok = 0;
  }
  x /= 2;
  ans = pmod(ans, x);
  if (ok)
    for (int i = 1; i < 200005; i++)
      ans = (1ll * ans * pmod(i, cnt[i] / 2)) % 1000000007;
  cout << ans;
  return 0;
}
