#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = (1 << 20) + 5;
constexpr int MOD = 1e9 + 7;
constexpr long long MOD2 = 1e9 + 9;
constexpr double eps = 1e-6;
constexpr int INF = (1 << 30);
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
const int N = 1e5 + 9;
long long b[100050];
vector<long long> x[63];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    for (int j = 60; j >= 0; j--)
      if ((1LL << j) & b[i]) {
        x[j].push_back(b[i]);
        break;
      }
  }
  vector<long long> ans;
  for (int i = 60; i >= 0; i--) {
    vector<long long> res;
    if (x[i].empty()) continue;
    res.push_back(x[i].back());
    x[i].pop_back();
    for (long long foo : ans) {
      res.push_back(foo);
      if ((foo & (1LL << i)) && !x[i].empty()) {
        res.push_back(x[i].back());
        x[i].pop_back();
      }
    }
    if (!x[i].empty()) return cout << "No" << endl, 0;
    swap(ans, res);
  }
  cout << "Yes" << endl;
  for (auto foo : ans) cout << foo << ' ';
  cout << endl;
  return 0;
}
