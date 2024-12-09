#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
long long have[maxn], need[maxn];
int main() {
  int n, k, i;
  scanf("%d%d", &n, &k);
  for (i = 1; i <= n; i++) scanf("%lld", need + i);
  for (i = 1; i <= n; i++) scanf("%lld", have + i);
  long long l = 0, r = 2e9;
  long long mid;
  while (l <= r) {
    mid = (l + r) >> 1;
    long long s = k, flag = 0;
    for (int i = 1; i <= n; i++) {
      if (mid * need[i] > have[i]) {
        s -= (mid * need[i] - have[i]);
        if (s < 0) {
          flag = 1;
          break;
        }
      }
    }
    if (flag)
      r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%lld\n", r);
}
