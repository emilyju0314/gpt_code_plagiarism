#include <bits/stdc++.h>
using namespace std;
struct node {
  long long id, val;
  bool operator<(node oth) const { return val > oth.val; }
};
long long n, m;
long long c[100005], w[100005], vis[100006], ans;
priority_queue<node> q;
int main() {
  scanf("%I64d%I64d", &n, &m);
  for (long long i = 1; i <= n; ++i) scanf("%I64d", c + i);
  for (long long i = 1; i <= n; ++i) scanf("%I64d", w + i);
  for (long long i = 1; i <= n; ++i) {
    if (c[i] % 100 == 0) continue;
    q.push((node){i, w[i] * (100 - c[i] % 100)});
    m -= c[i] % 100;
    if (m < 0) {
      vis[q.top().id] = 1;
      ans += q.top().val;
      q.pop();
      m += 100;
    }
  }
  printf("%I64d\n", ans);
  for (long long i = 1; i <= n; ++i) {
    if (vis[i])
      printf("%I64d %I64d\n", c[i] / 100 + 1, 0);
    else
      printf("%I64d %I64d\n", c[i] / 100, c[i] % 100);
  }
}
