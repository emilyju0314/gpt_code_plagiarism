#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m, k;
    cin >> n >> m >> k;
    long long int c = n / k;
    if (m <= c)
      cout << m << '\n';
    else {
      long long int rem = m - c;
      if (rem % (k - 1) == 0) {
        cout << c - (rem / (k - 1)) << '\n';
      } else {
        cout << c - (rem / (k - 1)) - 1 << '\n';
      }
    }
  }
  return 0;
}
