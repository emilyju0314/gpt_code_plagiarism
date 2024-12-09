#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, sum;
  cin >> m >> sum;
  if (sum == 0 && m > 1) {
    cout << "-1 -1" << endl;
    return 0;
  }
  if (sum > 9 * m) {
    cout << "-1 -1" << endl;
    return 0;
  }
  int s = sum;
  int res[m];
  s = s - 1;
  for (int i = m - 1; i > 0; i--) {
    if (s > 9) {
      res[i] = 9;
      s -= 9;
    } else {
      res[i] = s;
      s = 0;
    }
  }
  res[0] = s + 1;
  for (int i = 0; i < m; i++) cout << res[i];
  cout << " ";
  s = sum;
  for (int i = 0; i < m; i++) {
    if (s > 9) {
      res[i] = 9;
      s -= 9;
    } else {
      res[i] = s;
      s = 0;
    }
  }
  for (int i = 0; i < m; i++) cout << res[i];
  cout << endl;
  return 0;
}
