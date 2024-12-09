#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 0, s = 0, x = 0;
  cin >> t >> s >> x;
  bool f = 0;
  if (x >= t && (x - t) % s == 0) {
    cout << "YES\n";
    return 0;
  } else if (x > t + 1 && (x - t - 1) % s == 0)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
