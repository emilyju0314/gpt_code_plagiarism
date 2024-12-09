#include <bits/stdc++.h>
using namespace std;
const long long N = 1000006, M = 10004, INF = 1e18, MOD = 1e9 + 7;
int n, m, x, y, d, z, pa[N], w[N], a[N], inn[N], out[N], t, f[N], k, L[N], R[N],
    val, hl[N];
vector<pair<pair<int, int>, int> > v[N];
string s[4];
long double h, l;
int main() {
  cin >> h >> l;
  cout << setprecision(10)
       << (long double)(l * l - h * h) / (long double)(2 * h);
  return 0;
}
