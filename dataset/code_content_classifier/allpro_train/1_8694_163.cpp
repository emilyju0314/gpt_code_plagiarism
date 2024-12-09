#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const double pi = acos(-1);
const double EPS = 1e-9;
long long binpowmod(long long a, long long b) {
  a %= MOD;
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ret % MOD;
}
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
const int N = 1 << 18;
const int E = N * 2;
bool good(long long n) {
  long long t = n;
  int sumofdigits = 0;
  while (n) {
    sumofdigits += n % 10;
    n /= 10;
  }
  return (gcd(t, sumofdigits) > 1);
}
int n, m, ans;
vector<vector<int> > a;
bool good(int i, int j) {
  for (int k = 0; k < m; ++k) {
    if (a[i][k] != a[j][k]) return false;
  }
  return true;
}
void solveit(int l = 0, int r = n - 1, int c = 1) {
  int len = r - l + 1;
  if (len % 2) return;
  int i = l, j = r;
  while (i < j) {
    if (!good(i, j)) return;
    i++;
    j--;
  }
  ans = min(ans, n / (1 << c));
  int mid = (l + r) / 2;
  solveit(l, mid, c + 1);
  solveit(mid + 1, r, c + 1);
}
void solve() {
  cin >> n >> m;
  ans = n;
  a.assign(n, vector<int>(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> a[i][j];
  solveit();
  cout << ans << '\n';
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  while (tc--) {
    solve();
  }
}
