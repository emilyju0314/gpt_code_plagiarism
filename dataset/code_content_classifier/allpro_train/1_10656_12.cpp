#include <bits/stdc++.h>
using namespace std;
long long a[300005], ans;
vector<pair<long long, long long> > adj[300005];
vector<set<pair<long long, long long> > > st(300005);
void dfs(long long node, long long par) {
  st[node].insert(make_pair(0LL, 1000000007));
  st[node].insert(make_pair(0LL, 1000000007 + 1));
  for (auto i : adj[node])
    if (i.first != par) {
      dfs(i.first, node);
      long long num = a[i.first] - i.second;
      pair<long long, long long> m1 = (*(st[i.first].rbegin()));
      long long maxx = m1.first;
      st[node].insert(make_pair(max(0LL, num + maxx), i.first));
    }
}
void dfs1(long long node, long long par, long long dist_from_par) {
  long long temp = a[node];
  if (par != -1) {
    long long maxx_from_node =
        max(0LL, (*st[node].rbegin()).first + a[node] - dist_from_par);
    st[par].erase(make_pair(maxx_from_node, node));
    long long maxx1 = (*(st[par].rbegin())).first + a[par] - dist_from_par;
    maxx1 = max(maxx1, 0LL);
    st[node].insert(make_pair(maxx1, par));
    st[par].insert(make_pair(maxx_from_node, node));
  }
  pair<long long, long long> m1 = (*(st[node].rbegin()));
  st[node].erase(m1);
  pair<long long, long long> m2 = (*(st[node].rbegin()));
  temp += (m1.first + m2.first);
  st[node].insert(m1);
  ans = max(ans, temp);
  for (auto i : adj[node])
    if (i.first != par) {
      dfs1(i.first, node, i.second);
    }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) {
    int n, i, j, k;
    cin >> n;
    for (i = 1; i <= n; i++) cin >> a[i];
    for (i = 0; i < n - 1; i++) {
      long long x, y, wt;
      cin >> x >> y >> wt;
      adj[x].push_back(make_pair(y, wt));
      adj[y].push_back(make_pair(x, wt));
    }
    dfs(1, -1);
    dfs1(1, -1, -1);
    cout << ans;
  }
  return 0;
}
