#include <bits/stdc++.h>
using namespace std;
long long MOD;
inline long long mod(long long x) { return x % MOD + (MOD * (x % MOD < 0)); }
long long cal(long long d, long long r, long long m) {
  long long k = (m - r) / d;
  if (m < r) return 0;
  return mod(mod(r) * mod(k + 1) + mod(d) * mod(mod(k) * mod(k + 1) / 2));
}
long long qry(long long k, long long m, long long d, long long r, long long l) {
  long long p = l / 2 + (l % 2);
  if (k == 0 or m == 0) return 0;
  if (l == 1) return mod((r + d * (r == 0)) * ((r + d * (r == 0)) <= m));
  if (k <= p) {
    return mod(qry(k, m, d * 2, r + d * (r == 0), p));
  } else {
    return mod(qry(k - p, m, d * 2, r + (d * (r != 0)), l - p) +
               cal(d * 2, r + d * (r == 0), m));
  }
}
int main() {
  long long n, m;
  long long i;
  long long a, b, c, d;
  cin >> n >> m >> MOD;
  for (i = 0; i < m; i++) {
    cin >> a >> b >> c >> d, d = min(d, n);
    if (c > n) {
      printf("0\n");
      continue;
    }
    cout << mod(mod(qry(b, d, 1, 0, n) - qry(b, c - 1, 1, 0, n)) -
                mod(qry(a - 1, d, 1, 0, n) - qry(a - 1, c - 1, 1, 0, n)))
         << endl;
  }
  return 0;
}
