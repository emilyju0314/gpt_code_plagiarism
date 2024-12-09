#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, n, p, tc, ans = 0;
  set<int> se;
  set<int>::iterator it;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> k;
    se.insert(k);
  }
  ans = 1;
  n = *se.begin();
  for (it = se.begin(); it != se.end(); it++) {
    k = *it;
    if (k - n == 1) {
      ans++;
      if (ans == 3) {
        cout << "YES" << endl;
        return 0;
      }
    } else
      ans = 1;
    n = k;
  }
  cout << "NO" << endl;
  return 0;
}
