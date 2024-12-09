#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long double inf = 1e18;
const long long MOD = (long long)(1e9 + 7);
const double EPS = 1e-6;
void file_io(string inp = "input.txt", string out = "output.txt",
             bool debug = false) {
  freopen(inp.c_str(), "r", stdin);
  if (!debug) freopen(out.c_str(), "w", stdout);
}
void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long check(vector<vector<long long>> a) {
  long long sum = 0;
  long long n = a.size();
  long long m = a[0].size();
  for (long long i = 0; i < n; ++i) {
    for (long long j = 1; j < m; ++j)
      if (a[i][j] <= a[i][j - 1]) return -1;
  }
  for (long long i = 0; i < m; ++i) {
    for (long long j = 1; j < n; ++j)
      if (a[j][i] <= a[j - 1][i]) return -1;
  }
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < m; ++j) {
      if (a[i][j] <= 0)
        return -1;
      else
        sum += a[i][j];
    }
  }
  return sum;
}
int32_t main() {
  long long n, m;
  cin >> n >> m;
  vector<vector<long long>> a(n, vector<long long>(m, 0));
  for (long long i = 0; i < n; ++i)
    for (long long j = 0; j < m; ++j) cin >> a[i][j];
  for (long long i = n - 2; i >= 0; --i) {
    for (long long j = m - 2; j >= 0; --j) {
      if (a[i][j] != 0) continue;
      a[i][j] = min(a[i + 1][j] - 1, a[i][j + 1] - 1);
    }
  }
  cout << check(a) << "\n";
  return 0;
}
