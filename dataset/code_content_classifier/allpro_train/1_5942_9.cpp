#include <bits/stdc++.h>
using namespace std;
const int N = 32;
int n, l;
int cost[N];
int main() {
  scanf("%d %d", &n, &l);
  for (int i = 0; i < n; i++) {
    scanf("%d", &cost[i]);
  }
  for (int i = 1; i < n; i++) {
    cost[i] = min(cost[i], cost[i - 1] * 2);
  }
  long long ans = 2e18, here = 0;
  for (int i = n - 1; i >= 0; i--) {
    long long buy = l / (1 << i);
    l -= buy * (1 << i);
    here += buy * cost[i];
    ans = min(ans, here + (l > 0) * cost[i]);
  }
  printf("%I64d\n", ans);
  return 0;
}
