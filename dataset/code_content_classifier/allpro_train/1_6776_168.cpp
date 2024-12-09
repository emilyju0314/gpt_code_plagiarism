#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int dr = k * l;
  int t = dr / nl;
  int li = c * d;
  int s = p / np;
  int mn = min(t, li);
  cout << min(mn, s) / n << endl;
  return 0;
}
