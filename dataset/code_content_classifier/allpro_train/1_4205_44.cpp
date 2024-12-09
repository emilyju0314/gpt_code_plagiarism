#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
long long pers[maxn], sum = 0;
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &pers[i]);
    sum += pers[i];
  }
  sort(pers + 1, pers + 1 + n);
  int l1 = sum / n, r1 = (sum + n - 1) / n;
  int l = 0, r = l1, ans1 = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    long long tmp = 0;
    for (int i = 1; i <= n; i++) {
      if (pers[i] <= mid) tmp += mid - pers[i];
    }
    if (tmp <= k) {
      ans1 = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  l = r1, r = 1e9;
  int ans2 = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    long long tmp = 0;
    for (int i = 1; i <= n; i++) {
      if (pers[i] > mid) tmp += pers[i] - mid;
    }
    if (tmp <= k) {
      ans2 = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  printf("%d\n", ans2 - ans1);
  return 0;
}
