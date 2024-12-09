#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
void pre() {}
void solve() {}
int a[100009];
int l[1509], r[1509];
vector<pair<int, int> > v;
int n, s, m, k;
int dp[1509][1509];
int lt[1509], rt[1509];
vector<int> g[1509];
int mx[1509];
int chk(int x) {
  vector<int> q;
  for (int i = 0; i < (x); ++i) q.push_back(v[i].second), g[i].clear();
  sort(q.begin(), q.end());
  memset(dp, 0, sizeof(dp));
  memset(mx, -1, sizeof(mx));
  for (int i = 0; i < (s); ++i) {
    lt[i] = lower_bound(q.begin(), q.end(), l[i]) - q.begin();
    rt[i] = upper_bound(q.begin(), q.end(), r[i]) - q.begin();
    rt[i]--;
    for (int j = lt[i]; j <= (rt[i]); ++j) {
      if (mx[j] == -1)
        mx[j] = lt[i];
      else
        mx[j] = min(mx[j], lt[i]);
    }
  }
  for (int i = 1; i <= (k); ++i) dp[0][i] = 2000;
  for (int i = 1; i <= (x); ++i) {
    if (mx[i - 1] == -1) {
      for (int j = 0; j < (k + 1); ++j) dp[i][j] = dp[i - 1][j];
      continue;
    }
    int mn = mx[i - 1];
    int lg = min(i - mn, k);
    for (int j = 1; j <= (lg); ++j) {
      dp[i][j] = 1;
    }
    for (int j = lg + 1; j <= (k); ++j) {
      dp[i][j] = min(dp[i - 1][j], dp[mn][j - lg] + 1);
    }
  }
  return dp[x][k];
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  pre();
  cin >> n >> s >> m >> k;
  for (int i = 0; i < (n); ++i) cin >> a[i], v.push_back(make_pair(a[i], i));
  for (int i = 0; i < (s); ++i) {
    cin >> l[i] >> r[i];
    l[i]--, r[i]--;
  }
  sort(v.begin(), v.end());
  if (chk(n) > m) {
    cout << -1;
    exit(0);
  }
  int lo = k, hi = n;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (chk(mid) <= m) {
      hi = mid;
    } else
      lo = mid + 1;
  }
  cout << v[lo - 1].first;
  return 0;
}
