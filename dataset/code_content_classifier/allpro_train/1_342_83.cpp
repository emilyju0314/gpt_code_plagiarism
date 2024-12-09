#include <bits/stdc++.h>
using namespace std;
const long long linf = 4000000000000000000LL;
const long long inf = 1000000007;
const long double pi = 3.1415926535;
void pv(vector<int> a) {
  for (auto& x : a) cout << x << " ";
  cout << '\n';
}
void pv(vector<long long> a) {
  for (auto& x : a) cout << x << " ";
  cout << '\n';
}
void pv(vector<vector<int> > a) {
  for (int i = (0); i < (int(a.size())); ++i) {
    cout << i << '\n';
    pv(a[i]);
    cout << '\n';
  }
}
void pv(vector<vector<long long> > a) {
  for (int i = (0); i < (int(a.size())); ++i) {
    cout << i << '\n';
    pv(a[i]);
  }
  cout << '\n';
}
void pv(vector<string> a) {
  for (auto& x : a) cout << x << '\n';
  cout << '\n';
}
void setIO(string second) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (int(second.size())) {
    freopen((second + ".in").c_str(), "r", stdin);
    if (second != "test1") freopen((second + ".out").c_str(), "w", stdout);
  }
}
int n;
vector<long double> a;
vector<vector<int> > adj;
vector<int> parent;
void dfs(int i, int p) {
  parent[i] = p;
  for (auto& x : adj[i]) {
    if (x == p) continue;
    dfs(x, i);
  }
}
int main() {
  setIO("");
  cin >> n;
  a.resize(n);
  for (auto& x : a) cin >> x, x = 1 - x;
  adj.resize(n);
  for (int i = (0); i < (n - 1); ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  parent.resize(n);
  dfs(0, -1);
  vector<long double> b(n, 1);
  for (int i = (0); i < (n); ++i)
    for (auto& x : adj[i])
      if (x != parent[i]) b[i] -= a[x];
  long double ans = 0;
  for (int i = (0); i < (n); ++i) ans += a[i] * b[i];
  int testc;
  cin >> testc;
  while (testc--) {
    int i;
    long double x;
    cin >> i >> x;
    x = 1 - x;
    long double y = a[i];
    if (parent[i] != -1) {
      b[parent[i]] -= x - y;
      ans -= (x - y) * a[parent[i]];
    }
    ans += (x - y) * b[i];
    a[i] = x;
    cout << fixed << setprecision(20) << ans << '\n';
  }
}
