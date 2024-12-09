#include <bits/stdc++.h>
using namespace std;
char _;
bitset<32> bset1;
int i, j, k, a, b, d, f, g, h, l, m, n, p, q, r, s, t, u, v, w, x, y, z,
    maxx = INT_MIN, minn = INT_MAX, ans = 0, sum = 0, cnt = 0;
double c;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  x = ceil(sqrt(n));
  c = (double)n / x;
  cout << x + ceil(c) << endl;
  return 0;
}
