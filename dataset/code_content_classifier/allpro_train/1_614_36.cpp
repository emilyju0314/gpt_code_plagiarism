#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10;
int ans[maxn];
int main() {
  long long n, k;
  scanf("%lld%lld", &n, &k);
  long long sum = (n + 1) * n >> 1;
  if (k < sum) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= n; i++) ans[i] = i;
  int l = 1, r = n;
  while (l < r) {
    if (sum + r - l <= k) {
      swap(ans[l], ans[r]);
      sum += r - l;
      l++;
      r--;
    } else {
      int p = k - sum + l;
      swap(ans[l], ans[p]);
      sum += p - l;
      break;
    }
  }
  printf("%lld\n", sum);
  for (int i = 1; i <= n; i++) printf("%d%c", i, i == n ? '\n' : ' ');
  for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
}
