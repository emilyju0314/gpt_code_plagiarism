#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
vector<int> G[maxn];
int a[maxn];
int dis[maxn];
bool vis[maxn];
int n, m, s, k;
struct Node {
  int n, val;
};
priority_queue<int, vector<int>, greater<int>> q[maxn];
void work() {
  for (int i = 1; i <= s; i++) {
    queue<Node> que;
    memset(dis, INF, sizeof(dis));
    memset(vis, false, sizeof(vis));
    for (int j = 1; j <= n; j++)
      if (a[j] == i) {
        dis[j] = 0;
        vis[j] = true;
        que.push((Node){j, 0});
      }
    while (!que.empty()) {
      auto x = que.front();
      que.pop();
      int u = x.n;
      for (int v : G[u]) {
        if (!vis[v]) {
          dis[v] = dis[u] + 1;
          vis[v] = true;
          que.push((Node){v, dis[v]});
        }
      }
    }
    for (int j = 1; j <= n; j++) q[j].push(dis[j]);
  }
}
int main(int argc, const char **argv) {
  cin >> n >> m >> s >> k;
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  work();
  for (int i = 1; i <= n; i++) {
    long long ans = 0;
    for (int j = 1; j <= k; j++) {
      ans += q[i].top();
      q[i].pop();
    }
    printf("%I64d ", ans);
  }
  return 0;
}
