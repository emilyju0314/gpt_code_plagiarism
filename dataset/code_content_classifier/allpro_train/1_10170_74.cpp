#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, x, k, r, t, u;
  cin >> l >> x;
  bool done = false;
  vector<vector<int> > w;
  for (int i = 1; i <= 9 && !done; i++) {
    vector<int> v;
    k = i;
    r = 0;
    for (int j = 0; j < l; j++) {
      v.push_back(k);
      t = (k * x + r) / 10;
      u = (k * x + r) % 10;
      r = t;
      k = u;
    }
    if (r == 0 && k == i && v[v.size() - 1] != 0) {
      reverse(v.begin(), v.end());
      w.push_back(v);
      done = true;
    }
  }
  if (!done)
    cout << "Impossible";
  else {
    sort(w.begin(), w.end());
    for (int i = 0; i < w[0].size(); i++) cout << w[0][i];
  }
  return 0;
}
