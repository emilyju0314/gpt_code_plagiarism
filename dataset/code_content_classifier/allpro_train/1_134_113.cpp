#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, k, p;
int a[1050], b[2050];
bool judge(long long x) {
  int pos = -1;
  for (int i = 0; i < n; i++) {
    while (pos <= k) {
      pos++;
      if ((long long)(abs(a[i] - b[pos]) + abs(p - b[pos])) <= x) break;
    }
    if (pos >= k) return 0;
  }
  return 1;
}
int main() {
  scanf("%d%d%d", &n, &k, &p);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  for (int i = 0; i < k; i++) scanf("%d", &b[i]);
  sort(b, b + k);
  long long ans = 0x3f3f3f3f3f3f3f3f;
  long long l = 0, r = ans;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (judge(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  printf("%I64d\n", ans);
  return 0;
}
