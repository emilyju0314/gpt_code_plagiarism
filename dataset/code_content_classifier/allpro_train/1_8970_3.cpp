#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long MAXN = 1001;
const long long INF = 1e18;
long long n, m;
bool check(long long x) { return x * (x + 1) / 2 >= n - m; }
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  if (m >= n) {
    cout << n;
    return 0;
  }
  long long ans = m;
  long long r = sqrt(2 * (n - m));
  if (!check(r)) r++;
  cout << ans + r;
  return 0;
}
