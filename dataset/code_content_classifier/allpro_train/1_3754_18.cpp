#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long lcm_tri(int a, int b, int c) {
  return lcm(lcm((long long)a, (long long)b), (long long)c);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = max(n - 100, 1); i <= n; i++) {
    for (int j = i; j <= n; j++) {
      for (int k = j; k <= n; k++) {
        ans = max(ans, lcm_tri(i, j, k));
      }
    }
  }
  cout << ans << endl;
  return 0;
}
