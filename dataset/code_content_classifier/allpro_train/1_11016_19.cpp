#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
inline long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
inline long long int lcm(long long int a, long long int b) {
  return a * b / gcd(a, b);
}
inline long long int add(long long int a, long long int b) {
  return ((a % MOD) + (b % MOD)) % MOD;
}
inline long long int multi(long long int a, long long int b) {
  return ((a % MOD) * (b % MOD)) % MOD;
}
inline long long int sub(long long int a, long long int b) {
  a %= MOD;
  b %= MOD;
  a -= b;
  if (a < 0) a += MOD;
  return a;
}
inline long long int power(long long int a, long long int b) {
  a %= MOD;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = multi(res, a);
    }
    a = multi(a, a);
    b >>= 1;
  }
  return res;
}
bool isPrime(long long int x) {
  if (x <= 4 || x % 2 == 0 || x % 3 == 0) {
    return x == 2 || x == 3;
  }
  for (long long int i = 5; i * i <= x; i += 6) {
    if (x % i == 0 || x % (i + 2) == 0) {
      return 0;
    }
  }
  return 1;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  long long int c1 = 0, c2 = 0;
  vector<long long int> res;
  long long int ans = 0;
  bool flag = 0;
  for (long long int i = 0; i < n; i++) {
    if (s[i] == '1') c1++;
    if (t[i] == '1') c2++;
  }
  if (c1 != c2) {
    cout << -1;
    return 0;
  }
  long long int pos = 0, neg = 0;
  for (long long int i = 0; i < n; i++) {
    if (s[i] == '1' && t[i] == '0') {
      if (neg > 0) {
        pos++;
        neg--;
      } else
        pos++;
    } else if (s[i] == '0' && t[i] == '1') {
      if (pos > 0) {
        neg++;
        pos--;
      } else
        neg++;
    }
  }
  cout << neg + pos;
}
