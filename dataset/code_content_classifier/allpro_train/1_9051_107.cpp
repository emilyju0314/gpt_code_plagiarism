#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);
long long ans, n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  cout << n - (n / 2 + n / 3 + n / 5 + n / 7 -
               (n / 6 + n / 10 + n / 14 + n / 15 + n / 21 + n / 35) +
               (n / (2 * 3 * 5) + n / (2 * 5 * 7) + n / (3 * 5 * 7) +
                n / (2 * 3 * 7)) -
               (n / (2 * 3 * 5 * 7)));
}
