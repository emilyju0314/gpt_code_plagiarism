#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n >= 0)
    cout << n << endl;
  else {
    n = abs(n);
    int r1 = n % 10;
    int m1 = (n - r1) / 10;
    int r2 = m1 % 10;
    int m2 = m1 - r2 + r1;
    int x = min(m1, m2);
    if (x == 0)
      cout << x << endl;
    else
      cout << "-" << x << endl;
  }
}
