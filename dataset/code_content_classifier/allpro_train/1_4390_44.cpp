#include <bits/stdc++.h>
using namespace std;
long long int powfi(long long int a, long long int b) {
  long long int c = 1LL;
  while (b > 0) {
    if (b % 2 == 1) c = ((c % 1000000007) * (a % 1000000007)) % 1000000007;
    a = ((a % 1000000007) * (a % 1000000007)) % 1000000007;
    b = b / 2;
  }
  return c;
}
long long int n, u;
long long int en[100005];
int c = 0;
int main() {
  int i, j, k;
  cin >> n >> u;
  long double ans = 0, dummy;
  for (i = 1; i <= n; i++) cin >> en[i];
  for (i = 1; i < n - 1; i++) {
    int ind = upper_bound(en + i + 1, en + n + 1, en[i] + u) - en;
    ind--;
    if (ind > i + 1) {
      c++;
      dummy = ((long double)((long double)(en[ind] - en[i + 1])) /
               ((long double)(en[ind] - en[i])));
      ans = max(ans, dummy);
    }
  }
  if (c == 0)
    cout << -1 << "\n";
  else
    printf("%.10LF", ans);
}
