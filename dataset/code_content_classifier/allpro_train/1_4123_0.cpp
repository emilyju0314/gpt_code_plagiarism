#include <bits/stdc++.h>
using namespace std;
int main() {
  string x, y, ans;
  cin >> x >> y;
  for (int i = 0; i < x.length(); i++) {
    if (x[i] < y[i]) {
      cout << -1 << endl;
      return 0;
    } else
      ans.push_back(y[i]);
  }
  cout << ans << endl;
  return 0;
}
