#include <bits/stdc++.h>
using namespace std;
void my_dbg() { cout << endl; }
template <typename Arg, typename... Args>
void my_dbg(Arg A, Args... B) {
  cout << ' ' << A;
  my_dbg(B...);
}
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
const int inf = INT_MAX;
const int ninf = INT_MIN;
const int mod = 1e9 + 7;
const int maxN = 1e2 + 2;
long double eps;
int n, k;
vi X(maxN), Y(maxN);
int X0, Y0;
long double dist(int x, int y) {
  return fabs(X0 - x) * fabs(X0 - x) + fabs(Y0 - y) * fabs(Y0 - y);
}
long double f(long double d, long double r) {
  long double pwr = 1.0 - (d / r) * (d / r);
  long double e = 2.7182818284590452353602874713527;
  return powl(e, pwr);
}
bool check(long double mid) {
  int cnt = 0;
  vector<long double> a;
  for (int i = (int)(0); i < (int)(n); i++) {
    long double rr = dist(X[i], Y[i]);
    long double r = sqrtl(rr);
    if (r > mid) {
      a.push_back(f(r, mid));
    } else {
      cnt++;
    }
  }
  if (cnt >= k) return 1;
  int req = k - cnt;
  int sz = (int)a.size();
  long double dp[sz + 1][sz + 1];
  for (int i = (int)(0); i < (int)(sz + 1); i++) {
    for (int j = (int)(0); j < (int)(sz + 1); j++) dp[i][j] = 0.0;
  }
  dp[0][0] = 1.0;
  for (int i = (int)(0); i < (int)(sz); i++) {
    for (int j = (int)(0); j < (int)(i + 1); j++) {
      dp[i + 1][j] += (1.0 - a[i]) * dp[i][j];
      dp[i + 1][j + 1] += a[i] * dp[i][j];
    }
  }
  long double p_here = 0.0;
  for (int i = (int)(req); i < (int)(sz + 1); i++) p_here += dp[sz][i];
  return p_here >= eps;
}
void solve() {
  scanf("%d", &n);
  scanf("%d", &k);
  long double eps_in_mils;
  scanf("%Lf", &eps_in_mils);
  eps_in_mils = 1000.0 - eps_in_mils;
  eps = (long double)eps_in_mils / 1000.0;
  scanf("%d", &X0);
  scanf("%d", &Y0);
  for (int i = (int)(0); i < (int)(n); i++) {
    scanf("%d", &X[i]);
    scanf("%d", &Y[i]);
  }
  long double lo = 0.0, hi = (long double)1e6, ans = 0.0;
  int iterations = 200;
  while (iterations--) {
    long double mid = (lo + hi) / 2.0;
    if (check(mid)) {
      ans = mid;
      hi = mid;
    } else {
      lo = mid;
    }
  }
  printf("%.8Lf", ans);
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
