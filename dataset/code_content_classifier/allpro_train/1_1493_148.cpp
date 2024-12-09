#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    if ((k % 2 == 0 && n % 2) || n < k) {
      cout << "NO" << endl;
      continue;
    }
    if (n % 2) {
      cout << "YES" << endl;
      cout << (n - (k - 1));
      for (long long i = 0; i < (k - 1); i++) cout << " " << '1';
    } else {
      if (k % 2) {
        if (n < (2 * k)) {
          cout << "NO";
        } else {
          cout << "YES" << endl;
          cout << (n - 2 * (k - 1));
          for (long long i = 1; i < k; i++) cout << " " << '2';
        }
      } else {
        cout << "YES" << endl;
        cout << (n - (k - 1));
        for (long long i = 1; i < k; i++) cout << " " << '1';
      }
    }
    cout << endl;
  }
  return 0;
}
