#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[4];
  for (int i = 0; i < 4; i++) cin >> a[i];
  for (int m = 0; m < 16; m++) {
    int s = 0;
    for (int i = 0; i < 4; i++) s += (m & (1 << i) ? a[i] : -a[i]);
    if (!s) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
}
