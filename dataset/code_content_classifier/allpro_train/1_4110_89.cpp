#include <bits/stdc++.h>
const int MAXN = 1e5 + 5, mod = 1e9 + 7;
using namespace std;
char str[MAXN], t[MAXN], tmp[2 * MAXN];
int lps[MAXN];
long long dp[MAXN], dp1[MAXN];
vector<int> kmp(const string& s) {
  int n = s.size();
  vector<int> res(n, 0);
  int k = 0;
  for (int i = 1; i < n; ++i) {
    while (k > 0 && s[k] != s[i]) {
      k = res[k - 1];
    }
    if (s[i] == s[k]) {
      ++k;
    }
    res[i] = k;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  vector<int> pi = kmp(t + '#' + s);
  int last = -1;
  vector<long long> sum(n, 0);
  if (t.size() == 1 && s[0] == t[0]) {
    dp[0] = 1;
    sum[0] = 1;
    last = 0;
  }
  for (int i = 1; i < n; ++i) {
    if (pi[i + m + 1] == m) {
      last = i;
    }
    dp[i] = (dp[i] + dp[i - 1]) % mod;
    if (last == -1) continue;
    if (last - m >= 0) dp[i] = (dp[i] + sum[last - m]) % mod;
    dp[i] = (dp[i] + last - m + 2) % mod;
    sum[i] = (sum[i - 1] + dp[i]) % mod;
  }
  printf("%I64d\n", dp[n - 1]);
  return 0;
}
