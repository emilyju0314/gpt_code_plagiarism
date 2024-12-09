#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 1e9;
const int MAXN = 2e5 + 2;
const int oo = 1e9;
const long long oo15 = 1e15;
const long long oo18 = 1e18 + 3;
const long long oooo = 9223372036854775807;
void solve() {
  int n, dem1 = 0, dem0 = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x == 1)
      dem1++;
    else if (x == 0)
      dem0++;
  }
  long long res = 1;
  for (int i = 1; i <= dem0; i++) res *= 2;
  cout << dem1 * res << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int testcase = 1;
  cin >> testcase;
  while (testcase--) solve();
}
