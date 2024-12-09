#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  cin >> n;
  if (n <= 2)
    cout << -1 << endl;
  else if (n % 2 == 0) {
    long long x = (n / 2) * (n / 2) - 1;
    long long y = (n / 2) * (n / 2) + 1;
    cout << x << " " << y << endl;
  } else {
    long long x = (n * n) / 2;
    long long y = (n * n) / 2 + 1;
    cout << x << " " << y << endl;
  }
}
