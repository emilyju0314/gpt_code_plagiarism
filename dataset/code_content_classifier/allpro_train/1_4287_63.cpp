#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) { return (a > b); }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
bool prime[1000000];
void sieve() {
  prime[2] = true;
  for (int i = 4; i <= 1000000; i += 2) {
    prime[i] = false;
    prime[i - 1] = true;
  }
  for (int i = 3; i <= 1000; i += 2) {
    if (prime[i]) {
      for (int j = i * i; j <= 1000000; j += 2 * i) {
        prime[j] = false;
      }
    }
  }
}
bool p(long long x) {
  if (x % 2 == 0) {
    return 0;
  }
  for (int i = 3; i * i <= x; i += 2) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}
string a[100006];
int main() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++)
    if (a[i].substr(0, s.length()) == s) {
      cout << a[i];
      return 0;
    }
  cout << s;
  return 0;
}
