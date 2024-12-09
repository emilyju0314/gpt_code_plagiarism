#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
template <class T>
using vi2 = vector<vector<T>>;
using ll = long long;
using pii = pair<int, int>;
int main() {
  auto solve = [&]() {
    int n;
    cin >> n;
    vi2<int> a(n + 1, vector<int>(2));
    for (int i = 1, _i = int(n); i <= _i; i++) scanf("%1d", &a[i][0]);
    for (int i = 1, _i = int(n); i <= _i; i++) scanf("%1d", &a[i][1]);
    bool can = 1;
    for (int i = 2, _i = int(n); i <= _i; i++) {
      if (a[i][0] == a[i][1] && a[i][0] == 1) {
        cout << "NO" << endl;
        return;
      }
    }
    cout << "YES" << endl;
  };
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
