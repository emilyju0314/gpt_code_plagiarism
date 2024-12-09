#include <bits/stdc++.h>
using namespace std;
long long modpow(long long base, long long exp, long long modulus) {
  base %= modulus;
  long long result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}
int main() {
  long long n;
  cin >> n;
  long long a[n];
  map<long long, long long> m;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long t;
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) m[a[i] + a[j]]++;
  }
  long long mx = 0;
  for (auto x : m) {
    mx = max(x.second, mx);
  }
  cout << mx;
  return 0;
}
