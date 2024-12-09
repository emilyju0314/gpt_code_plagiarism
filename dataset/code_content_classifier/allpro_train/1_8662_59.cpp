#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long n, a[100005], b[100005];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cerr.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i] >> b[i];
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  long long sum = 0;
  sum += n;
  for (long long i = 1; i <= n; i++) sum += max(a[i], b[i]);
  cout << sum << '\n';
}
