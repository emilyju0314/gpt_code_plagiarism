#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 2;
const double X = 1e6;
double n, C;
double f[2][N];
double p[2][N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> C;
  C /= X;
  for (int i = int(0); i <= int(n); ++i) {
    cin >> p[0][i];
    p[0][i] /= X;
    f[0][i] = i;
  }
  int t = 0;
  for (int i = int(n - 1); i >= int(0); --i) {
    for (int j = int(0); j <= int(n); ++j) {
      p[t ^ 1][j] = (p[t][j + 1] * (j + 1) + p[t][j] * (i + 1 - j)) / (i + 1);
      double p1 = p[t][j + 1] * (j + 1) / (i + 1);
      double p2 = p[t][j] * (i + 1 - j) / (i + 1);
      if (p1 + p2 == 0) continue;
      double pr = p1 / (p1 + p2);
      f[t ^ 1][j] = max<double>(j, pr * f[t][j + 1] + (1 - pr) * f[t][j] - C);
    }
    t ^= 1;
  }
  cout << fixed << setprecision(12) << f[t][0] << endl;
}
