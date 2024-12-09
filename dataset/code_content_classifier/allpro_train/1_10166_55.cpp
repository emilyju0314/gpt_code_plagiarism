#include <bits/stdc++.h>
using namespace std;
const int N = 10000005;
int cnt[N] = {0};
int flag[N] = {0};
int n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    cnt[k]++;
  }
  for (int i = N - 2; i >= 0; i--) cnt[i] += cnt[i + 1];
  long long ans = 1, ret, low, high, mid;
  for (int i = 2; i < N; i++) {
    if (flag[i]) continue;
    for (int j = 2; j * i < N; j++) flag[i * j] = 1;
    long long t = 0;
    for (long long p = i; p < N && p > 0; p *= (long long)i)
      for (long long q = p; q < N; q += (long long)p) t += cnt[q];
    if (t == 0) continue;
    low = ans, high = (1LL << 61);
    while (low <= high) {
      mid = (low + high) >> 1;
      long long temp = mid, tot = 0;
      while (temp) {
        temp /= i;
        tot += temp;
      }
      if (tot >= t)
        ans = mid, high = mid - 1;
      else
        low = mid + 1;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
