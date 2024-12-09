#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  int h, m;
  while (test--) {
    cin >> h >> m;
    if (h == 0 && m == 0) {
      cout << "0" << endl;
      continue;
    }
    int ans = 24 * 60 - h * 60 - m;
    cout << ans << endl;
  }
  return 0;
}
