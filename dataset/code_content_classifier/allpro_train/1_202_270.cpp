#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, K;
  cin >> n >> K;
  vector<int> v(n, 0);
  for (int i = 0; i < n; ++i) cin >> v[i];
  int ans = -300 * 1000;
  for (int i = 0; i < n; ++i)
    for (int j = i; j < n; ++j) {
      vector<int> w;
      vector<int> w2(v.begin() + i, v.begin() + j + 1);
      for (int k = 0; k < n; ++k) {
        if (k >= i && k <= j) continue;
        w.push_back(v[k]);
      }
      sort(w.rbegin(), w.rend());
      if ((int)w.size() > K) w = vector<int>(w.begin(), w.begin() + K);
      for (auto tmp : w) w2.push_back(tmp);
      sort(w2.rbegin(), w2.rend());
      int tmp = 0;
      for (int k = 0; k < j - i + 1; ++k) tmp += w2[k];
      ans = max(ans, tmp);
    }
  cout << ans << "\n";
}
