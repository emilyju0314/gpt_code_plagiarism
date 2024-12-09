#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e5 + 10;
long long a[maxn];
int main() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n, greater<long long>());
  long long ans = a[0] * n;
  long long lol = n;
  for (long long i = 1; i < n; i++) {
    ans += a[i] * (lol--);
  }
  cout << ans;
}
