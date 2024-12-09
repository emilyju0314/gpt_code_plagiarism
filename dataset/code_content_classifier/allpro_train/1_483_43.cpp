#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, size[N], odd[N], dep[N], fa[N];
vector<int> e[N];
bool match = 1;
long long ans;
void dfs(int x, int f) {
  fa[x] = f;
  size[x] = 1;
  for (auto v : e[x])
    if (v != f) {
      dep[v] = dep[x] + 1;
      dfs(v, x);
      size[x] += size[v];
      odd[x] += size[v] & 1;
    }
  odd[x] += (size[x] & 1);
  if (odd[x] > 1) match = 0;
  if (odd[x] > 3) puts("0"), exit(0);
}
long long cnt[N], sum[N];
void solve(int x, int f) {
  size[x] = 1;
  long long cnt_good = 0, cnt_bad = 0;
  long long sum_good = 0, sum_bad = 0;
  for (auto v : e[x])
    if (v != f) {
      dep[v] = dep[x] + 1;
      solve(v, x);
      size[x] += size[v];
      if (size[v] & 1) {
        ans += sum[v];
        ans += sum_good * cnt[v] + sum[v] * cnt_good;
        cnt_bad += cnt[v];
        sum_bad += sum[v];
      } else {
        ans += sum_bad * cnt[v] + sum[v] * cnt_bad;
        cnt_good += cnt[v];
        sum_good += sum[v];
      }
    }
  if (size[x] & 1)
    cnt[x] = cnt_good + 1, sum[x] = sum_good + cnt[x];
  else
    cnt[x] = cnt_bad, sum[x] = sum_bad;
}
int x, y, D = -1, q[N], m, edge[N];
bool visit(int x, int fa, int dep) {
  if (odd[x] == 3 && dep > D) D = dep, y = x;
  bool ans = odd[x] == 3;
  int cnt = 0;
  for (auto v : e[x])
    if (v != fa && visit(v, x, dep + 1)) cnt++, ans = 1;
  if (cnt > 1) puts("0"), exit(0);
  if (ans) q[++m] = x;
  return ans;
}
int main() {
  scanf("%d", &n);
  if (n & 1) return puts("0"), 0;
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1, 0);
  if (match) {
    solve(1, 0);
    for (int i = 2; i <= n; i++)
      if (!(size[i] & 1)) ans += 1ll * size[i] * (n - size[i]);
    printf("%lld\n", ans);
  } else {
    dep[0] = -1;
    for (int i = 1; i <= n; i++)
      if (odd[i] == 3 && dep[i] > dep[x]) x = i;
    visit(x, 0, 0);
    for (int i = 1; i < m; i++) edge[i] = min(size[q[i]], size[q[i + 1]]) & 1;
    for (int i = 1; i < m; i++)
      if (!edge[i] && !edge[i + 1]) puts("0"), exit(0);
    for (int i = 2; i < m; i++)
      if (odd[q[i]] == 3 && (!edge[i - 1] || !edge[i])) puts("0"), exit(0);
    int len = 0;
    for (int i = 1; i < m; i++) len += edge[i];
    if (m == 1) {
      solve(x, 0);
      ans = 0;
      m = 0;
      for (auto v : e[x])
        if (size[v] & 1) q[++m] = v;
      ans += cnt[q[1]] * (sum[q[2]] + sum[q[3]]);
      ans += cnt[q[2]] * (sum[q[1]] + sum[q[3]]);
      ans += cnt[q[3]] * (sum[q[1]] + sum[q[2]]);
      printf("%lld\n", ans);
    } else {
      solve(q[1], q[2]);
      solve(q[m], q[m - 1]);
      ans = 0;
      long long cntx = 0, sumx = 0, cnty = 0, sumy = 0;
      for (auto v : e[q[1]])
        if (v != q[2] && (size[v] & 1)) cntx += cnt[v], sumx += sum[v];
      for (auto v : e[q[m]])
        if (v != q[m - 1] && (size[v] & 1)) cnty += cnt[v], sumy += sum[v];
      ans = cntx * cnty * len + cntx * sumy + cnty * sumx;
      printf("%lld\n", ans);
    }
  }
  return 0;
}
