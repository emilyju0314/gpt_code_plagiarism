#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, u = 0;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      int p;
      cin >> p;
      if (p > k) a[i] = 2;
      if (p == k) {
        a[i] = 1;
        u = 1;
      }
      if (p < k) a[i] = 0;
    }
    if (u == 0) {
      cout << "No" << endl;
    } else if (n == 1) {
      cout << "Yes" << endl;
    } else {
      int w = 0;
      for (int i = 0; i < n - 1; i++) {
        if (a[i] != 0 && a[i + 1] != 0) {
          cout << "Yes" << endl;
          w = 1;
          break;
        }
        if (i < n - 2 && a[i] != 0 && a[i + 2] != 0) {
          cout << "Yes" << endl;
          w = 1;
          break;
        }
      }
      if (w == 0) {
        cout << "No" << endl;
      }
    }
  }
  return 0;
}
