#include <bits/stdc++.h>
using namespace std;
vector<long long> adj[200005];
vector<map<long long, long long>> dp(200005);
long long spf[200005];
long long arr[200005];
long long ans = 0;
void sieve() {
  spf[1] = 1;
  for (long long i = 2; i < 200005; i++) spf[i] = i;
  for (long long i = 4; i < 200005; i += 2) spf[i] = 2;
  for (long long i = 3; i * i < 200005; i++) {
    if (spf[i] == i) {
      for (long long j = i * i; j < 200005; j += i) {
        if (spf[j] == j) spf[j] = i;
      }
    }
  }
}
vector<long long> getFactorization(long long x) {
  vector<long long> ret;
  set<long long> s;
  while (x != 1) {
    s.insert(spf[x]);
    x = x / spf[x];
  }
  for (auto it = s.begin(); it != s.end(); ++it) ret.push_back(*it);
  return ret;
}
void DFS(long long s, long long p) {
  vector<long long> fac = getFactorization(arr[s]);
  for (long long i = 0; i < adj[s].size(); ++i) {
    long long c = adj[s][i];
    if (c != p) {
      DFS(c, s);
      for (long long j = 0; j < fac.size(); ++j) {
        ans = max(ans, dp[s][fac[j]] + dp[c][fac[j]]);
        dp[s][fac[j]] = max(dp[s][fac[j]], dp[c][fac[j]] + 1);
        ans = max(ans, dp[s][fac[j]]);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  sieve();
  long long N;
  cin >> N;
  for (long long i = 1; i <= N; ++i) {
    cin >> arr[i];
    vector<long long> fac = getFactorization(arr[i]);
    for (long long j = 0; j < fac.size(); ++j) {
      dp[i][fac[j]] = 1;
      ans = 1;
    }
  }
  for (long long i = 0; i < (N - 1); ++i) {
    long long u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  DFS(1, -1);
  cout << ans << endl;
}
