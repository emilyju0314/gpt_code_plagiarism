#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> a >> b;
  if (n <= m || m == 1 || (a - 1) / m == (b - 1) / m)
    cout << 1;
  else {
    if (b == n || b % m == 0) {
      if (a % m == 1)
        cout << 1;
      else
        cout << 2;
    } else {
      if (a % m == 1)
        cout << 2;
      else if ((b - a + 1) % m == 0)
        cout << 2;
      else if ((b + m - 1) / m == (a + m - 1) / m + 1)
        cout << 2;
      else
        cout << 3;
    }
  }
  cout << endl;
  return 0;
}
