#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
const int mod2 = 998244353;
long long exp(long long taban, long long us, long long md) {
  long long carpan = taban % md;
  if (carpan == 0) return 0;
  long long temp = us;
  long long res = 1;
  while (temp) {
    if (temp % 2) res = (res * carpan) % md;
    temp /= 2;
    carpan = (carpan * carpan) % md;
  }
  return res;
}
long long ebob(long long a, long long b) {
  if (!a) return b;
  return ebob(b % a, a);
}
long long ekok(long long a, long long b) { return (a * b) / ebob(a, b); }
long long mul(long long a, long long b, long long md) { return a * b % md; }
vector<long long> fact;
vector<long long> inv_fact;
void fact_init(int n) {
  fact.resize(n + 5);
  inv_fact.resize(n + 5);
  fact[0] = inv_fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
    inv_fact[i] = exp(fact[i], mod - 2, mod);
  }
}
long long komb(long long a, long long b) {
  return fact[a] * (inv_fact[a - b] * inv_fact[b] % mod) % mod;
}
const int N = 30 + 5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  unsigned long long a, b;
  cin >> a >> b;
  unsigned long long x = b, y = 0;
  a -= b;
  if (a < 0 || a % 2) {
    cout << -1;
    return 0;
  }
  a /= 2;
  if (x & a) {
    cout << -1;
    return 0;
  }
  x += a, y += a;
  cout << y << " " << x << endl;
}
