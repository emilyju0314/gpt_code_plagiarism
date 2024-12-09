#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    set<int> s;
    for (int i = 1; i <= 2 * n; i++) s.insert(i);
    vector<int> b(2 * n);
    bool er = false;
    for (int i = 0; i < n; i++) {
      if (s.find(a[i]) == s.end()) {
        er = true;
        break;
      } else
        s.erase(a[i]);
      b[2 * i] = a[i];
    }
    for (int i = 0; i < n; i++) {
      auto it = s.upper_bound(a[i]);
      if (it == s.end()) {
        er = true;
        break;
      }
      b[2 * i + 1] = *it;
      s.erase(it);
    }
    if (er)
      cout << "-1\n";
    else {
      for (int i = 0; i < 2 * n; i++) cout << b[i] << " ";
      cout << "\n";
    }
  }
}
