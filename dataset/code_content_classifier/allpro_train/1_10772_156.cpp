#include <bits/stdc++.h>
const long long inf = 0x3f3f3f3f3f3f3f3LL;
const long long mod = (long long)1e9 + 7;
using namespace std;
template <class T>
void smin(T& a, T val) {
  if (a > val) a = val;
}
template <class T>
void smax(T& a, T val) {
  if (a < val) a = val;
}
const long long N = 100 + 5;
long long dp[N][N][N][2];
vector<long long> prefix_function(string s) {
  long long n = (long long)s.length();
  vector<long long> pi(n);
  for (long long i = 1; i < n; i++) {
    long long j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
string s, t, pat;
vector<long long> pi;
long long solve(long long idx1, long long idx2, long long idx3,
                long long ongoing) {
  if (idx3 == (long long)(pat.size())) {
    return -inf;
  }
  if (idx1 == (long long)(s.size()) or idx2 == (long long)(t.size())) {
    return 0;
  }
  long long& ans = dp[idx1][idx2][idx3][ongoing];
  if (~ans) return ans;
  ans = 0;
  if (!ongoing) {
    smax(ans, solve(idx1 + 1, idx2, idx3, 0));
    smax(ans, solve(idx1, idx2 + 1, idx3, 0));
  }
  if (s[idx1] == t[idx2]) {
    if (s[idx1] == pat[idx3]) {
      smax(ans, 1 + solve(idx1 + 1, idx2 + 1, idx3 + 1, 0));
    } else {
      if (idx3 == 0) {
        smax(ans, 1 + solve(idx1 + 1, idx2 + 1, 0, 0));
      } else {
        smax(ans, solve(idx1, idx2, pi[idx3 - 1], 1));
      }
    }
  }
  return ans;
}
string vals = "";
void path(long long idx1, long long idx2, long long idx3, long long ongoing) {
  if (idx1 == (long long)(s.size()) or idx2 == (long long)(t.size())) {
    return;
  }
  long long ans = solve(idx1, idx2, idx3, ongoing);
  if (!ongoing) {
    if (ans == solve(idx1 + 1, idx2, idx3, 0)) {
      path(idx1 + 1, idx2, idx3, 0);
      return;
    } else if (ans == solve(idx1, idx2 + 1, idx3, 0)) {
      path(idx1, idx2 + 1, idx3, 0);
      return;
    }
  }
  if (s[idx1] == t[idx2]) {
    if (s[idx1] == pat[idx3]) {
      vals += s[idx1];
      path(idx1 + 1, idx2 + 1, idx3 + 1, 0);
    } else {
      if (idx3 == 0) {
        vals += s[idx1];
        path(idx1 + 1, idx2 + 1, 0, 0);
      } else {
        path(idx1, idx2, pi[idx3 - 1], 1);
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> s >> t >> pat;
  memset(dp, -1, sizeof dp);
  pi = prefix_function(pat);
  solve(0, 0, 0, 0);
  path(0, 0, 0, 0);
  if ((long long)(vals.size()) == 0) {
    cout << 0;
    exit(0);
  }
  cout << vals;
  return 0;
}
