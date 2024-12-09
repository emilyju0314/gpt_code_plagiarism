#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
inline long long input() {
  long long n;
  cin >> n;
  return n;
}
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const long long INF = 8e18;
vector<int> adj[MAXN];
int ans[MAXN];
int res[MAXN];
vector<pair<int, int> > ET;
bool mark[MAXN];
int n;
void dfs(int v) {
  mark[v] = true;
  for (auto u : adj[v]) {
    if (!mark[u]) {
      ET.push_back({v, u});
      dfs(u);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  int tmp;
  int root = 0;
  for (int i = 1; i <= n; i++) {
    cin >> tmp;
    ans[i] = tmp;
    adj[i].push_back(ans[i]);
    adj[ans[i]].push_back(i);
    if (ans[i] == i) root = i;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (!mark[i]) dfs(i);
  }
  for (auto l : ET) {
    int a = l.first, b = l.second;
    if (a != ans[b]) swap(a, b);
    res[b] = a;
  }
  for (int i = 1; i <= n; i++) {
    if (!res[i] and !root) {
      root = i;
    }
    if (!res[i]) {
      res[i] = root;
    }
    if (res[i] != ans[i]) cnt++;
  }
  cout << cnt << "\n";
  for (int i = 1; i <= n; i++) {
    cout << res[i] << ' ';
  }
}
