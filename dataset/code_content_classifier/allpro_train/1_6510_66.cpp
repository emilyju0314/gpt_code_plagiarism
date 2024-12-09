#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }
    if (n == 2) {
      cout << 2 << '\n';
      for (int i = 0; i < n; ++i) {
        cout << p[i] << ' ';
      }
      cout << '\n';
      continue;
    }
    vector<int> res;
    res.push_back(p[0]);
    for (int i = 0; i < n - 2; ++i) {
      if (p[i] < p[i + 1] && p[i + 1] < p[i + 2]) {
        continue;
      }
      if (p[i] > p[i + 1] && p[i + 1] > p[i + 2]) {
        continue;
      }
      res.push_back(p[i + 1]);
    }
    res.push_back(p[n - 1]);
    cout << res.size() << '\n';
    for (auto it : res) {
      cout << it << ' ';
    }
    cout << '\n';
  }
}
