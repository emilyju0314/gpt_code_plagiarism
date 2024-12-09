#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> buk(30);
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      for (int j = 0; j < 30; j++) {
        if ((x >> j) & 1) {
          buk[j]++;
        }
      }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
      int ok = 1;
      for (int j = 0; j < 30; j++) {
        if (buk[j] % i) {
          ok = 0;
          break;
        }
      }
      if (ok) {
        cout << i << " ";
      }
    }
    cout << "\n";
  }
}
