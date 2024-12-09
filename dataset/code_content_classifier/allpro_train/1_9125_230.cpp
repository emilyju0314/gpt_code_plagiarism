#include <bits/stdc++.h>
using namespace std;
long long powm(long long a, long long b, long long M) {
  if (b == 0) return 1;
  if (b == 1) return a % M;
  if (b & 1) return (a * powm(a, b - 1, M)) % M;
  return powm((a * a) % M, b / 2, M) % M;
}
int main() {
  ios::sync_with_stdio(0);
  long long k, n, m;
  cin >> n >> m >> k;
  long long L = 0, R = n;
  while (L < R) {
    long long M = L + (R - L + 1) / 2;
    if (M * (k - 1) <= m && M <= n - m)
      L = M;
    else
      R = M - 1;
  }
  m -= R * (k - 1);
  long long ats = 0;
  long long T = m / k;
  m %= k;
  ats = ((powm(2, T + 1, 1000000009) - 2) * k) % 1000000009;
  if (ats < 0) ats = (ats + 1000000009) % 1000000009;
  cout << (ats + m + R * (k - 1)) % 1000000009 << "\n";
}
