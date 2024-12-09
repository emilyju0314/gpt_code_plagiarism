#include <bits/stdc++.h>
using namespace std;
const double pi =
    3.141592653589793238462643383279502884197169399375105820974944;
const double e = 2.71828182845904523536028747135266249775724709369995;
const long long mod = 1e9 + 7;
const unsigned long long inf = 9e18;
const long long ninf = -9e18;
const long long nax = 1e6;
const double err = 1e-9;
long long i, j, k, t, l, n, m, p, x, q, r, flag = 0, ctr = 0, mini, maxi,
                                           sum = 0, ans = 0;
string s, str;
vector<long long> a, b, arr;
vector<bool> sieve(nax + 10, true);
bool comp(const long long &a, const long long &b) { return a < b; }
bool isequal(double a, double b) { return abs(a - b) < err; }
void siev(long long n) {
  sieve[0] = false;
  sieve[1] = false;
  for (long long i = 2; i <= sqrtl(n); i++) {
    if (sieve[i]) {
      for (long long j = i; i * j <= n; j++) {
        sieve[i * j] = false;
      }
    }
  }
}
long long power(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans *= x;
    x *= x;
    y >>= 1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> x;
  sum = 0;
  for (i = 0; i < n; i++) {
    cin >> l;
    a.push_back(l);
    sum += l;
  }
  long long zero = x - sum;
  if (zero == n - 1)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
