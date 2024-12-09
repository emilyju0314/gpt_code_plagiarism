#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long A[200003], B[200003], C[200003];
long long count2, r, c;
string S[50001];
int main() {
  long long i, j, k, s, a, b, c, x, y, z, m, n, t, p, q, T, sum, ans, pos, val,
      count;
  scanf("%lld%lld%lld", &n, &k, &x);
  p = 1;
  for (i = 1; i <= k; i++) p *= x;
  B[0] = 0;
  for (i = 1; i <= n; i++) {
    scanf("%lld", &A[i]);
    B[i] = B[i - 1] | A[i];
  }
  C[n + 1] = 0;
  for (i = n; i >= 1; i--) {
    C[i] = C[i + 1] | A[i];
  }
  ans = 0;
  for (i = 1; i <= n; i++) {
    ans = max(ans, B[i - 1] | C[i + 1] | (A[i] * p));
  }
  printf("%lld\n", ans);
  return 0;
}
