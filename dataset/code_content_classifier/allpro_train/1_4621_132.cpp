#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int n, lim, m;
int a[N], b[N], d[N], used[N], u[N];
int nxt[N][N];
vector<int> ver;
vector<int> nei[N];
vector<pair<pair<int, int>, int> > ans;
queue<int> q;
set<pair<int, int> > st;
void dfs(int x) {
  used[x] = 1;
  ver.push_back(x);
  for (int i = 0; i < nei[x].size(); i++) {
    int to = nei[x][i];
    if (!used[to]) dfs(to);
  }
}
void bfs(int x) {
  for (int i = 0; i < ver.size(); i++) u[ver[i]] = 0;
  u[x] = 1;
  while (!q.empty()) q.pop();
  q.push(x);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int i = 0; i < nei[now].size(); i++) {
      int to = nei[now][i];
      if (u[to] == 0) {
        nxt[x][to] = now;
        u[to] = 1;
        q.push(to);
      }
    }
  }
}
void update(int x) {
  if (d[x]) st.erase(make_pair(d[x], x));
  d[x] = b[x] - a[x];
  if (d[x]) st.insert(make_pair(d[x], x));
}
void flow(int x, int y, int f) {
  int z = nxt[x][y];
  if (x == y) return;
  if (a[z] >= f) {
    ans.push_back(make_pair(make_pair(z, y), f));
    a[z] -= f;
    a[y] += f;
    flow(x, z, f);
    update(y);
    update(z);
  } else {
    int tf = a[z];
    ans.push_back(make_pair(make_pair(z, y), tf));
    a[y] += tf;
    a[z] -= tf;
    flow(x, z, f - tf);
    ans.push_back(make_pair(make_pair(z, y), f - tf));
    a[y] += f - tf;
    a[z] -= f - tf;
    update(y);
    update(z);
  }
}
bool solve(int hd) {
  long long td = 0ll;
  ver.clear();
  st.clear();
  dfs(hd);
  for (int i = 0; i < ver.size(); i++) {
    int x = ver[i];
    td += 1ll * d[x];
    if (d[x]) st.insert(make_pair(d[x], x));
  }
  if (td != 0ll) return false;
  for (int i = 0; i < ver.size(); i++) bfs(ver[i]);
  while (!st.empty()) {
    int x = st.begin()->second;
    set<pair<int, int> >::iterator it = st.end();
    it--;
    int y = it->second;
    flow(x, y, min(a[x] - b[x], b[y] - a[y]));
  }
  return true;
}
int main() {
  scanf("%d%d%d", &n, &lim, &m);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) scanf("%d", b + i);
  for (int i = 1; i <= n; i++) d[i] = b[i] - a[i];
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    nei[x].push_back(y);
    nei[y].push_back(x);
  }
  for (int i = 1; i <= n; i++)
    if (!used[i])
      if (!solve(i)) {
        puts("NO");
        return 0;
      }
  printf("%d\n", int(ans.size()));
  for (int i = 0; i < ans.size(); i++)
    printf("%d %d %d\n", ans[i].first.first, ans[i].first.second,
           ans[i].second);
  return 0;
}
