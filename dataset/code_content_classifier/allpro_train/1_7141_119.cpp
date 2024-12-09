#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
vector<int> a[N], b[N];
vector<pair<int, int> > e;
bool mark[N];
int p[N];
bool flag = false;
int eid[N];
vector<int> cover[N];
vector<int> vec[3];
int h[N];
int edge(int id, int v) {
  return (e[id].first == v) ? e[id].second : e[id].first;
}
void addedge(int u, int v) {
  b[u].push_back(v);
  b[v].push_back(u);
}
void check(int x) {
  for (int i = 0, u, v; i + 1 < cover[x].size(); i++) {
    addedge(cover[x][i], cover[x][i + 1]);
  }
  addedge(cover[x][0], cover[x].back());
}
void dfs(int v) {
  if (flag) return;
  mark[v] = true;
  int id = 0;
  for (int i = 0, u; i < a[v].size(); i++) {
    u = edge(a[v][i], v);
    if (!mark[u]) {
      h[u] = h[v] + 1;
      p[u] = a[v][i];
      dfs(u);
    } else if (u != edge(p[v], v) && h[u] < h[v]) {
      int x = v;
      if (flag) return;
      while (x != u) {
        if (eid[p[x]] != -1) {
          flag = true;
          id = eid[p[x]];
        }
        cover[a[v][i]].push_back(x);
        eid[p[x]] = a[v][i];
        x = edge(p[x], x);
      }
      cover[a[v][i]].push_back(u);
      if (flag) {
        check(a[v][i]);
        check(id);
        return;
      }
    }
  }
}
int s = -1, en;
void dfs2(int v, int id = -1) {
  if (id != -1) {
    vec[id].push_back(v + 1);
  }
  mark[v] = true;
  int k = 0;
  for (int i = 0, u; i < b[v].size(); i++) {
    u = b[v][i];
    if (!mark[u]) {
      if (id != -1)
        dfs2(u, id);
      else
        dfs2(u, k++);
    }
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(eid, -1, sizeof(eid));
  int n, m;
  cin >> n >> m;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    u--;
    v--;
    e.push_back(make_pair(u, v));
    a[u].push_back(i);
    a[v].push_back(i);
  }
  p[0] = -1;
  for (int i = 0; i < n; i++) {
    if (!mark[i]) dfs(i);
  }
  if (!flag) return cout << "NO\n", 0;
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    sort(b[i].begin(), b[i].end());
    b[i].resize(unique(b[i].begin(), b[i].end()) - b[i].begin());
    if (b[i].size() == 3) {
      if (s == -1)
        s = i;
      else
        en = i;
    }
  }
  memset(mark, 0, sizeof(mark));
  mark[en] = true;
  dfs2(s);
  for (int i = 0; i < 3; i++) {
    cout << vec[i].size() + 2 << " ";
    cout << s + 1 << " ";
    for (int j = 0; j < vec[i].size(); j++) cout << vec[i][j] << " ";
    cout << en + 1 << "\n";
  }
  return 0;
}
