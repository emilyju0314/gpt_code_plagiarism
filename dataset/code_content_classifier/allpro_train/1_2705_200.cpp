#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long sum = 0, n, w;
    cin >> n >> w;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
      int k;
      cin >> k;
      if (k > w || sum >= (w + 1) / 2) continue;
      if (k >= (w + 1) / 2)
        v = {i}, sum = k;
      else
        sum += k, v.push_back(i);
    }
    if (sum >= (w + 1) / 2) {
      cout << v.size() << endl;
      for (auto& i : v) cout << i << " ";
      cout << endl;
    } else
      cout << -1 << endl;
  }
}
