#include <bits/stdc++.h>
using namespace std;
using ll = long long;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  struct Bor {
    struct Node {
      int to[2];
      int sum;
      Node() : sum(0) { to[0] = to[1] = 0; }
    };
    vector<Node> nodes;
    int nodes_cnt;
    int new_node() {
      assert(nodes_cnt < max_nodes);
      return nodes_cnt++;
    }
    int max_nodes;
    const int maxlog;
    Bor(int maxlog, int max_nodes)
        : maxlog(maxlog),
          max_nodes(max_nodes),
          nodes(max_nodes),
          nodes_cnt(1) {}
    void add(int num) {
      int cur = 0;
      nodes[cur].sum++;
      for (int i = maxlog; i >= 0; --i) {
        bool v = num & (1 << i);
        if (!nodes[cur].to[v]) {
          nodes[cur].to[v] = new_node();
        }
        cur = nodes[cur].to[v];
        nodes[cur].sum++;
      }
    }
    int dfs(int v, int idx) {
      if (idx == 0) return 0;
      int lsz = nodes[v].to[0] ? nodes[nodes[v].to[0]].sum : 0;
      int rsz = nodes[v].to[1] ? nodes[nodes[v].to[1]].sum : 0;
      int lres =
          nodes[v].to[0] ? dfs(nodes[v].to[0], idx - 1) + max(0, rsz - 1) : 1e9;
      int rres =
          nodes[v].to[1] ? dfs(nodes[v].to[1], idx - 1) + max(0, lsz - 1) : 1e9;
      return min(lres, rres);
    }
    int solve() { return dfs(0, maxlog); }
  };
  int n;
  while (cin >> n) {
    Bor bor(30, 60 * n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      bor.add(a[i]);
    }
    cout << bor.solve() << "\n";
  }
}
