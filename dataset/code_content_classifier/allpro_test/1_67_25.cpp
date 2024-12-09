#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-14;
long double getpwin(long double total, long double good) {
  long double bad = total - good;
  long double sol = 0;
  if (good >= 3) {
    long double prob = 1;
    prob *= good / total;
    prob *= (good - 1) / (total - 1);
    prob *= (good - 2) / (total - 2);
    sol += prob;
  }
  if (good >= 2 && bad >= 1) {
    long double prob = 1;
    prob *= good / total;
    prob *= (good - 1) / (total - 1);
    prob *= bad / (total - 2);
    sol += prob * 3;
  }
  if (good >= 1 && bad >= 2) {
    long double prob = 1;
    prob *= good / total;
    prob *= bad / (total - 1);
    prob *= (bad - 1) / (total - 2);
    prob *= ((long double)1 / (long double)3 + (long double)1 / (long double)6);
    sol += prob * 3;
  }
  return sol;
}
long long n;
long double p;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> p;
  for (long long i = 0; i <= n; i++) {
    if (getpwin(n, i) - p >= -eps) {
      cout << i << "\n";
      return 0;
    }
  }
  return 0;
}
