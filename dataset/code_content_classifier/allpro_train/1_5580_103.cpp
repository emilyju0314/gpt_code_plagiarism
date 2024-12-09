#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
void fast() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p);
}
long long int ncr(long long int n, long long int r, long long int p) {
  if (r == 0) return 1;
  long long int fac[n + 1];
  fac[0] = 1;
  for (long long int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
int main() {
  int m;
  cin >> m;
  int n;
  cin >> n;
  int paintingTime[m][n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) cin >> paintingTime[i][j];
  }
  vector<int> finishTime(m);
  for (int i = 0; i < n; i++) {
    int freeAt = 0;
    for (int j = 0; j < m; j++) {
      int start = max(freeAt, finishTime[j]);
      finishTime[j] = start + paintingTime[j][i];
      freeAt = finishTime[j];
    }
  }
  for (auto x : finishTime) cout << x << ' ';
}
