#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      if (i % 2 == 0)
        cout << 0 << " ";
      else
        cout << ((long long)1 << (i + j)) << " ";
    }
    cout << endl;
  }
  long long q;
  cin >> q;
  for (long long c = 0; c < q; c++) {
    long long ans;
    cin >> ans;
    long long x = 0;
    long long y = 0;
    while (x + y != 2 * n - 2) {
      cout << x + 1 << " " << y + 1 << endl;
      if (ans & ((long long)1 << (x + 1 + y))) {
        if (x % 2 == 0) {
          x++;
          continue;
        } else {
          y++;
          continue;
        }
      } else {
        if (x % 2 == 0) {
          y++;
          continue;
        } else {
          x++;
          continue;
        }
      }
    }
    cout << n << " " << n << endl;
  }
}
