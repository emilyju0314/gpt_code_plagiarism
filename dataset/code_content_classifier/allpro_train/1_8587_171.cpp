#include <bits/stdc++.h>
using namespace std;
long long mul[250005];
long long inv[250005];
long long qp(long long a, long long b, long long p) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = a * ans % p;
    a = a * a % p;
    b >>= 1;
  }
  return ans;
}
int main() {
  long long n, m;
  cin >> n >> m;
  mul[0] = 1;
  for (int i = 1; i <= 250005 - 5; i++) mul[i] = mul[i - 1] * i % m;
  inv[250005 - 5] = qp(mul[250005 - 5], m - 2, m);
  for (int i = 250005 - 5; i >= 1; i--) inv[i - 1] = inv[i] * i % m;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long tem = n + 1 - i;
    tem *= n + 1 - i;
    tem %= m;
    tem *= mul[i];
    tem %= m;
    tem *= mul[n - i];
    tem %= m;
    ans += tem;
    ans %= m;
  }
  cout << ans << endl;
}
