#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int k = n / 7;
  if (k == 0 && n == 4)
    cout << 4 << endl;
  else if (k == 0)
    cout << -1 << endl;
  else {
    bool is = 1;
    int k4 = 0;
    int b = n % 7;
    if (b == 1) {
      k--;
      k4 += 2;
    } else if (b == 2) {
      if (k >= 2) {
        k -= 2;
        k4 += 4;
      } else {
        cout << -1 << endl;
        is = 0;
      }
    } else if (b == 3) {
      if (k >= 3) {
        k -= 3;
        k4 += 6;
      } else {
        cout << -1 << endl;
        is = 0;
      }
    } else if (b == 4) {
      k4++;
    } else if (b == 5) {
      k -= 1;
      k4 += 3;
    } else if (b == 6) {
      if (k >= 2) {
        k -= 2;
        k4 += 5;
      } else {
        is = 0;
        cout << -1 << endl;
      }
    }
    if (is) {
      for (int i = 0; i < k4; ++i) cout << 4;
      for (int i = 0; i < k; ++i) cout << 7;
      cout << endl;
    }
  }
}
