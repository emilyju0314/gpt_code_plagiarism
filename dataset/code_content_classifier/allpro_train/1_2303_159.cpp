#include <bits/stdc++.h>
using namespace std;
long long n, x, y;
bitset<20000009> mark;
long long d[20000009];
long long calc() {
  for (long long i = 1; i < 2 * n; i++) {
    d[i] = d[i - 1] + x;
    if (i % 2 == 0) d[i] = min(d[i], d[i / 2] + y);
    int k = i - 1;
    while (k >= 0 && d[k + 1] + x < d[k]) d[k] = d[k + 1] + x, k--;
  }
  long long ans = d[n];
  for (long long i = n + 1; i < 2 * n; i++) {
    ans = min(ans, d[i] + (i - n) * x);
  }
  return ans;
}
int main() {
  scanf("%I64d%I64d%I64d", &n, &x, &y);
  long long ans = calc();
  printf("%I64d\n", ans);
}
