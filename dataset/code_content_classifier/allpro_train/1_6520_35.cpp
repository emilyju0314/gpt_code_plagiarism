#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
long long int k, b, n, t;
bool check(long long int num) {
  if (k == 1) {
    double z = (1.0 * n * b + 1 - t) / (1.0 * b);
    if ((1.0 * num) >= z) return true;
    return false;
  }
  if (num >= n) return true;
  long long int z = n - num;
  long long int prev = (k - 1 + b);
  for (int i = 1; i <= z; i++) {
    prev = k * prev;
    if (prev > (t * k - t + b)) {
      return false;
    }
  }
  return true;
}
long long int fnd(long long int start, long long int end) {
  if (end >= start) {
    long long int mid = (end + start) >> 1;
    if (check(mid) and (((mid == start) or !check(mid - 1)))) return mid;
    if (check(mid)) return fnd(start, mid - 1);
    return fnd(mid + 1, end);
  }
}
void solve() {
  scanf("%lld", &k);
  scanf("%lld", &b);
  scanf("%lld", &n);
  scanf("%lld", &t);
  printf("%lld\n", fnd(0, n));
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
