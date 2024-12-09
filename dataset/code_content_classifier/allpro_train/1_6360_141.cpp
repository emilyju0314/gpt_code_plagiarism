#include <bits/stdc++.h>
using namespace std;
int main() {
  double n, T;
  double c;
  cin >> n >> T >> c;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int m;
  cin >> m;
  vector<long long> sum_o(n);
  for (int i = 0; i < n; i++)
    if (i == 0)
      sum_o[i] = a[i];
    else
      sum_o[i] = sum_o[i - 1] + a[i];
  vector<int> p(m);
  for (int i = 0; i < m; i++) cin >> p[i];
  vector<double> real(m, 0), error(m), approx(m);
  int pref = 0;
  double mean = 0.0;
  for (int i = 0; i < m; i++) {
    real[i] = (sum_o[p[i] - 1]);
    if (p[i] - 1 - T >= 0) real[i] -= (sum_o[p[i] - 1 - T]);
    real[i] /= T;
    for (int j = pref; j < p[i]; j++) {
      mean = (mean + double(a[j] / T)) / c;
    }
    approx[i] = mean;
    pref = p[i];
  }
  for (int i = 0; i < m; i++)
    cout << fixed << setprecision(6) << real[i] << " " << approx[i] << " "
         << abs(real[i] - approx[i]) / real[i] << "\n";
  cout << flush;
  return 0;
}
