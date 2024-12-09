#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    int j = 0;
    while (n != 1) {
      if (n % 6 == 0) {
        n /= 6;
        j++;
      } else if (n % 3 == 0) {
        n *= 2;
        j++;
      } else
        break;
    }
    cout << (n == 1 ? j : -1) << "\n";
  }
  return 0;
}
