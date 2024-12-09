#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e18;
const long long N = 2e5 + 10;
void testCase() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long &i : a) cin >> i;
  long long ans = 0;
  for (long long i = 0; i < n;) {
    vector<long long> got;
    got.push_back(i++);
    while (i < n and a[i] != a[i - 1]) got.push_back(i++);
    ans = max(ans, ((long long)got.size() - 1) / 2);
    long long front = a[got[0]];
    long long back = a[got.back()];
    for (long long j = 1; j < (long long)got.size(); j++)
      a[got[j]] = j >= ((long long)got.size() + 1) / 2 ? back : front;
    if ((long long)got.size() > 2) a[got.back() - 1] = a[got.back()];
  }
  cout << ans << '\n';
  for (long long i : a) cout << i << ' ';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  long long t_c = 1;
  while (t_c--) testCase();
}
