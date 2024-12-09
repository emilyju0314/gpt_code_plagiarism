#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
int main() {
  int n;
  cin >> n;
  long long k1 = 0, k2 = 0;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (t == 1) k1++;
    if (t == 2) k2++;
  }
  a[0] = 1;
  for (int i = 1; i <= k1; i++)
    a[i] = (a[i - 1] + a[i - 2] * (i - 1)) % 1000000007;
  long long ans = a[k1];
  for (int i = 1; i <= k2; i++) ans = ans * (k1 + i) % 1000000007;
  cout << ans;
  return 0;
}
