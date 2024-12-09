#include <bits/stdc++.h>
const long long INF = (long long)1e7 + 1;
using namespace std;
void solve();
void fastIO() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  fastIO();
  solve();
}
long long int pw(long long int k, long long int x);
long long int gcd(long long int x, long long int y);
void solve() {
  int test;
  test = 1;
  while (test--) {
    long long int n;
    cin >> n;
    int cnt = 0;
    long long int temp = n;
    long long int x;
    for (long long int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        while (n % i == 0) {
          n /= i;
        }
        cnt++;
        x = i;
      }
    }
    if (cnt == 0) {
      cout << temp;
    } else if (cnt == 1 && n == 1) {
      cout << x;
    } else
      cout << 1;
  }
}
long long int gcd(long long int x, long long int y) {
  if (x == 0)
    return y;
  else
    return gcd(y % x, x);
}
long long int pw(long long int k, long long int x) {
  if (x == 0) return 1;
  if (x & 1)
    return ((pw(k, x - 1) % 1000000007) * k % 1000000007) % 1000000007;
  else
    return ((pw(k, x / 2) % 1000000007) * (pw(k, x / 2) % 1000000007)) %
           1000000007;
}
