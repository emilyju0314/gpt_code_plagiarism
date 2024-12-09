#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  size_t T;
  cin >> T;
  while (T--) {
    long long int n, l, r;
    cin >> n >> l >> r;
    long long int t = 1;
    long long int k = 1;
    while (k < l && t != n) {
      k += 2 * (n - t++);
    }
    if (k > l) {
      k -= 2 * (n - --t);
    }
    if (t == n) {
      cout << 1 << endl;
      continue;
    }
    long long int difference = l - k;
    long long int c = difference / 2 + t + 1;
    if (difference % 2) {
      cout << c << " ";
      ++l;
      difference = l - k;
      c = difference / 2 + t + 1;
      if (c > n) {
        c = ++t + 1;
        if (t == n) {
          cout << 1 << endl;
          break;
        }
      }
    }
    if (difference % 2 == 0) {
      long long int current = l;
      while (current <= r) {
        cout << t << " ";
        ++current;
        if (current <= r) {
          cout << c++ << " ";
          ++current;
          if (c > n) {
            c = ++t + 1;
            if (t == n) {
              if (current <= r) cout << 1;
              break;
            }
          }
        }
      }
    }
    cout << endl;
  }
}
