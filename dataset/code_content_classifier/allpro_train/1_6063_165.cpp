#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
struct point {
  long double x, y;
  pair<long double, long double> centre_range(long double rad) {
    long double d = sqrtl(pow(rad, 2) - pow(rad - y, 2));
    return make_pair(x - d, x + d);
  }
};
point a[N];
long double bs(long long n);
bool check(long double rad, long long n);
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  bool pos = false, neg = false;
  for (long long i = 0; i < n; ++i) {
    long long x, y;
    cin >> x >> y;
    a[i].x = x;
    a[i].y = abs(y);
    if (y > 0) {
      pos = true;
    } else if (y < 0) {
      neg = true;
    }
  }
  if (pos && neg) {
    cout << "-1\n";
    return 0;
  }
  cout << fixed << setprecision(10) << bs(n) << "\n";
  return 0;
}
long double bs(long long n) {
  long double low = 0, high = 1e18, mid;
  for (long long i = 0; i < n; ++i) {
    low = max(low, abs(a[i].y));
  }
  low /= 2;
  for (long long iter = 0; iter <= 150; ++iter) {
    mid = low + (high - low) / 2;
    bool ok = check(mid, n);
    if (ok) {
      high = mid;
    } else {
      low = mid;
    }
  }
  return low;
}
bool check(long double rad, long long n) {
  long double left = -1e18, right = 1e18;
  pair<long double, long double> temp;
  for (long long i = 0; i < n; ++i) {
    temp = a[i].centre_range(rad);
    left = max(left, temp.first);
    right = min(right, temp.second);
  }
  return left <= right;
}
