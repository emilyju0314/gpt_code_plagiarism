#include <bits/stdc++.h>
const long long LL_INF = (long long)2e18 + 5;
using namespace std;
void solve() {
  long long n;
  cin >> n;
  bool ok = 1;
  map<long long, long long> m;
  for (long long i = (long long)(0); i < (long long)(n); i++) {
    long long a;
    cin >> a;
    if (m[(((a + i) % n) + n) % n]) ok = 0;
    m[(((a + i) % n) + n) % n]++;
  }
  ok ? cout << "YES\n" : cout << "NO\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tt;
  cin >> tt;
  while (tt--) solve();
}
