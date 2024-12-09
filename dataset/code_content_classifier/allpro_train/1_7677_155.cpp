#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  while (n--) {
    long long int m;
    cin >> m;
    if (m % 3 == 0 || m % 7 == 0)
      cout << "YES" << endl;
    else {
      long long int k = m / 3;
      if (k >= 4)
        cout << "YES" << endl;
      else {
        if (m <= 8 || m == 11) cout << "NO" << endl;
      }
      if (m == 10) cout << "YES" << endl;
    }
  }
  return 0;
}
