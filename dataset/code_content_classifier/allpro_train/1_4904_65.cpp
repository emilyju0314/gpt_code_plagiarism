#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double PI = acos(-1);
int n, deg[N], deptha[N], depthb[N];
vector<int> G[N];
queue<int> que;
vector<pair<pair<int, int>, int>> vc;
pair<int, int> dfs(int u, int fa, int* depth) {
  if (fa)
    depth[u] = depth[fa] + 1;
  else
    depth[u] = 0;
  pair<int, int> ans = make_pair(depth[u], u);
  for (auto& v : G[u]) {
    if (v == fa) continue;
    ans = max(ans, dfs(v, u, depth));
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  int A = dfs(1, 0, deptha).second;
  int B = dfs(A, 0, deptha).second;
  dfs(B, 0, depthb);
  for (int i = 1; i <= n; i++)
    if (i != A && i != B && deg[i] == 1) que.push(i);
  long long ans = 0;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    if (deptha[u] > depthb[u]) {
      ans += deptha[u];
      vc.push_back(make_pair(make_pair(A, u), u));
    } else {
      ans += depthb[u];
      vc.push_back(make_pair(make_pair(B, u), u));
    }
    for (auto& v : G[u])
      if (--deg[v] == 1) que.push(v);
  }
  que.push(B);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    if (u == A) break;
    ans += deptha[u];
    vc.push_back(make_pair(make_pair(A, u), u));
    for (auto& v : G[u])
      if (--deg[v] == 1) que.push(v);
  }
  printf("%lld\n", ans);
  for (auto& t : vc)
    printf("%d %d %d\n", t.first.first, t.first.second, t.second);
  return 0;
}
