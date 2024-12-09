#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int n, m, q;
int p, x, y, t, t_;
vector<long long> v;
vector<vector<long long> > a, b, bt;
int ii[5] = {0, 0, 0, 1, -1};
int jj[5] = {0, 1, -1, 0, 0};
void mult_Av(vector<vector<long long> >& a, vector<long long>& v);
void mult_AB(vector<vector<long long> >& a, vector<vector<long long> > b);
void mod_pow(vector<vector<long long> >& a, int n);
void fill();
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> q;
  fill();
  t_ = 1;
  for (int i = 0; i < q; ++i) {
    cin >> p >> x >> y >> t;
    --x;
    --y;
    t -= t_;
    t_ += t;
    bt.assign(b.begin(), b.end());
    mod_pow(bt, t);
    mult_Av(bt, v);
    if (p == 1) {
      cout << v[x * m + y] << endl;
    } else if (p == 2) {
      v[x * m + y] = 0;
      for (int j = 0; j < n * m; ++j) b[x * m + y][j] = 0;
    } else {
      for (int j = 0; j < n * m; ++j) b[x * m + y][j] = a[x * m + y][j];
    }
  }
  return 0;
}
void fill() {
  a.resize(n * m, vector<long long>(n * m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < 5; ++k) {
        int i_ = i + ii[k];
        int j_ = j + jj[k];
        if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m)
          a[i * m + j][i_ * m + j_] = 1;
      }
    }
  }
  b.assign(a.begin(), a.end());
  v.assign(n * m, 0);
  v[0] = 1;
}
void mult_Av(vector<vector<long long> >& a, vector<long long>& v) {
  vector<long long> w(v.begin(), v.end());
  for (int i = 0; i < m * n; ++i) {
    v[i] = 0;
    for (int j = 0; j < m * n; ++j) {
      v[i] += a[i][j] * w[j];
      v[i] %= mod;
    }
  }
}
void mult_AB(vector<vector<long long> >& a, vector<vector<long long> > b) {
  vector<vector<long long> > c(a.begin(), a.end());
  for (int i = 0; i < m * n; ++i) {
    for (int j = 0; j < m * n; ++j) {
      a[i][j] = 0;
      for (int k = 0; k < m * n; ++k) {
        a[i][j] += c[i][k] * b[k][j];
        a[i][j] %= mod;
      }
    }
  }
}
void mod_pow(vector<vector<long long> >& a, int n) {
  if (n == 1) return;
  if (n & 1) {
    vector<vector<long long> > b(a.begin(), a.end());
    mod_pow(a, n - 1);
    mult_AB(a, b);
  } else {
    mult_AB(a, a);
    mod_pow(a, n / 2);
  }
}
