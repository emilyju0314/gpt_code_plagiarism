#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MAX_N = 5e3 + 5;
struct edge {
  long long to;
  long long w;
  long long idx;
};
long long cidx;
long long vr1, vr2;
long long vw;
vector<edge> adj[MAX_N];
long long vis[MAX_N];
pair<long long, long long> dp[MAX_N];
long long n;
pair<long long, long long> dfs0(long long x, long long p) {
  long long cans = 0;
  long long ccnt = 1;
  for (auto e : adj[x]) {
    if (e.idx == cidx || e.to == p) continue;
    pair<long long, long long> ch = dfs0(e.to, x);
    cans += ch.first;
    cans += e.w * ch.second;
    ccnt += ch.second;
  }
  return make_pair(cans, ccnt);
}
pair<long long, long long> dfs1(long long x, long long d) {
  vis[x] = 1;
  long long cans = 0;
  long long ccnt = 1;
  for (auto e : adj[x]) {
    if (e.idx == cidx || vis[e.to]) continue;
    pair<long long, long long> ch = dfs1(e.to, x);
    cans += ch.first;
    cans += e.w * ch.second;
    ccnt += ch.second;
  }
  return dp[x] = make_pair(cans, ccnt);
}
long long mn;
long long vv;
void dfs2(long long x, long long p, long long ud, long long ucnt) {
  long long acans = dp[x].first;
  long long tw = ud;
  long long tcnt = ucnt + 1;
  if (dp[x].first + ud < mn) {
    mn = dp[x].first + ud;
    vv = x;
  }
  for (auto e : adj[x]) {
    if (e.idx == cidx || e.to == p) {
      continue;
    }
    tcnt += dp[e.to].second;
    tw += dp[e.to].first + e.w * dp[e.to].second;
  }
  for (auto e : adj[x]) {
    if (e.idx == cidx || e.to == p) {
      continue;
    }
    long long ctcnt = tcnt - dp[e.to].second;
    long long ctw =
        dp[x].first + ud - dp[e.to].first - e.w * dp[e.to].second + ctcnt * e.w;
    dfs2(e.to, x, ctw, ctcnt);
  }
}
long long bidx;
pair<long long, long long> gans(long long x, long long p) {
  long long cans = 0;
  long long ccnt = 1;
  for (auto e : adj[x]) {
    if (e.to == p || e.idx == bidx) {
      continue;
    }
    pair<long long, long long> ch = gans(e.to, x);
    cans += ch.first;
    cans += ch.second * e.w;
    ccnt += ch.second;
  }
  return make_pair(cans, ccnt);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  long long u, v, w;
  vector<pair<pair<long long, long long>, long long>> edges;
  for (long long i = 1; i < n; i++) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w, i});
    adj[v].push_back({u, w, i});
    edges.push_back({{u, v}, w});
  }
  long long aidx = 1;
  long long va1 = 1, va2 = 2;
  long long mimp = -1;
  long long bw = 0;
  long long var1, var2;
  for (long long i = 1; i < n; i++) {
    cidx = i;
    vr1 = edges[i - 1].first.first;
    vr2 = edges[i - 1].first.second;
    vw = edges[i - 1].second;
    long long r1 = vr1;
    long long r2 = vr2;
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    dfs1(r1, 0);
    dfs1(r2, 0);
    auto res1 = dp[r1];
    auto res2 = dp[r2];
    long long pans = res1.second * (vw * res2.second + res2.first) +
                     res1.first * res2.second;
    mn = 1e18;
    dfs2(r1, -1, 0, 0);
    long long mn1 = mn;
    long long mnr1 = vv;
    mn = 1e18;
    dfs2(r2, -1, 0, 0);
    long long mn2 = mn;
    long long mnr2 = vv;
    long long nans = res1.second * (vw * res2.second + mn2) + mn1 * res2.second;
    long long imp = pans - nans;
    if (imp > mimp) {
      mimp = imp;
      va1 = vr1;
      va2 = vr2;
      var1 = mnr1;
      var2 = mnr2;
      bidx = cidx;
      bw = vw;
    }
  }
  adj[var1].push_back({var2, bw, n});
  adj[var2].push_back({var1, bw, n});
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    ans += gans(i, -1).first;
  }
  cout << ans / 2;
  return 0;
}
