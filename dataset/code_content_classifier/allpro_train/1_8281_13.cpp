#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[122][12];
long long q[12];
long long getp(long long p, long long q) {
  if (2ll * p > q) return 500;
  if (4ll * p > q) return 1000;
  if (8ll * p > q) return 1500;
  if (16ll * p > q) return 2000;
  if (32ll * p > q) return 2500;
  return 3000;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 5; ++j) {
      cin >> a[i][j];
      if (a[i][j] != -1) q[j]++;
    }
  }
  long long answ = -1;
  for (long long M = 0; M <= 50000; ++M) {
    long long Q[12], N;
    N = n + M;
    for (int i = 1; i <= 5; ++i) Q[i] = q[i];
    for (int i = 1; i <= 5; ++i) {
      if (a[1][i] != -1 && (a[1][i] > a[2][i] && a[2][i] != -1)) Q[i] += M;
    }
    long long s1 = 0, s2 = 0;
    for (int i = 1; i <= 5; ++i) {
      long long P = getp(Q[i], N);
      if (a[1][i] != -1) s1 += P - (P / 250) * a[1][i];
      if (a[2][i] != -1) s2 += P - (P / 250) * a[2][i];
    }
    if (s1 > s2) {
      answ = M;
      break;
    }
  }
  cout << answ << endl;
  return 0;
}
