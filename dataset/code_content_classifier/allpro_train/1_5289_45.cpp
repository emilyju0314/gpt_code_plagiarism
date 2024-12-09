#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int inf = 1e13;
int n, k;
long long a[N], b[N], c[N];
struct node {
  long long now, cost, sign;
  bool operator<(const node &a) const { return sign > a.sign; }
};
bool judge(long long x) {
  priority_queue<node> Q;
  for (int i = 1; i <= n; i++) Q.push({a[i], b[i], a[i] / b[i]});
  for (int i = 1; i <= k; i++) {
    node t1 = Q.top();
    Q.pop();
    if (t1.now / t1.cost + 1LL < 1LL * i) return false;
    if (t1.now / t1.cost + 1LL >= 1LL * k) return true;
    Q.push({t1.now + x, t1.cost, (t1.now + x) / t1.cost});
  }
  return true;
}
int main() {
  scanf("%d%d", &n, &k);
  long long bm = -1;
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%lld", &b[i]), bm = max(bm, b[i]);
  long long L = 0, R = (k - 1) * bm + 1, Mid, ans = -1;
  while (L <= R) {
    Mid = (L + R) >> 1;
    if (judge(Mid))
      ans = Mid, R = Mid - 1;
    else
      L = Mid + 1;
  }
  printf("%lld\n", ans);
  return 0;
}
