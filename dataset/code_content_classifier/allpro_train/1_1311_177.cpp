#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > sen;
int n, m, a;
double ans;
void dfs(int at, int left) {
  if (at == n) {
    double tot = 0;
    for (int i = 0; i < (1 << n); ++i) {
      double per = 1, b = 0;
      for (int j = 0; j < n; ++j) {
        if (i & (1 << j)) {
          per *= sen[j].second / 100.0;
        } else {
          per *= (100 - sen[j].second) / 100.0;
          b += sen[j].first;
        }
      }
      if (__builtin_popcount(i) > n / 2) {
        tot += per;
      } else {
        tot += per * (a * 1.0 / (a + b));
      }
    }
    ans = max(ans, tot);
    return;
  }
  for (int i = 0; i <= left && sen[at].second + 10 * i <= 100; ++i) {
    sen[at].second += i * 10;
    dfs(at + 1, left - i);
    sen[at].second -= i * 10;
  }
}
int main() {
  cin >> n >> m >> a;
  sen.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> sen[i].first >> sen[i].second;
  }
  ans = 0;
  dfs(0, m);
  printf("%.10f\n", ans);
}
