#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  long long sum = 0;
  for (int i = 0; i < n; i++) scanf("%d", a + i), sum += a[i];
  if (sum <= 1) {
    printf("-1\n");
    return 0;
  }
  vector<int> factor;
  for (int i = 2; i * i <= sum; i++) {
    if (sum % i == 0) {
      factor.push_back(i);
      while (sum % i == 0) {
        sum /= i;
      }
    }
  }
  if (sum > 1) factor.push_back(sum);
  long long re = 1e12;
  for (int it : factor) {
    long long tem = 0, extra = 0;
    for (int i = 0; i < n; i++) {
      extra += a[i];
      extra %= it;
      tem += min(extra, it - extra);
    }
    re = min(re, tem);
  }
  printf("%lld\n", re);
  return 0;
}
