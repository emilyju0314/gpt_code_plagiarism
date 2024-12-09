#include <bits/stdc++.h>
long long z = 100000000000000;
long long gcd(long long a, long long b) {
  if (b > a) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long c = power(a, b / 2);
  if (b % 2 == 0)
    return ((c * c) % z);
  else
    return ((((c * c) % z) * a) % z);
}
long long inverse(long long a, long long n) { return power(a, n - 2); }
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  long long ans[n][m], arr[n][m], pre[n][m], f_maxi[n][m + 2], b_maxi[n][m + 2];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  for (long long i = 0; i < n; i++) {
    pre[i][0] = arr[i][0];
    for (long long j = 1; j < m; j++) {
      pre[i][j] = (pre[i][j - 1] + arr[i][j]);
    }
  }
  for (long long i = 0; i < n; i++) {
    f_maxi[i][0] = -z;
    f_maxi[i][m + 1] = -z;
    b_maxi[i][0] = -z;
    b_maxi[i][m + 1] = -z;
  }
  for (long long j = 0; j < m; j++) {
    ans[0][j] = pre[0][j];
  }
  for (long long i = 1; i < n; i++) {
    for (long long j = 1; j <= m; j++) {
      f_maxi[i - 1][j] = max(f_maxi[i - 1][j - 1], ans[i - 1][j - 1]);
    }
    for (long long j = m; j > 0; j--) {
      b_maxi[i - 1][j] = max(b_maxi[i - 1][j + 1], ans[i - 1][j - 1]);
    }
    if (i % 2 == 0) {
      for (long long j = 0; j < m; j++)
        ans[i][j] = f_maxi[i - 1][j] + pre[i][j];
    } else {
      for (long long j = 0; j < m; j++) {
        ans[i][j] = b_maxi[i - 1][j + 2] + pre[i][j];
      }
    }
  }
  long long res = -100000000000000;
  for (long long j = 0; j < m; j++) res = max(res, ans[n - 1][j]);
  cout << res << endl;
  return 0;
}
