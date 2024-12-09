#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
const long long mod = 1e9 + 7;
long long powermodm(long long x, long long n, long long M) {
  long long result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = (result * x) % M;
    x = (x * x) % M;
    n = n / 2;
  }
  return result;
}
long long power(long long _a, long long _b) {
  long long _r = 1;
  while (_b) {
    if (_b % 2 == 1) _r = (_r * _a);
    _b /= 2;
    _a = (_a * _a);
  }
  return _r;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) {
  return (max(a, b) / gcd(a, b)) * min(a, b);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m;
  cin >> n >> m;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long l = 0, r = m - 1, ans = m - 1;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
      if (i == 0) {
        if (a[i] + mid >= m)
          arr[i] = 0;
        else
          arr[i] = a[i];
      } else {
        long long tmp = a[i] + mid;
        if (a[i] == arr[i - 1]) {
          arr[i] = arr[i - 1];
        } else if (a[i] > arr[i - 1]) {
          if (tmp >= m) {
            if (tmp % m >= arr[i - 1])
              arr[i] = arr[i - 1];
            else
              arr[i] = a[i];
          } else
            arr[i] = a[i];
        } else {
          if (tmp >= arr[i - 1])
            arr[i] = arr[i - 1];
          else
            arr[i] = a[i];
        }
      }
    }
    long long flag = 1;
    for (long long i = 1; i < n; i++) {
      if (arr[i] < arr[i - 1]) flag = 0;
    }
    if (flag) {
      ans = min(ans, mid);
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << ans;
  return 0;
}
