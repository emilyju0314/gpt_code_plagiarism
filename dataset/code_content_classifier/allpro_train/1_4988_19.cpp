#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int Pow(register int a, register int x, register int ans = 1) {
  for (; x; x >>= 1, a = 1ll * a * a % mod)
    if (x & 1) ans = 1ll * ans * a % mod;
  return ans;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  printf("%lld\n", 1ll * (n + 1 - m) * Pow(n + 1, mod - 2) % mod *
                       Pow(2 * (n + 1), m) % mod);
  return 0;
}
