#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"'; }
string to_string(char s) { return string(1, s); }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A>
string to_string(A);
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool f = 1;
  string r = "{";
  for (const auto& x : v) {
    if (!f) r += ", ";
    f = 0;
    r += to_string(x);
  }
  return r + "}";
}
void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug_out(T...);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    double C, T;
    cin >> C >> T;
    vector<pair<int, int>> a(n);
    int sum = 0;
    for (auto i = (0); i <= (n - 1); ++i)
      cin >> a[i].first >> a[i].second, sum += a[i].second;
    sort((a).begin(), (a).end()), reverse((a).begin(), (a).end());
    vector<double> p9(n + 1);
    p9[0] = 1;
    for (auto i = (1); i <= (n); ++i) p9[i] = p9[i - 1] / 0.9;
    vector<vector<double>> dp(n + 1, vector<double>(sum + 1 + 1, 1e18));
    dp[0][0] = 0;
    sum = 0;
    for (auto i = (1); i <= (n); ++i) {
      int w = a[i - 1].second, t = a[i - 1].first;
      sum += w;
      for (auto k = (i); k >= (1); --k) {
        for (auto s = (w); s <= (sum); ++s) {
          dp[k][s] = min(dp[k][s], dp[k - 1][s - w] + t * p9[k]);
        }
      }
    }
    int ans = 0;
    for (auto k = (1); k <= (n); ++k) {
      double t = T - k * 10;
      double s = max(0.0, (C * t - 1) / 2 / C);
      if (t >= 0 and s <= t) {
        double at = (t - s) * (1 + s * C);
        for (auto s = (0); s <= (sum); ++s)
          if (dp[k][s] <= at + 1e-6) {
            ans = max(ans, s);
          }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
