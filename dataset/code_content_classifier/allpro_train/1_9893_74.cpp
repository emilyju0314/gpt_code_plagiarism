#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
string base = "3 1 4 2 ";
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n < 4)
      cout << -1 << endl;
    else {
      for (int i = n - (n % 2); i > 4; i -= 2) cout << i << ' ';
      cout << base;
      for (int i = 5; i <= n; i += 2) cout << i << ' ';
      cout << endl;
    }
  }
}
