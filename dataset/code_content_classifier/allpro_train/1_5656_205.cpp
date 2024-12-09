#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const long long int mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
void cp() {
  int s, a, b, c;
  cin >> s >> a >> b >> c;
  double x, y, z;
  if (a == 0 && b == 0 && c == 0)
    x = y = z = 0;
  else {
    double sum = a + b + c;
    x = a * s / sum;
    y = b * s / sum;
    z = c * s / sum;
  }
  cout << setprecision(10) << fixed;
  ;
  cout << x << " " << y << " " << z << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  t = 1;
  while (t--) {
    cp();
  }
  return 0;
}
