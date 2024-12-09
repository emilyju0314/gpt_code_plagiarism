#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a;
    cin >> a;
    if (a <= 30) {
      cout << "NO" << endl;
      continue;
    } else {
      cout << "YES" << endl;
      if ((a - 30) != 14 && (a - 30) != 10 && (a - 30) != 6) {
        cout << 14 << " " << 10 << " " << 6 << " " << a - 30 << endl;
      } else if ((a - 31) != 15 && (a - 31) != 10 && (a - 31) != 6) {
        cout << 15 << " " << 10 << " " << 6 << " " << a - 31 << endl;
      } else if ((a - 37) != 21 && (a - 37) != 10 && (a - 37) != 6) {
        cout << 21 << " " << 10 << " " << 6 << " " << a - 37 << endl;
      } else if ((a - 98) != 55 && (a - 98) != 10 && (a - 98) != 33) {
        cout << 55 << " " << 10 << " " << 33 << " " << a - 98 << endl;
      }
    }
  }
  return 0;
}
