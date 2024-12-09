#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e+2 + 7;
const long long MOD = 1e+9 + 7, MOD1 = 998244353, INF = 0x7f7f7f7f7f7f7f7f;
const int INFi = 0x7f7f7f7f;
double EPS = 1e-9;
double PI = acos(-1);
vector<vector<long long> > transpose(const vector<vector<long long> > &m) {
  vector<vector<long long> > result(m.size(),
                                    vector<long long>(m[0].size(), 0));
  for (vector<long long>::size_type i(0); i < m.size(); ++i)
    for (vector<long long>::size_type j(0); j < m[0].size(); ++j)
      result[i][j] = m[j][i];
  return result;
}
long long p = 1, ans, n;
int main() {
  ios::sync_with_stdio(false);
  cout << fixed;
  cout.tie(nullptr);
  cin.tie(nullptr);
  cout << setprecision(0);
  ;
  cin >> n;
  for (long long i = 0; i < 3 * n; i += 1) {
    p = (p * 3) % MOD;
  }
  ans = p;
  p = 1;
  for (long long i = 0; i < n; i += 1) {
    p = (p * 7) % MOD;
  }
  ans = (ans - p) % MOD;
  if (ans < 0) ans += MOD;
  cout << ans;
}
