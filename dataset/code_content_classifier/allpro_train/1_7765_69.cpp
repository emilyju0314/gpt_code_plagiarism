#include <bits/stdc++.h>
using namespace std;
int n, m;
long long ans, A[55], B[55];
int main() {
  int i, j, k;
  long long res;
  cin >> n >> m;
  for (i = 1; i <= n; i++) cin >> A[i];
  for (i = 1; i <= m; i++) cin >> B[i];
  ans = 2e18;
  ;
  for (i = 1; i <= n; i++) {
    res = -2e18;
    ;
    for (j = 1; j <= n; j++)
      if (i != j)
        for (k = 1; k <= m; k++) {
          long long sum = A[j] * B[k];
          res = max(res, sum);
        }
    ans = min(ans, res);
  }
  cout << ans;
  return 0;
}
