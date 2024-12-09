#include <bits/stdc++.h>
using namespace std;
long long x, y, n, c;
bool check(long long t) {
  long long ans = 2 * t * t + 2 * t + 1;
  if (x + t > n) {
    long long m = x + t - n;
    ans -= m * m;
  }
  if (y + t > n) {
    long long m = y + t - n;
    ans -= m * m;
  }
  if (x - 1 < t) {
    long long m = t - x + 1;
    ans -= m * m;
  }
  if (y - 1 < t) {
    long long m = t - y + 1;
    ans -= m * m;
  }
  if (x - 1 + y - 1 < t) {
    long long a = t - (x - 1 + y - 1) - 1;
    ans += a * (a + 1) / 2;
  }
  if (x - 1 + n - y < t) {
    long long a = t - (x - 1 + n - y) - 1;
    ans += a * (a + 1) / 2;
  }
  if (n - x + y - 1 < t) {
    long long a = t - (n - x + y - 1) - 1;
    ans += a * (a + 1) / 2;
  }
  if (n - x + n - y < t) {
    long long a = t - (n - x + n - y) - 1;
    ans += a * (a + 1) / 2;
  }
  return ans >= c;
}
int main() {
  while (cin >> n >> x >> y >> c) {
    long long low = 0, high = 2 * n, mid;
    while (low < high) {
      mid = (low + high) / 2;
      if (check(mid))
        high = mid;
      else
        low = mid + 1;
    }
    cout << low << endl;
  }
  return 0;
}
