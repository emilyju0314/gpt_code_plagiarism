#include <bits/stdc++.h>
using namespace std;
long long n, divi;
vector<long long> v;
void sieve(long long n) {
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (long long i = 2; i * i <= n; i++)
    if (is_prime[i])
      for (long long j = i * i; j <= n; j += i) is_prime[j] = false;
  for (long long i = 0; i <= n; i++)
    if (is_prime[i]) v.push_back(i);
}
bool isprime(long long x) {
  for (long long i = 2; i * i <= x; i++)
    if (n % i == 0) return false;
  return true;
}
void solve(long long x) {
  long long ret = 0;
  while (x > 0) {
    if (x % 2 == 0) {
      ret += x / 2;
      break;
    } else if (isprime(x)) {
      ret += 1;
      break;
    } else {
      for (int i = 0;; i++)
        if (x % v[i] == 0) {
          x -= v[i];
          break;
        }
      ret++;
    }
  }
  cout << ret << endl;
}
int main() {
  cin >> n;
  sieve(ceil(sqrt(n)));
  solve(n);
}
