#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
long long q_pow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    scanf("%lld", &n);
    long long bg = 0, ed = 0, len;
    long long sum = 0, k = 1;
    for (int i = 1;; i++, k++) {
      len = q_pow(10, i) - q_pow(10, i - 1);
      bg = ed + i;
      ed = bg + (len - 1) * i;
      long long cnt = (bg + ed) * len / 2;
      if (sum + cnt >= n) break;
      sum += cnt;
    }
    n = n - sum;
    long long l = 0, r = len, mid;
    long long x;
    while (l <= r) {
      mid = (l + r) >> 1;
      long long y = (bg + bg + (mid - 1) * k) * mid / 2;
      if (y < n) {
        l = mid + 1;
        x = mid;
      } else
        r = mid - 1;
    }
    long long m = q_pow(10, k - 1) + x;
    n -= (bg + bg + (x - 1) * k) * x / 2;
    sum = 0, k = 0;
    for (int i = 0;; i++, k++) {
      long long cnt = (i + 1) * (q_pow(10, i + 1) - q_pow(10, i));
      if (sum + cnt >= n) break;
      sum += cnt;
    }
    n -= sum;
    x = n / (k + 1);
    if (n % (k + 1) == 0) x--;
    n -= x * (k + 1);
    x = q_pow(10, k) + x;
    stack<int> s;
    while (x) {
      s.push(x % 10);
      x /= 10;
    }
    while (!s.empty()) {
      n--;
      if (n == 0) {
        printf("%d\n", s.top());
        break;
      }
      s.pop();
    }
  }
  return 0;
}
