#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e10 + 5;
long long countExcluded(vector<long long> &v, long long currDiv, int taken,
                        int index, long long x, long long p) {
  if (currDiv > MAXN) return 0;
  if (index == v.size()) {
    if (currDiv == 1) return 0;
    long long cnt = p / currDiv - x / currDiv;
    if (taken % 2 == 0) return -cnt;
    return cnt;
  }
  return countExcluded(v, currDiv, taken, index + 1, x, p) +
         countExcluded(v, currDiv * v[index], taken + 1, index + 1, x, p);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    long long x, p, k;
    long long l, r, mid;
    cin >> x >> p >> k;
    vector<long long> primeDivisors;
    for (int d = 2; d * d <= p; d++) {
      if (p % d == 0) {
        primeDivisors.push_back(d);
        while (p % d == 0) p /= d;
      }
    }
    if (p != 1) {
      primeDivisors.push_back(p);
    }
    l = x + 1;
    r = MAXN;
    while (l + 1 < r) {
      mid = (l + r) / 2;
      if (mid - x - countExcluded(primeDivisors, 1, 0, 0, x, mid) >= k)
        r = mid;
      else
        l = mid + 1;
    }
    if (l - x - countExcluded(primeDivisors, 1, 0, 0, x, l) >= k)
      cout << l << '\n';
    else
      cout << r << '\n';
  }
}
