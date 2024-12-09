#include <bits/stdc++.h>
using namespace std;
long long tim[2000100], cost[2000100], ans[2000100], cop[2000100];
int main() {
  long long n, sz;
  scanf("%lld%lld", &n, &sz);
  for (long long i = 1; i <= n; i++) scanf("%lld%lld", &tim[i], &cost[i]);
  tim[n + 1] = 10000000000000000ll;
  long long T = 0, remain = 0, id = 0, head = 0, tail = 0;
  for (long long now = 1; now <= n; now++) {
    while ((head != tail) && (T + remain <= tim[now])) {
      T = T + remain;
      remain = 0;
      ans[id] = T;
      id = cop[++tail];
      remain = cost[id];
    }
    if ((id) && (T + remain <= tim[now])) {
      T = T + remain;
      remain = 0;
      ans[id] = T;
      id = remain = 0;
    }
    remain -= tim[now] - T;
    remain = max(remain, 0ll);
    T = tim[now];
    if (head - tail == sz) {
      ans[now] = -1;
      continue;
    }
    cop[++head] = now;
  }
  while (head != tail) {
    T = T + remain;
    remain = 0;
    ans[id] = T;
    id = cop[++tail];
    remain = cost[id];
  }
  ans[id] = T + remain;
  for (long long i = 1; i <= n; i++) printf("%lld ", ans[i]);
}
