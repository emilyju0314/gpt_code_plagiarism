#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  long long int a, b, c, d, e, x, y, p;
  a = (1 + m) / 5;
  b = (2 + m) / 5;
  c = (3 + m) / 5;
  d = (4 + m) / 5;
  e = m / 5;
  x = n / 5;
  p = x * (a + b + c + d + e);
  if (n % 5 == 0) cout << p;
  if (n % 5 == 1) cout << p + a;
  if (n % 5 == 2) cout << p + a + b;
  if (n % 5 == 3) cout << p + a + b + c;
  if (n % 5 == 4) cout << p + a + b + c + d;
}
