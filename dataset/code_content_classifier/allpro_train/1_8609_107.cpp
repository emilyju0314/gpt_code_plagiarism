#include <bits/stdc++.h>
using namespace std;
set<int> s;
int main() {
  int n, v;
  cin >> n >> v;
  for (int i = 0; i < n; i++) {
    int t, k, mn = INT_MAX;
    cin >> k;
    for (int j = 0; j < k; j++) {
      cin >> t;
      mn = min(mn, t);
    }
    if (v > mn) s.insert(i + 1);
  }
  cout << s.size() << endl;
  for (int x : s) cout << x << " ";
  return 0;
}
