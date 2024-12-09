#include <bits/stdc++.h>
std::map<long long, long long> mm2;
long long arr[200005], qsum[200005], fuck;
int main() {
  long long n, i, i2, k, ans = 0, i3, sum = 0, hh = 0;
  scanf("%I64d %I64d", &n, &k);
  fuck = (1 << k) - 1;
  for (i = 1; i <= n; i++) {
    scanf("%I64d", &arr[i]);
    qsum[i] = (qsum[i - 1] ^ arr[i]);
  }
  mm2[0] = 1;
  for (i = 1; i <= n; i++) {
    if (mm2.find(qsum[i]) == mm2.end()) {
      mm2[qsum[i]] = 1;
      qsum[i] = qsum[i];
    } else if (mm2.find(fuck - qsum[i]) == mm2.end()) {
      mm2[fuck - qsum[i]] = 1;
      qsum[i] = fuck - qsum[i];
    } else if (mm2[qsum[i]] < mm2[fuck - qsum[i]]) {
      hh += mm2[qsum[i]];
      mm2[qsum[i]]++;
      qsum[i] = qsum[i];
    } else {
      hh += mm2[fuck - qsum[i]];
      mm2[fuck - qsum[i]]++;
      qsum[i] = fuck - qsum[i];
    }
  }
  printf("%I64d", n * (n + 1) / 2 - hh);
  return 0;
}
