#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie();
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  int T, k;
  cin >> T >> k;
  ++k;
  while (T--) {
    int m, n;
    cin >> m >> n;
    if (m > n) swap(m, n);
    if (m % k == 0) {
      cout << "+";
    } else {
      int group = min(m / k, n / k);
      int del = m / k;
      int x = m - del * k;
      int y = n - del * k;
      bool win = group % 2;
      bool ans;
      if (k == 2) win = 0;
      if ((x + y) % 2 == 0)
        ans = win;
      else
        ans = !win;
      cout << (ans ? "+" : "-");
    }
    cout << '\n';
  }
  return 0;
}
