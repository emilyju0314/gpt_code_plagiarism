#include <bits/stdc++.h>
using namespace std;
int main() {
  long long l, r, k;
  while (cin >> l >> r >> k) {
    int c = 0;
    for (long long i = 1LL; i <= r; i *= k) {
      if (i >= l) {
        if (c) cout << " ";
        cout << i;
        c++;
      }
      if (i > r / k) break;
    }
    if (!c) {
      cout << "-1";
    }
    cout << "\n";
  }
  return 0;
}
