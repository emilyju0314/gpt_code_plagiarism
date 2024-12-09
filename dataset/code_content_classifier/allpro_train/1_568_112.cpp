#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
const long long N = 1e5 + 5;
long long n, m, in[N], ou[N], x, y;
set<long long> adj[N];
vector<long long> adj1[N], cur;
bool vis[N];
void dfs(long long u) {
  vis[u] = 1;
  cur.push_back(u);
  for (long long v : adj1[u])
    if (!vis[v]) dfs(v);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) {
    cin >> x >> y;
    adj[y].insert(x);
    adj1[x].push_back(y);
    adj1[y].push_back(x);
    in[x]++;
    ou[y]++;
  }
  long long prev1 = 0;
  vector<long long> ans(n + 1);
  for (long long i = 1; i <= n; i++) {
    if (!vis[i]) {
      cur.clear();
      dfs(i);
      priority_queue<long long> pq;
      long long as = prev1 + (long long)cur.size();
      long long as1 = as;
      for (long long j = 0; j < (long long)cur.size(); j++) {
        if (!in[cur[j]]) pq.push(cur[j]);
      }
      while (!pq.empty()) {
        long long u = pq.top();
        pq.pop();
        ans[u] = as--;
        for (long long v : adj[u]) {
          in[v]--;
          if (in[v] == 0) pq.push(v);
        }
      }
      prev1 = as1;
    }
  }
  for (long long i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << "\n";
  return 0;
}
