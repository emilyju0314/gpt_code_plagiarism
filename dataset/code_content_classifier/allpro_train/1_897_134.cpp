#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
vector<bool> primes(100005);
void sieve() {
  for (int i = 0; i < 100005; ++i) primes[i] = true;
  primes[0] = false;
  primes[1] = false;
  for (int i = 2; i * i <= 100004; ++i) {
    if (primes[i]) {
      for (int j = 2 * i; j <= 100004; j += i) primes[j] = false;
    }
  }
}
int phi(int n) {
  float result = n;
  for (int p = 2; p * p <= n; ++p) {
    if (n % p == 0) {
      while (n % p == 0) n /= p;
      result *= (1.0 - (1.0 / (float)p));
    }
  }
  if (n > 1) result *= (1.0 - (1.0 / (float)n));
  return (int)result;
}
bool isPrime(long long int n) {
  if (n == 2 || n == 3) return true;
  for (long long int i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  int test = 1;
  while (test--) {
    int n;
    cin >> n;
    if (n < 3) {
      cout << -1;
      exit(0);
    } else if (n == 3) {
      cout << "210";
      exit(0);
    }
    int rem = 1;
    for (int i = 1; i < n; ++i) {
      rem = (rem * 10) % 210;
    }
    int adder = 210 - rem;
    string s = "000";
    int i = 2;
    while (i >= 0) {
      s[i] = char((adder % 10) + 48);
      adder /= 10;
      i--;
    }
    cout << "1";
    for (int i = 2; i < n - 2; ++i) cout << "0";
    cout << s;
  }
  return 0;
}
