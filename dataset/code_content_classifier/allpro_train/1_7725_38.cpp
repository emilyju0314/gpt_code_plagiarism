#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
const ll INF = 9e18;
const int M = 501;
int mat[M][M];
int x[M], y[M];
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) mat[i][j] = 0, x[i] = 0, y[i] = 0;
  }
  for (int i = 1; i <= n && m; ++i) {
    mat[i][i] = 1;
    --m;
  }
  int pos1 = n, pos2 = 2;
  while (m) {
    int x = pos2;
    for (int i = 1; i <= n && x <= n && m; ++i) {
      mat[i][x] = 1;
      ++x;
      --m;
    }
    pos2++;
    x = pos1;
    for (int i = 1; i <= n && x <= n && m; ++i) {
      mat[x][i] = 1;
      ++x;
      --m;
    }
    pos1--;
  }
  for (int i = 1; i <= n; ++i) {
    int cnt = 0;
    for (int j = 1; j <= n; ++j) cnt += mat[i][j];
    x[i] = cnt;
  }
  for (int i = 1; i <= n; ++i) {
    int cnt = 0;
    for (int j = 1; j <= n; ++j) cnt += mat[j][i];
    y[i] = cnt;
  }
  int mxx = 0, mnx = MOD, mxy = 0, mny = MOD;
  for (int i = 1; i <= n; ++i) {
    mxx = max(mxx, x[i]);
    mnx = min(mnx, x[i]);
    mxy = max(mxy, y[i]);
    mny = min(mny, y[i]);
  }
  cout << (mxx - mnx) * (mxx - mnx) + (mxy - mny) * (mxy - mny) << '\n';
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << mat[i][j];
    }
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
