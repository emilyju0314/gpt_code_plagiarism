#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    if ((n % 2 != m % 2) || pow(m, 2) > n)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
