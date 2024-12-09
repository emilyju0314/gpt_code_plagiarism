#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
void DEBUG(string label, T value) {
  cerr << "[" << label << " = " << value << "]\n";
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> vertical(n);
  for (int i = 0; i < n; ++i) {
    cin >> vertical[i];
  }
  vector<int> endpoints;
  for (int i = 0; i < m; ++i) {
    int x1, x2, y;
    cin >> x1 >> x2 >> y;
    if (x1 == 1) {
      endpoints.push_back(x2);
    }
  }
  sort(vertical.begin(), vertical.end());
  sort(endpoints.begin(), endpoints.end());
  int ans = 1 << 30;
  for (int i = 0; i < n; ++i) {
    int num = endpoints.end() -
              lower_bound(endpoints.begin(), endpoints.end(), vertical[i]);
    ans = min(ans, i + num);
  }
  int num = endpoints.end() -
            lower_bound(endpoints.begin(), endpoints.end(), (int)(1e9));
  ans = min(ans, n + num);
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
