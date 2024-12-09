#include <bits/stdc++.h>
using namespace std;
const long long N = 1001;
long long x[N], y[N];
map<pair<long long, long long>, set<long long>> slope_map;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> x[i] >> y[i];
  long long total = 0, res = 0;
  for (long long i = 1; i <= n - 1; i++)
    for (long long j = i + 1; j <= n; j++) {
      long long x1 = x[i], y1 = y[i], x2 = x[j], y2 = y[j];
      long long a = y1 - y2, b = x1 - x2;
      long long d = gcd(a, b);
      a /= d;
      b /= d;
      if (a < 0 || (a == 0 && b < 0)) {
        a = -a;
        b = -b;
      }
      pair<long long, long long> slope(a, b);
      long long c = a * x1 - b * y1;
      if (!slope_map[slope].count(c)) {
        total++;
        slope_map[slope].insert(c);
        res += total - slope_map[slope].size();
      }
    }
  cout << res << endl;
}
