#include <bits/stdc++.h>
const double PI = acos(-1), EPS = 1e-7;
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
long long gcd(long long x, long long y) { return (!y) ? x : gcd(y, x % y); }
long long lcm(long long x, long long y) { return ((x / gcd(x, y)) * y); }
const long long mod = 998244353;
long long power(long long x, long long y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  long long r = power(x, y / 2) % mod;
  return r % mod * r % mod * power(x, y % 2) % mod;
}
void file() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  file();
  int n;
  cin >> n;
  if (n == 1)
    cout << "-1" << '\n';
  else
    cout << n << " " << n + 1 << " " << n * (n + 1) << '\n';
}
