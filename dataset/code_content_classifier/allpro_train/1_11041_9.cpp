#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
const int inf = 1e9;
long long int linf = 1000000ll * 10000 * 10000;
const int maxn = 3e5 + 20;
const int maxfn = 5e4 + 20;
int kmch = 15e4 + 5, V, n, m, psb;
vector<int> sat_adj[2][maxn], vec[maxn], cl, ans, comp;
vector<pair<pair<int, int>, pair<int, int> > > adj[maxfn], E;
stack<int> stk;
int bag[maxn], mark[maxn];
void pre_dfs(int v) {
  mark[v] = 1;
  for (int u : sat_adj[0][v]) {
    if (!mark[u]) {
      pre_dfs(u);
    }
  }
  stk.push(v);
}
void dfs(int v, int id) {
  mark[v] = 1;
  bag[v] = id;
  for (int u : sat_adj[1][v]) {
    if (!mark[u]) {
      dfs(u, id);
    }
  }
}
inline int var(int x) {
  if (x >= kmch) {
    x -= kmch;
  } else {
    x += kmch;
  }
  return x;
}
inline void make_condition(int v, int u) {
  sat_adj[0][var(u)].push_back(v);
  if (u != v) sat_adj[0][var(v)].push_back(u);
  sat_adj[1][v].push_back(var(u));
  if (u != v) sat_adj[1][u].push_back(var(v));
}
inline bool is_posbl() {
  memset(mark, 0, sizeof(mark));
  for (int i = 1; i <= V; i++) {
    if (!mark[i]) {
      pre_dfs(i);
    }
    if (!mark[var(i)]) {
      pre_dfs(var(i));
    }
  }
  memset(mark, 0, sizeof(mark));
  int cnt = 0;
  while (!stk.empty()) {
    int v = stk.top();
    stk.pop();
    if (!mark[v]) {
      dfs(v, cnt++);
    }
  }
  for (int i = 1; i <= V; i++) {
    if (bag[i] == bag[var(i)]) {
      return false;
    }
  }
  return true;
}
inline void set_condition(int x) {
  for (int i = 1; i <= V; i++) {
    sat_adj[0][i].clear();
    sat_adj[0][var(i)].clear();
    sat_adj[1][i].clear();
    sat_adj[1][var(i)].clear();
  }
  int ind = 0;
  for (auto P : E) {
    ind++;
    if (P.first.first > x) {
      make_condition(ind, ind);
    }
  }
  ind = 0;
  for (int i = 1; i <= n; i++) {
    bool is_first = 1;
    int j = 0;
    for (auto P : adj[i]) {
      ind++;
      int pos =
          lower_bound(comp.begin(), comp.end(), P.second.second) - comp.begin();
      vec[pos].push_back(P.first.second);
      cl.push_back(pos);
      if (j + 1 != adj[i].size()) {
        make_condition(m + ind + 1, P.first.second);
      }
      make_condition(P.first.second, var(m + ind));
      if (is_first) {
        is_first = 0;
        j++;
        continue;
      }
      make_condition(var(m + ind - 1), m + ind);
      j++;
    }
    sort(cl.begin(), cl.end());
    cl.resize(unique(cl.begin(), cl.end()) - cl.begin());
    for (int j : cl) {
      if (psb == -1) {
        vec[j].clear();
        continue;
      }
      if (vec[j].size() >= 3) {
        psb = -1;
      }
      if (vec[j].size() <= 1) {
        vec[j].clear();
        continue;
      }
      make_condition(var(vec[j][0]), var(vec[j][1]));
      vec[j].clear();
    }
    cl.clear();
    if (psb == -1) return;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  V = 3 * m;
  for (int i = 0; i < m; i++) {
    int u, v, c, t;
    cin >> u >> v >> c >> t;
    comp.push_back(c);
    E.push_back({{t, c}, {u, v}});
    adj[v].push_back({{u, i + 1}, {t, c}});
    adj[u].push_back({{v, i + 1}, {t, c}});
  }
  sort(comp.begin(), comp.end());
  comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
  int l = -1, r = mod;
  while (r - l > 1) {
    psb = 0;
    int mid = (l + r) >> 1;
    set_condition(mid);
    if (psb == -1) {
      l = mid;
      continue;
    }
    if (is_posbl()) {
      r = mid;
    } else {
      l = mid;
    }
  }
  if (r == mod) {
    cout << "No";
    return 0;
  }
  cout << "Yes\n";
  set_condition(r);
  is_posbl();
  for (int i = 1; i <= m; i++) {
    if (bag[i] < bag[var(i)]) {
      ans.push_back(i);
    }
  }
  cout << r << " " << ans.size() << "\n";
  for (int i : ans) {
    cout << i << " ";
  }
  return 0;
}
