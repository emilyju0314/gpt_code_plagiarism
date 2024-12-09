#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
const long long INF = 1e18;
const int MAXPW = 62;
const double EPS = 1e-9;
vector<long long> perfect;
inline bool IsPerfect(long long n) {
  long long x = sqrt(n);
  return x * x < n;
}
void precalc() {
  for (long long i = 2; i <= 1000000; ++i) {
    for (long long temp = i * i; temp <= INF / i; temp *= i)
      if (IsPerfect(temp * i)) perfect.push_back(temp * i);
  }
  sort(perfect.begin(), perfect.end());
  perfect.resize(unique(perfect.begin(), perfect.end()) - perfect.begin());
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  precalc();
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long sq = sqrt(n);
    if (sq * sq > n) sq--;
    long long pf =
        upper_bound(perfect.begin(), perfect.end(), n) - perfect.begin();
    cout << n - sq - pf << '\n';
  }
  return 0;
}
