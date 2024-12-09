#include <bits/stdc++.h>
using namespace std;
int n, n_, k, q;
vector<int> a, b;
long long res;
vector<vector<int> > spt, ind;
void build_spt() {
  spt.assign(k, vector<int>(n, 0));
  ind.assign(k, vector<int>(n, 0));
  for (int j = 0; j < n; ++j) {
    spt[0][j] = b[j];
    ind[0][j] = j;
  }
  int m = 1;
  for (int i = 1; i < k; ++i) {
    m <<= 1;
    for (int j = 0; j < n - m + 1; ++j) {
      if (spt[i - 1][j] > spt[i - 1][j + m / 2]) {
        spt[i][j] = spt[i - 1][j];
        ind[i][j] = ind[i - 1][j];
      } else {
        spt[i][j] = spt[i - 1][j + m / 2];
        ind[i][j] = ind[i - 1][j + m / 2];
      }
    }
  }
}
void calc_n() {
  n = 1;
  k = 1;
  while (n < n_) {
    n <<= 1;
    ++k;
  }
}
void solve(int l, int r) {
  if (l == r) {
    res += (long long)b[l];
    return;
  }
  int len = r - l + 1;
  int k = 0;
  int m = 1;
  while (m + m < len) {
    m <<= 1;
    ++k;
  }
  long long mb;
  int in;
  if (spt[k][l] > spt[k][r - m + 1]) {
    mb = spt[k][l];
    in = ind[k][l];
  } else {
    mb = spt[k][r - m + 1];
    in = ind[k][r - m + 1];
  }
  res += (mb * ((r - in + 1ll) * 1ll * (in - l + 1ll)));
  if (in > l) solve(l, in - 1);
  if (in < r) solve(in + 1, r);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n_ >> q;
  calc_n();
  a.assign(n + 1, 0);
  for (int i = 0; i < n_; ++i) cin >> a[i];
  b.resize(n);
  for (int i = 0; i < n; ++i) b[i] = abs(a[i + 1] - a[i]);
  build_spt();
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    --l;
    --r;
    --r;
    res = 0;
    solve(l, r);
    cout << res << endl;
  }
  return 0;
}
