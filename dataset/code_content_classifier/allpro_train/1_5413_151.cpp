#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9, N = 100010, mod = 1e9 + 7;
const long long INFL = 1e18;
int n, b, a[N], k, x;
int cnt[101];
struct matrix {
  vector<vector<int> > M;
  vector<int>& operator[](int x) { return M[x]; };
  int size() { return (int)M.size(); };
  matrix(int n, int m) { M.assign(n + 1, vector<int>(m + 1, 0)); }
};
matrix operator*(matrix a, matrix b) {
  int m = a.size() - 1, n = a[0].size() - 1, p = b[0].size() - 1;
  matrix res = matrix(m, p);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= p; j++) {
      for (int k = 1; k <= n; k++)
        res[i][j] = (res[i][j] + (1LL * a[i][k] * b[k][j]) % mod) % mod;
    }
  return res;
}
matrix pw(matrix a, int n) {
  int m = a.size() - 1;
  matrix res = matrix(m, m);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= m; j++)
      if (i == j)
        res[i][j] = 1;
      else
        res[i][j] = 0;
  for (int i = 0; (1LL << i) <= n; i++) {
    if (n & (1LL << i)) res = res * a;
    a = a * a;
  }
  return res;
}
int Mod(int val) { return (val % x + x) % x; }
void debug(matrix a) {
  for (int i = 1; i < a.size(); i++) {
    for (int j = 1; j < a[0].size(); j++) cout << a[i][j] << ' ';
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> b >> k >> x;
  for (int i = 1; i <= n; i++) cin >> a[i], cnt[a[i] % x]++;
  if (b == 1) return cout << cnt[k] << "\n", 0;
  matrix G = matrix(x, x);
  matrix res = matrix(x, 1);
  for (int i = 0; i < x; i++) res[i + 1][1] = cnt[i];
  for (int i = 0; i < x; i++)
    for (int j = 0; j < x; j++) {
      int mod = ((i - 10 * j) % x + x) % x;
      G[i + 1][j + 1] = cnt[mod];
    }
  res = pw(G, b - 1) * res;
  cout << res[k + 1][1] << "\n";
}
