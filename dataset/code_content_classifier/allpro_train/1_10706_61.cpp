#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 3;
long long n, m, k, h, t, a3, a4;
bool ok = true;
vector<long long> v, g1, g2, v1, v2;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long i, j, a, b, c, x, y, d, z;
  cin >> n;
  g1.resize(n);
  g2.resize(n);
  for (i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
  }
  x = 0;
  y = 0;
  for (i = n - 1; i >= 0; i--) {
    y += max(x + 1, v[i]) - v[i];
    g2[i] = y;
    x = max(x + 1, v[i]);
    v2.push_back(x);
  }
  reverse(v2.begin(), v2.end());
  x = 0;
  y = 0;
  for (i = 0; i < n; i++) {
    y += max(x + 1, v[i]) - v[i];
    g1[i] = y;
    x = max(x + 1, v[i]);
    v1.push_back(x);
  }
  x = min(g1[n - 1], g2[0]);
  for (i = 0; i < n - 1; i++) {
    c = 0;
    if (v1[i] <= v2[i + 1]) {
      c = v2[i + 1] - v1[i] + 1;
    }
    x = min(x, g1[i] + g2[i + 1] + c);
  }
  cout << x << "\n";
  return 0;
}
