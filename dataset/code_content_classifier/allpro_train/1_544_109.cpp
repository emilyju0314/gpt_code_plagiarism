#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
vector<int> edge[maxn];
bool vis[maxn];
int pre[maxn], d[maxn];
int u, v, n, m, k, last, dep;
bool mark;
void dfs(int id, int cnt) {
  if (mark) return;
  for (int i = 0; i < edge[id].size(); i++) {
    if (mark) return;
    int x = edge[id][i];
    if (x == u && cnt >= k) {
      mark = true;
      dep = cnt + 1;
      last = id;
      return;
    }
    if (vis[x]) continue;
    vis[x] = true;
    pre[x] = id;
    dfs(x, cnt + 1);
    vis[x] = false;
  }
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    vis[i] = false;
    d[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
    d[u]++;
    d[v]++;
  }
  u = 1;
  for (int i = 2; i <= n; i++) {
    if (d[i] > d[u]) u = i;
  }
  vis[u] = true;
  mark = false;
  dfs(u, 0);
  printf("%d\n", dep);
  int i = last;
  for (; i != u; i = pre[i]) printf("%d ", i);
  printf("%d\n", u);
  return 0;
}
