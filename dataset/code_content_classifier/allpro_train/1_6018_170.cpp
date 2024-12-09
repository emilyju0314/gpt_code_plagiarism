#include <bits/stdc++.h>
const long double pie = 3.1415926535;
using namespace std;
long long fpow(long long n, long long p) {
  long long m = 1;
  while (p) {
    if (p % 2) m *= n;
    p >>= 1;
    n *= n;
  }
  return m;
}
bool br1, br2, br;
char ch, ch1, ch2;
long long n, k, x, y, z, mini, maxi, l, ind, ini, sum, t, len, r, w, imini, m;
string s, s1, s2;
void solve() {
  cin >> n >> m;
  if (m % 2)
    cout << (m / 2 + 1) << endl;
  else
    cout << ((n - m) / 2 + 1) << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  solve();
  return 0;
}
