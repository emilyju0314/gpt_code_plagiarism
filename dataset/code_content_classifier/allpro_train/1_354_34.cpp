#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VL = vector<LL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
void dout() { cerr << endl; }
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
  cerr << H << ' ';
  dout(T...);
}
const int INF = 1e9 + 47;
void solve() {
  int n;
  cin >> n;
  VI a(n);
  for (int i = (0); i < (n); ++i) cin >> a[i];
  int mn = INF, mx = -1;
  for (int i = (0); i < (n); ++i) {
    if (a[i] == -1) {
      if (i > 0 && a[i - 1] != -1) {
        mn = min(mn, a[i - 1]);
        mx = max(mx, a[i - 1]);
      }
      if (i + 1 < n && a[i + 1] != -1) {
        mn = min(mn, a[i + 1]);
        mx = max(mx, a[i + 1]);
      }
    }
  }
  int k = (mx + mn) / 2;
  for (int i = (0); i < (n); ++i) {
    if (a[i] == -1) a[i] = k;
  }
  int res = 0;
  for (int i = (1); i < (n); ++i) {
    res = max(res, abs(a[i] - a[i - 1]));
  }
  cout << res << " " << k << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
