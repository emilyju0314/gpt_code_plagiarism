#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const long long N = 2010;
long long n;
long long k;
string s[N];
string ans;
long long dp[N][N];
long long path[N][N];
void solve() {
  cin >> n;
  cin >> k;
  for (long long i = 0; i < n; ++i) cin >> s[i];
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < n; ++j) {
      if (i == 0 && j == 0) {
        dp[i][j] += (s[i][j] != 'a');
        continue;
      }
      if (i == 0) {
        dp[i][j] = dp[i][j - 1];
        dp[i][j] += (s[i][j] != 'a');
        continue;
      }
      if (j == 0) {
        dp[i][j] = dp[i - 1][j];
        dp[i][j] += (s[i][j] != 'a');
        continue;
      }
      dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]) + (s[i][j] != 'a');
    }
  }
  if (k >= 2 * n - 1) {
    ans = string(2 * n - 1, 'a');
    cout << ans << '\n';
    return;
  }
  set<pair<long long, long long>> pool;
  long long len = -1;
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < n; ++j) {
      if (dp[i][j] <= k) {
        len = max(len, i + j);
      }
    }
  }
  if (len == -1) {
    ans.push_back(s[0][0]);
    len = 0;
    if (1 < n) {
      pool.insert({0, 1});
      pool.insert({1, 0});
    }
  } else {
    ans = string(len + 1, 'a');
    for (long long i = 0; i < n; ++i) {
      for (long long j = 0; j < n; ++j) {
        if (i + j == len && dp[i][j] <= k) {
          if (i + 1 < n) pool.insert({i + 1, j});
          if (j + 1 < n) pool.insert({i, j + 1});
        }
      }
    }
  }
  long long req = 2 * n - 1 - len - 1;
  ;
  while (req > 0) {
    char c = 'z';
    for (auto it : pool) {
      c = min(c, s[it.first][it.second]);
    }
    vector<pair<long long, long long>> toerase;
    for (auto it : pool) {
      if (c != s[it.first][it.second]) toerase.push_back(it);
    }
    for (auto it : toerase) pool.erase(it);
    vector<pair<long long, long long>> topush;
    for (auto [i, j] : pool) {
      if (i + 1 < n) topush.push_back({i + 1, j});
      if (j + 1 < n) topush.push_back({i, j + 1});
    }
    pool.clear();
    for (auto it : topush) pool.insert(it);
    req--;
    ans.push_back(c);
  }
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t = 1;
  while (t--) solve();
}
