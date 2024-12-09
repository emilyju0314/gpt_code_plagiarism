#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const double eps = 1e-10;
const int maxn = 1e5 + 10;
struct node {
  long long x, y;
} p[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;
  if (n & 1) {
    cout << "NO" << endl;
    return 0;
  }
  bool f = 0;
  long long tx = (p[1].x + p[n / 2 + 1].x), ty = (p[1].y + p[n / 2 + 1].y);
  for (int i = 1; i <= n / 2; i++) {
    if ((p[i].x + p[n / 2 + i].x) == tx && (p[i].y + p[n / 2 + i].y) == ty)
      continue;
    f = 1;
  }
  if (f)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
