#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int maxn = 1e9, minn = -1e9;
long long modpow(long long base, long long exp, int modulus) {
  base %= modulus;
  long long result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}
int sqr(int x) { return x * x; }
bool is_prime(int x) {
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long x = 1234567, y = 123456, z = 1234;
  int n;
  scanf("%d", &n);
  bool ans = false;
  for (long long i = 0; i <= n; i += x) {
    for (long long j = 0; j <= n; j += y) {
      long long c = n - i - j;
      if (c % z == 0 && c >= 0) ans = true;
    }
  }
  if (ans)
    cout << "yes";
  else
    cout << "no";
  return 0;
}
