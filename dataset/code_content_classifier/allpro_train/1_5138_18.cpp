#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> g[maxn], tree[maxn];
vector<long long> BIT[maxn];
int n, q, u, v, o, x, d, t[maxn], sl, cnt = 0;
int depth[maxn], in[maxn], out[maxn], idt[maxn], sz[maxn];
long long BIT_D[maxn];
bool visited[maxn];
void bigUpdate(int d, long long val) {
  while (d <= maxn - 1) {
    BIT_D[d] += val;
    d += (d & -d);
  }
}
long long Sum(int id, int d) {
  long long ret = 0;
  while (d > 0) {
    ret += BIT[id][d];
    d -= (d & -d);
  }
  return ret;
}
void Update(int id, int d, long long val) {
  while (d <= sz[id]) {
    BIT[id][d] += val;
    d += (d & -d);
  }
}
long long bigSum(int d) {
  long long ret = 0;
  while (d > 0) {
    ret += BIT_D[d];
    d -= (d & -d);
  }
  return ret;
}
void dfs() {
  vector<int> dfs_stk, dep_stk, tree_id;
  dfs_stk.push_back(1);
  dep_stk.push_back(0);
  while (!dfs_stk.empty()) {
    int node = dfs_stk.back();
    dfs_stk.pop_back();
    int dosau = dep_stk.back();
    dep_stk.pop_back();
    depth[node] = dosau;
    visited[node] = true;
    if (node == 1) {
      sl = g[node].size();
      for (int i = 0; i < g[node].size(); ++i) {
        dfs_stk.push_back(g[node][i]);
        dep_stk.push_back(1);
        tree_id.push_back(i);
        visited[g[node][i]] = true;
      }
    } else {
      int tid = tree_id.back();
      tree_id.pop_back();
      idt[node] = tid;
      sz[tid] = dosau;
      for (int i = 0; i < g[node].size(); ++i) {
        if (!visited[g[node][i]]) {
          dfs_stk.push_back(g[node][i]);
          dep_stk.push_back(dosau + 1);
          tree_id.push_back(tid);
          visited[g[node][i]] = true;
        }
      }
    }
  }
}
void query0(int v, int x, int d) {
  if (v == 1) {
    bigUpdate(1, x);
    bigUpdate(d + 2, -x);
  } else {
    int it = idt[v];
    int l = depth[v] - d;
    int r = min(sz[it], depth[v] + d);
    if (depth[v] <= d) {
      bigUpdate(1, x);
      bigUpdate(d - depth[v] + 2, -x);
      l = d - depth[v] + 1;
    }
    Update(it, l, x);
    if (r < sz[it]) Update(it, r + 1, -x);
  }
}
void query1(int v) {
  long long res = 0;
  int it = idt[v];
  res += Sum(it, depth[v]);
  res += bigSum(depth[v] + 1);
  cout << res << '\n';
}
void solve() {
  for (int i = 0; i < sl; ++i) BIT[i].resize(sz[i] + 10);
  while (q--) {
    cin >> o;
    if (o == 0) {
      cin >> v >> x >> d;
      query0(v, x, d);
    } else {
      cin >> v;
      query1(v);
    }
  }
}
int main() {
  cin >> n >> q;
  for (int i = 0; i < n - 1; ++i) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs();
  solve();
  return 0;
}
