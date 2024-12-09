#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int a, b, c;
  cin >> a >> b >> c;
  for (int i = 0; i <= c / a; i++)
    if ((c - (i * a)) % b == 0) {
      cout << "YES" << endl;
      return 0;
    }
  cout << "NO" << endl;
  return 0;
}
