#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> solution(long long a, long long b, long long n) {
  for (long long i = 0; i * a <= n; i++) {
    if ((n - (i * a)) % b == 0) {
      return {i, (n - (i * a)) / b};
    }
  }
  return {-1, -1};
}
const long long N = 1e6 + 100;
long long ar[N + 100];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, a, b;
  cin >> n >> a >> b;
  pair<long long, long long> getxy = solution(a, b, n);
  long long x = getxy.first;
  long long y = getxy.second;
  if (x == -1) {
    cout << -1;
    return 0;
  }
  long long pl = 1;
  long long cx = x;
  long long cy = y;
  while (x--) {
    for (long long i = 0; i < a; i++) {
      ar[pl + (i) % a] = pl + (i + 1) % a;
    }
    pl += a;
  }
  while (y--) {
    for (long long i = 0; i < b; i++) {
      ar[pl + (i) % b] = pl + (i + 1) % b;
    }
    pl += b;
  }
  for (long long i = 1; i <= n; i++) cout << ar[i] << " ";
  return 0;
}
