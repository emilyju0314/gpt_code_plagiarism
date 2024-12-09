#include <bits/stdc++.h>
using namespace std;
const int BIG = 1e5 + 9;
const int INF = 1e9 + 9;
const long long BINF = 1e18 + 9;
const double SML = (1e-7);
int n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  if (n % 2 == 0) {
    for (int i = 1; i <= n; i++) {
      if (i % 2 != 0) {
        cout << i + 1 << ' ';
      } else {
        cout << i - 1 << ' ';
      }
    }
  } else {
    cout << 1 << ' ';
    for (int i = 2; i <= n; i++) {
      if (i % 2 == 0) {
        cout << i + 1 << ' ';
      } else {
        cout << i - 1 << ' ';
      }
    }
  }
  return 0;
}
