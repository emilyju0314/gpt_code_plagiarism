#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 0;
  cin >> t;
  while (t--) {
    int n = 0, x = 0;
    cin >> n;
    x = n;
    cout << "2\n";
    if (n > 2) {
      cout << x - 2 << " " << x << "\n";
      cout << x - 1 << " " << x - 1 << "\n";
      x--;
      for (int a = 0; a < n - 3; a++, x--) cout << x << " " << x - 2 << "\n";
    } else
      cout << "1 2\n";
  }
}
