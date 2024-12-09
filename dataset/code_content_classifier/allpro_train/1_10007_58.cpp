#include <bits/stdc++.h>
using namespace std;
long long n, k, b, c, a[200100], pre[200100];
int main() {
  scanf("%lld%lld%lld%lld", &n, &k, &b, &c);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
  sort(a, a + n);
  long long tmp = -a[0];
  for (int i = 0; i < n; ++i) {
    a[i] += tmp;
  }
  if (b >= c * 5) {
    for (int i = 0; i < n; ++i) {
      pre[i + 1] = pre[i] + a[i];
    }
    long long ans = c * (k * a[k - 1] - pre[k]);
    for (long long i = k; i <= n; ++i) {
      ans = min(ans, c * (k * a[i - 1] - pre[i] + pre[i - k]));
    }
    printf("%lld\n", ans);
    return 0;
  }
  long long ans = 0x3f3f3f3f3f3f3f3fLL;
  for (int T = 0; T < 5; ++T) {
    long long sum = 0;
    priority_queue<long long> q;
    for (int i = 0; i < n; ++i) {
      long long now = a[i];
      long long value = 0;
      while (now % 5 != T) {
        now++;
        value += c;
      }
      value -= b * (now - T) / 5;
      sum += value;
      q.push(value);
      if (q.size() > k) {
        sum -= q.top();
        q.pop();
      }
      if (q.size() == k) {
        ans = min(ans, k * b * (now - T) / 5 + sum);
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
