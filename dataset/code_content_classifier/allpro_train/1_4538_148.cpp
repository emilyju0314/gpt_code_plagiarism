#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    int hi = n / 2;
    cout << hi * hi << '\n';
    for (int i = n / 2 + 1; i <= n; i++) {
      for (int j = 1; j <= n / 2; j++) {
        cout << i << " " << j << '\n';
      }
    }
  } else {
    int hi = n / 2;
    cout << hi * (hi + 1) << '\n';
    ;
    for (int i = 1; i <= hi; i++) {
      for (int j = hi + 1; j <= n; j++) {
        cout << i << " " << j << '\n';
      }
    }
  }
  return 0;
}
