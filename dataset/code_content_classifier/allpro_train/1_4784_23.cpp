/*
  In the name of ALLAH
  Author : Raashid Anwar
*/

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int M1 =  998244353;
const int M2 =  1000000007;
mt19937 rng((uint64_t)chrono::steady_clock::now().time_since_epoch().count());

vector <vector <int>> node(2e5);
vector <int> path;
int ans;
const int inf = 1e9;

int dfs(int u, int p) {
  int first = 0, second = 0, mn = inf;
  if ((int)node[u].size() == 1 && u)
    return 1;
  for (int v : node[u]) {
    if (v != p) {
      int x = dfs(v, u);
      mn = min(mn, x);
      second = max(second, x);
      if (first < second)
        swap(first, second);
    }
  }
  if (second) {
    if (!u) {
      ans = max(ans, max(first, second + 1));
    } else {
      ans = max(ans, first + 1);
    }
  }
  ans = max(ans, mn);
  return mn + 1;
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    node[i].clear();
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    node[u - 1].push_back(v - 1);
    node[v - 1].push_back(u - 1);
  }
  ans = 1;
  dfs(0, -1);
  cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
}