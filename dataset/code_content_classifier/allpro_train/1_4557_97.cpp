#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
struct node {
  long long t, val;
} e;
bool operator<(node a, node b) { return a.t < b.t; }
int n;
long long ret, ans, w[N];
priority_queue<node> s;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &w[i]);
  s.push({w[1] - 1, 0}), ret = w[1];
  for (int i = 2; i <= n; i++) {
    long long val = 0;
    while (s.top().t >= w[i]) {
      e = s.top(), s.pop(),
      val = max(val, (e.t - w[i] + 1) / w[i] * w[i] * (i - 1) + e.val);
      s.push({e.t % w[i], e.val + (e.t - e.t % w[i]) * (i - 1)});
    }
    if (w[i] <= ret) ret = w[i];
    s.push({ret - 1, val});
  }
  while (!s.empty()) e = s.top(), s.pop(), ans = max(ans, e.val + e.t * n);
  cout << ans << endl;
  return 0;
}
