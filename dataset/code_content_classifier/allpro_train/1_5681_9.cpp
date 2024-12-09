#include <bits/stdc++.h>
using namespace std;
template <typename S, typename T>
ostream& operator<<(ostream& out, pair<S, T> const& p) {
  out << '(' << p.first << ", " << p.second << ')';
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> const& v) {
  long long l = v.size();
  for (long long i = 0; i < l - 1; i++) out << v[i] << ' ';
  if (l > 0) out << v[l - 1];
  return out;
}
template <typename T>
void trace(const char* name, T&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  trace(comma + 1, args...);
}
const int N = 1e5 + 100;
const int M = 350;
int sqt, n, q;
int arr[N];
int dp[M][N];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  sqt = int(sqrt(n));
  for (int k = 1; k <= sqt; k++) {
    for (int p = n; p >= 1; p--) {
      dp[k][p] = 1;
      if (p + arr[p] + k <= n) {
        dp[k][p] += dp[k][p + arr[p] + k];
      }
    }
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    int kk, pp;
    cin >> pp >> kk;
    if (kk <= sqt) {
      cout << dp[kk][pp] << "\n";
    } else {
      int ans = 0;
      for (int i = pp; i <= n;) {
        ans++;
        i = i + arr[i] + kk;
      }
      cout << ans << "\n";
    }
  }
}
