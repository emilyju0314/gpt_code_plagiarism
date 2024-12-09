#include <bits/stdc++.h>
using namespace std;
vector<long long int> fact(200005);
vector<long long int> prime_check(1e6 + 2);
vector<long long int> primes;
long long powmod(long long x, long long y, long long m) {
  long long res = 1LL;
  while (y) {
    if (y & 1) res = (res * x) % m;
    x = (x * x) % m;
    y /= 2;
  }
  return res;
}
void init_fact() {
  fact[0] = 1;
  for (long long int i = 1; i < 200005; i++) {
    fact[i] = (fact[i - 1] * i) % 1000000009;
  }
}
long long int C(long long int n, long long int r) {
  if (n < r) return 0;
  long long int temp =
      fact[n] * powmod(fact[r], 1000000009 - 2, 1000000009) % 1000000009;
  temp *= powmod(fact[n - r], 1000000009 - 2, 1000000009);
  temp %= 1000000009;
  return temp;
}
void Sieve() {
  for (long long int i = 2; i <= 1e6 + 1; i++) {
    if (prime_check[i]) continue;
    primes.push_back(i);
    for (long long int j = 2 * i; j <= 1e6 + 2; j += i) prime_check[j] = i;
  }
}
long long int phi(long long int n) {
  long long int i, res = n;
  for (i = 2; i * i <= n; i++)
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      res -= res / i;
    }
  if (n > 1) res -= res / n;
  return res;
}
long long int n;
vector<long long int> a(200005), a1(200005);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (long long int i = 1; i <= n; i++) cin >> a[i];
  long long int ans = 0;
  a1[1] = a[1];
  for (long long int i = 2; i <= n; i++) a1[i] = a1[i - 2] + a[i];
  ans = a1[n];
  for (long long int i = 2; i <= n; i++) {
    if (i % 2 == 0)
      ans = max(ans, a1[i - 1] + a1[n - 1] - a1[i - 2]);
    else
      ans = max(ans, a1[i - 1] + a1[n] - a1[i - 2]);
  }
  cout << ans << "\n";
}
