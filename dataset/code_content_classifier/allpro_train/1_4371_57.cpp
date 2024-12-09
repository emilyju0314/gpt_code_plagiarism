#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<long long> > v(n, vector<long long>(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> v[i][j];
    }
  }
  vector<long long> a(n), b(m);
  a[0] = 0;
  for (int i = 0; i < m; ++i) {
    b[i] = v[0][i];
  }
  for (int i = 1; i < n; ++i) {
    a[i] = v[i][0] - b[0];
  }
  long long k = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      k = gcd(k, abs(a[i] + b[j] - v[i][j]));
    }
  }
  if (k == 0) {
    k = (long long)1e14;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (k <= v[i][j]) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  cout << k << endl;
  for (int i = 0; i < n; ++i) {
    cout << a[i] + k * 2 << ' ';
  }
  cout << endl;
  for (int i = 0; i < m; ++i) {
    cout << b[i] + k * 2 << ' ';
  }
}
