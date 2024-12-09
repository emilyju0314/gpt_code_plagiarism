#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
vector<int> g[300500];
map<int, ll> t[300500];
vector<ll> ans(300500), used(300500);
map<int, ll> s;
void dfs(int x, int d = 0, ll sum = 0) {
  used[x] = 1;
  for (auto i : t[x]) {
    s[d + i.first + 1] += i.second;
    sum += i.second;
  }
  sum -= s[d];
  ans[x] = sum;
  for (int i : g[x]) {
    if (!used[i]) {
      dfs(i, d + 1, sum);
    }
  }
  for (auto i : t[x]) {
    s[d + i.first + 1] -= i.second;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cout.precision(20);
  cout << fixed;
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    ll v, d, x;
    cin >> v >> d >> x;
    t[v][d] += x;
  }
  dfs(1);
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}
