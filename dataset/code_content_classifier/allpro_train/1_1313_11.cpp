#include <bits/stdc++.h>
using ll = long long int;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793238;
using namespace std;
long double n, r, R;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> r;
  R = r / (1 / (sin(PI / n)) - 1);
  cout << setprecision(8) << R;
  return 0;
}
