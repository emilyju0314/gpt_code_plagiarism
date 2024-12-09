#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int n, p, pos, t[maxn], vis[maxn];
long long tim, ans[maxn];
queue<int> pre;
priority_queue<int, vector<int>, greater<int> > pp;
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    q;
inline void Update(int x, int d) {
  for (; x <= n; x = x + (x & -x)) vis[x] = vis[x] + d;
}
inline int Query(int x) {
  for (int res = 0;; res = res + vis[x], x = x - (x & -x))
    if (x == 0) return res;
}
int main(int argc, char const *argv[]) {
  scanf("%d%d", &n, &p);
  for (int i = 1; i <= n; ++i) scanf("%d", t + i), q.push(make_pair(t[i], i));
  tim = q.top().first, pos = 0;
  while (!q.empty() || !pre.empty() || !pp.empty()) {
    while (!q.empty() && tim > q.top().first) {
      if (!pp.empty() && pp.top() < q.top().second && Query(pp.top()) == 0)
        pre.push(pp.top()), Update(pp.top(), 1), pp.pop();
      if (Query(q.top().second) == 0)
        pre.push(q.top().second), Update(q.top().second, 1), q.pop();
      else
        pp.push(q.top().second), q.pop();
    }
    if (pos) Update(pos, -1);
    while (!q.empty() && tim == q.top().first) {
      if (!pp.empty() && pp.top() < q.top().second && Query(pp.top()) == 0)
        pre.push(pp.top()), Update(pp.top(), 1), pp.pop();
      if (Query(q.top().second) == 0)
        pre.push(q.top().second), Update(q.top().second, 1), q.pop();
      else
        pp.push(q.top().second), q.pop();
    }
    if (!pp.empty() && Query(pp.top()) == 0)
      pre.push(pp.top()), Update(pp.top(), 1), pp.pop();
    if (pre.empty())
      tim = q.top().first, pos = 0;
    else
      tim = tim + p, ans[pos = pre.front()] = tim, pre.pop();
  }
  for (int i = 1; i <= n; ++i) printf("%I64d ", ans[i]);
  return 0;
}
