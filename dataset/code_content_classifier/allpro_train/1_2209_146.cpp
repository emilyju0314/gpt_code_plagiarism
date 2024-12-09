#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const long long LINF = LLONG_MAX;
const unsigned long long ULINF = ULLONG_MAX;
const double EPS = 0.000001;
int main() {
  int m, t, r;
  cin >> m >> t >> r;
  vector<int> w(m);
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    w[i] = x;
  }
  if (t < r) {
    cout << -1 << "\n";
    return 0;
  }
  vector<long long> ss(1000, 0);
  long long kol = 0;
  for (int i = 0; i < m; i++) {
    int del = r - ss[w[i] + 320];
    kol += r - ss[w[i] + 320];
    for (int j = 0; j < del; j++)
      for (int k = w[i] - j; k < w[i] + t - j; k++) ss[k + 320]++;
  }
  cout << kol << "\n";
  return 0;
}
