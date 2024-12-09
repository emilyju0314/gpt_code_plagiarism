#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int mul(long long a, long long b) { return a * b % mod; }
using Matrix = vector<vector<int>>;
Matrix create(int n, int m) {
  return vector<vector<int>>(n, vector<int>(m, 0));
}
Matrix iden(int n) {
  Matrix res = create(n, n);
  for (int i = 0; i < n; i++) res[i][i] = 1;
  return res;
}
Matrix mul(Matrix &a, Matrix &b) {
  int n = a.size();
  Matrix res = create(n, n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++) {
        res[i][j] += mul(a[i][k], b[k][j]);
        if (res[i][j] >= mod) res[i][j] -= mod;
      }
  return res;
}
int main() {
  int n, k, m;
  cin >> n >> k >> m;
  int len = ((k + 1) << m) + 1;
  Matrix upd = create(len, len);
  for (int i = 0; i < k << m; i++) {
    int hm = i & ((1 << m) - 1);
    int hk = i >> m;
    int nm = ((hm << 1) + 1) & ((1 << m) - 1);
    upd[i][((hk + 1) << m) + nm] = 1 + __builtin_popcount(hm);
    nm &= ~1;
    upd[i][(hk << m) + nm] = 1;
  }
  for (int i = k << m; i < len; i++) upd[i][len - 1] = 1;
  Matrix res = iden(len);
  for (; n; n >>= 1, upd = mul(upd, upd))
    if (n & 1) res = mul(res, upd);
  int ans = 0;
  for (int i = k << m; i < len; i++) {
    ans += res[0][i];
    if (ans >= mod) ans -= mod;
  }
  cout << ans << endl;
  return 0;
}
