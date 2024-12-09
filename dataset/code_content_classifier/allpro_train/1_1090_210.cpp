#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t = 1;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while (t--) {
    long long int n, q, m, b, x, y, start = 0, end = 0;
    cin >> n >> b >> m;
    start = b - n;
    if (m == 0) {
      if (n == b)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else {
      if (start % m == 0 && start / m >= 0)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
}
