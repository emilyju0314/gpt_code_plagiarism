#include <bits/stdc++.h>
using namespace std;
const long long MX = 2e5 + 100, INF = 1e18, INF2 = -1e18, D = 1e9 + 7;
long long n;
long long k1;
long long k2;
long long s[MX];
long long ss[MX];
long long maxx;
long long y;
long long q[MX];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  cin >> k1 >> k2;
  for (long long i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (long long i = 0; i < n; i++) {
    cin >> ss[i];
  }
  for (long long i = 0; i < n; i++) {
    q[i] = abs(ss[i] - s[i]);
  }
  long long sum = k1 + k2;
  for (long long i = 0; i < sum; i++) {
    maxx = 0;
    y = 0;
    for (long long j = 0; j < n; j++) {
      if (q[j] > maxx) {
        y = j;
        maxx = q[j];
      }
    }
    if (maxx == 0) {
      q[0]++;
    } else {
      q[y]--;
    }
  }
  long long sum2 = 0;
  for (long long i = 0; i < n; i++) {
    sum2 += q[i] * q[i];
  }
  cout << sum2;
  return 0;
}
