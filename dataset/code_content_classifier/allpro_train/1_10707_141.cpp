#include <bits/stdc++.h>
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
template <typename T, typename U>
static void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static void amax(T &x, U y) {
  if (x < y) x = y;
}
long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
using namespace std;
const long long MD = 998244353;
long long fact[8888888];
long long inv[8888888];
long long pot(long long x, long long y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  long long ans = 1;
  if (y % 2 == 1) ans = x;
  long long val = pot(x, y / 2);
  ans *= val;
  ans %= MD;
  ans *= val;
  ans %= MD;
  return ans;
}
void init() {
  fact[0] = 1;
  for (int i = 1; i <= 100000; i++) {
    fact[i] = i * fact[i - 1];
    fact[i] %= MD;
  }
  for (int i = 0; i <= 100000; i++) {
    inv[i] = pot(fact[i], MD - 2) % MD;
  }
}
long long comb(long long x, long long y) { return (fact[x] * inv[x - y]) % MD; }
long long fun(long long x, long long y, long long a) {
  return (((comb(x, a) * comb(y, a)) % MD) * inv[a]) % MD;
}
int main() {
  init();
  long long a, b, c;
  cin >> a >> b >> c;
  long long ans = 0;
  long long ini = 0;
  int maxi = min(a, c);
  for (int i = 0; i <= maxi; i++) {
    ini += fun(a, c, i);
    ini %= MD;
  }
  long long sum2 = 0;
  for (int i = 0; i <= min(b, c); i++) {
    sum2 += fun(b, c, i);
    sum2 %= MD;
  }
  int maxi1 = min(a, b), maxi2 = min(b, c);
  for (int i = 0; i <= maxi1; i++) {
    long long fin = (ini * fun(a, b, i)) % MD;
    fin *= sum2;
    fin %= MD;
    ans += fin;
    ans %= MD;
  }
  cout << ans << endl;
  return 0;
}
