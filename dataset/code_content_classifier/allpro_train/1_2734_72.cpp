#include <bits/stdc++.h>
using namespace std;
int n, m, k;
long long get_sum(long long num, long long mid) {
  if (num >= mid)
    return mid * (mid - 1) / 2 + num - mid + 1;
  else
    return num * (mid - 1 + mid - num) / 2;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  int l = 1, r = m - n + 2, mid;
  while (r - l > 1) {
    mid = (l + r) / 2;
    long long sum1 = get_sum(k - 1, mid);
    long long sum2 = get_sum(n - k, mid);
    if (sum1 + sum2 + mid <= m)
      l = mid;
    else
      r = mid;
  }
  printf("%d\n", l);
}
