#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
int n;
int p[55];
long long num, f[55];
int ed[55];
void rep(int v) {
  if (v == n + 1) return;
  if (!ed[v]) cout << v << " ";
  rep(v + 1);
  if (ed[v]) cout << v << " ";
}
int main(void) {
  cin >> n >> num;
  f[1] = 1;
  for (int i = 2; i <= n; ++i) {
    f[i] = f[i - 1] + f[i - 1];
  }
  deque<int> d;
  for (int i = 1; i < n; ++i) {
    if (num > f[n - i]) {
      num -= f[n - i];
      ed[i] = 1;
    } else
      ed[i] = 0;
  }
  rep(1);
  return 0;
}
