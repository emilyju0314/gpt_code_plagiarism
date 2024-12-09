#include <bits/stdc++.h>
using namespace std;
void c_p_c() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
vector<long long> Sieve(long long n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long i = 2; i * i <= n; i++) {
    if (prime[i]) {
      for (long long j = i * i; j <= n; j += i) {
        prime[j] = false;
      }
    }
  }
  vector<long long> primes;
  for (long long i = 2; i <= n; i++) {
    if (prime[i]) primes.push_back(i);
  }
  return primes;
}
set<long long> primeFactors(long long n) {
  set<long long> factors;
  while (n % 2 == 0) {
    n /= 2;
    factors.insert(2);
  }
  for (long long i = 3; i <= sqrt(n); i += 2) {
    while (n % i == 0) {
      factors.insert(i);
      n /= i;
    }
  }
  if (n > 2) factors.insert(n);
  return factors;
}
bool isTriangle(long long x, long long y, long long z) {
  if (x + y > z && x + z > y && y + z > x)
    return true;
  else
    return false;
}
int32_t main() {
  c_p_c();
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    sum += max(abs(s[i] - 'a'), abs(s[i] - 'z'));
  }
  if (sum < k)
    cout << -1 << endl;
  else {
    for (long long i = 0; i < n; i++) {
      if (k == 0) break;
      if (k > abs(s[i] - 'a') && k > abs(s[i] - 'z')) {
        if (abs(s[i] - 'a') >= abs(s[i] - 'z')) {
          k -= abs(s[i] - 'a');
          s[i] = 'a';
        } else {
          k -= abs(s[i] - 'z');
          s[i] = 'z';
        }
      } else {
        if (s[i] + k <= 'z') {
          s[i] = s[i] + k;
          k = 0;
        } else if (s[i] - k >= 'a') {
          s[i] = s[i] - k;
          k = 0;
        }
      }
    }
    cout << s << endl;
  }
}
