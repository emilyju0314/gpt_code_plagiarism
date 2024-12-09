#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
T randint(T a, T b) {
  return uniform_int_distribution<T>(a, b)(rng);
}
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
set<pair<int, int> > dp[100001];
int n, m;
int mx = 1000007;
void add(int a, int b, int w) {
  auto it = dp[a].lower_bound({w, -1});
  it--;
  int len = it->second + 1;
  pair<int, int> can = {w, it->second + 1};
  auto gr = prev(dp[b].upper_bound({w, mx}));
  auto last = dp[b].rbegin()->second;
  if (gr->second > len) return;
  dp[b].insert(can);
  gr = dp[b].upper_bound(can);
  while (gr != dp[b].end() && gr->second <= len) {
    dp[b].erase(gr);
    gr = dp[b].upper_bound(can);
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) dp[i].insert({-1, 0});
  for (int i = 1; i <= m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    add(a, b, w);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, dp[i].rbegin()->second);
  cout << ans;
  return 0;
}
