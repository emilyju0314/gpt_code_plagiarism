#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using dd = long double;
namespace {
static bool constexpr dbg = 0;
ll constexpr N = 3.1e3;
ll n, dis[N];
vector<ll> adj[N];
ll vis[N];
bool root[N];
void init() {
  cin >> n;
  for (ll _ = 1; _ <= (ll)(n); ++_) {
    ll x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
}
vector<ll> v;
void dfs(ll c, ll p = -1) {
  vis[c] = 1;
  v.push_back(c);
  for (auto ch : adj[c])
    if (ch != p && vis[ch] != 2) {
      if (!vis[ch])
        dfs(ch, c);
      else {
        root[ch] = true;
        for (ll i = v.size() - 1; i >= 0 && v[i] != ch; --i) root[v[i]] = true;
      }
    }
  v.pop_back();
  vis[c] = 2;
}
void disdfs(ll c, ll d, ll p = -1) {
  dis[c] = d;
  for (auto ch : adj[c])
    if (ch != p && !root[ch]) disdfs(ch, d + 1, c);
}
void solve() {
  dfs(1);
  for (ll i = 1; i <= (ll)(n); ++i)
    if (root[i]) disdfs(i, 0);
  for (ll i = 1; i <= (ll)(n); ++i) cout << dis[i] << ' ';
}
void test() {
  if (dbg) {
  }
}
}  // namespace
int main() {
  if (!dbg) {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
  cout << fixed << setprecision(20);
  init();
  solve();
  test();
  return 0;
}
