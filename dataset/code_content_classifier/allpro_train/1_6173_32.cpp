#include <bits/stdc++.h>
using namespace std;
const long long E = 1e9 + 7;
const int N = 2000 + 10;
int n, k;
long long b[N], dp[N], a[N];
long long pEm2(int A, int B) {
  if (B == 0) return 1;
  long long c = pEm2(A, B >> 1) % E;
  c *= c;
  c %= E;
  if (B % 2 == 0)
    return c;
  else
    return (c * A) % E;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (k == 0) {
    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    return 0;
  }
  dp[0] = 1;
  for (long long i = 1; i < n; i++) {
    dp[i] = (dp[i - 1] * (i + k - 1)) % E * pEm2(i, E - 2);
    dp[i] %= E;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      b[i] += (long long)(a[i - j] * dp[j]);
      b[i] %= E;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << b[i] << " ";
  }
  return 0;
}
