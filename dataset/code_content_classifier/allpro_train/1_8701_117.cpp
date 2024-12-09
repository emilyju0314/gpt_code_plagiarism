#include <bits/stdc++.h>
const double PI = 3.141592653589793238463;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int64_t nCr(int64_t n, int64_t r) {
  int64_t tmp = n - r;
  for (int64_t i = n - 1; i > tmp; i--) n *= i;
  for (int64_t i = r - 1; i > 1; i--) r *= i;
  return n / r;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  ;
  ;
  int64_t p;
  cin >> p;
  vector<int64_t> v(p);
  for (auto &i : v) cin >> i;
  sort(v.begin(), v.end());
  int64_t ans = (1LL << 62);
  int64_t median = v.size() / 2;
  for (int64_t i = 0; i < median; i++) {
    ans = min(ans, v[i + median] - v[i]);
  }
  cout << ans;
  ;
  ;
  return 0;
}
