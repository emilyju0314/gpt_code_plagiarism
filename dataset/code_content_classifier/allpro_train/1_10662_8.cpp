#include <bits/stdc++.h>
#pragma optimize("O3")
using namespace std;
const long long MOD = 998244353;
const long long INF = 1e9 + 7;
const int base = 2e5 + 1;
const int MAX = 1e5 + 2;
const double EPS = 1e-9;
const double PI = acos(-1.);
const int MAXN = 5 * 1e5 + 47;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long a[4][100], c[4][100];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (long long i = (0); i < (n); ++i) {
      for (long long j = (0); j < (m); ++j) {
        scanf("%lld", &a[i][j]);
      }
    }
    long long res = 0;
    for (long long k = (0); k < (1000); ++k) {
      for (long long j = (0); j < (m); ++j) {
        int x = rand() % n;
        for (long long i = (0); i < (n); ++i) {
          c[i][j] = a[(i + x) % n][j];
        }
      }
      long long cur = 0;
      for (long long i = (0); i < (n); ++i) {
        long long mx = 0;
        for (long long j = (0); j < (m); ++j) {
          mx = max(mx, c[i][j]);
        }
        cur += mx;
      }
      res = max(res, cur);
    }
    printf("%lld\n", res);
  }
  return 0;
}
