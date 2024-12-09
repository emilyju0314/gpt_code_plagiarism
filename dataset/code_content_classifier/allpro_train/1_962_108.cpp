#include <bits/stdc++.h>
using namespace std;
class Solver {
 public:
  void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    long long prev = 0LL;
    long long cur;
    for (int i = 0; i < n; ++i) {
      cin >> cur;
      if (prev < cur) {
        long long lmin = prev + 1LL;
        long long lmax = cur;
        long long rmin = cur;
        result += choices(lmin, lmax, rmin, n);
      } else if (prev > cur) {
        long long lmax = cur;
        long long rmin = cur;
        long long rmax = prev - 1LL;
        result += choices(1LL, lmax, rmin, rmax);
      }
      prev = cur;
    }
    std::cout << result << std::endl;
  }
  long long choices(long long lmin, long long lmax, long long rmin,
                    long long rmax) {
    if (lmax <= rmin) {
      return (lmax - lmin + 1LL) * (rmax - rmin + 1LL);
    }
    return (rmin - lmin + 1LL) * (rmax - rmin + 1LL) +
           (rmax - lmax + 1LL) * (lmax - lmin + 1LL) -
           (rmin - lmin + 1LL) * (rmax - rmax + 1LL) +
           (lmax - rmin) * (lmax - rmin + 1LL) / 2LL;
  }
  long long result = 0LL;
  long long n;
};
int main() {
  Solver sol;
  sol.solve();
  return 0;
}
