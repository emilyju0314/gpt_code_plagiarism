#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, p, j;
  cin >> n >> k >> p;
  string s;
  for (int i = 0; i < p; ++i) {
    cin >> j;
    bool charged = false;
    if (n % 2 == 1) {
      if (n - j == 0) {
        if (k > 0) {
          charged = true;
        }
      } else if ((n - j) % 2 == 1) {
        if (k > (n - (j - 1)) / 2) {
          charged = true;
        }
      } else {
        if (k - (n + 1) / 2 > (n - j) / 2 - 1) {
          charged = true;
        }
      }
    } else {
      if ((n - j) % 2 == 0) {
        if (k > (n - j) / 2) {
          charged = true;
        }
      } else {
        if (k - n / 2 > (n - (j + 1)) / 2) {
          charged = true;
        }
      }
    }
    s += (charged ? 'X' : '.');
  }
  cout << s << endl;
  return 0;
}
