#include <bits/stdc++.h>
using namespace std;
void solve(std::istream &in, std::ostream &out);
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve(std::cin, std::cout);
  return 0;
}
void solve(std::istream &in, std::ostream &out) {
  int n, m;
  in >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    in >> u >> v;
    --u;
    --v;
    adj[u].push_back(v);
  }
  vector<int> dfn(n, -1);
  vector<int> low(n, -1);
  vector<int> scc(n, -1);
  vector<vector<int>> has;
  int dfn_cnt = 0;
  int scc_cnt = 0;
  stack<int> st;
  function<void(int)> tarjan = [&](int x) {
    dfn[x] = low[x] = dfn_cnt++;
    st.push(x);
    for (auto y : adj[x]) {
      if (dfn[y] == -1) {
        tarjan(y);
        low[x] = min(low[x], low[y]);
      } else if (scc[y] == -1) {
        low[x] = min(low[x], dfn[y]);
      }
    }
    if (dfn[x] == low[x]) {
      has.emplace_back();
      while (true) {
        int y = st.top();
        st.pop();
        scc[y] = scc_cnt;
        has[scc_cnt].push_back(y);
        if (y == x) {
          break;
        }
      }
      ++scc_cnt;
    }
  };
  for (int i = 0; i < n; ++i) {
    if (dfn[i] == -1) {
      tarjan(i);
    }
  }
  vector<vector<int>> graph(scc_cnt);
  vector<int> degree(scc_cnt);
  for (int x = 0; x < n; ++x) {
    for (auto y : adj[x]) {
      if (scc[x] != scc[y]) {
        graph[scc[x]].push_back(scc[y]);
        ++degree[scc[y]];
      }
    }
  }
  queue<int> q;
  int root = -1;
  for (int i = 0; i < scc_cnt; ++i) {
    if (!degree[i]) {
      if (root == -1) {
        root = i;
      } else {
        q.push(i);
      }
    }
  }
  while (!q.empty()) {
    int other = q.front();
    q.pop();
    while (!has[root].empty() && !has[other].empty()) {
      int from = has[root].back();
      int to = has[other].back();
      cout << "? " << from + 1 << " " << to + 1 << endl;
      int dir;
      cin >> dir;
      if (dir == 1) {
        has[other].pop_back();
      } else {
        has[root].pop_back();
      }
    }
    if (has[root].empty()) {
      swap(root, other);
    }
    for (auto another : graph[other]) {
      if (!--degree[another]) {
        q.push(another);
      }
    }
  }
  cout << "! " << has[root].back() + 1 << endl;
}
