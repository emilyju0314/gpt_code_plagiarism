#include <bits/stdc++.h>
using namespace std;
double p[100005];
double e[100005];
int main() {
  int n;
  cin >> n;
  double m = 0;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    if (i == 0)
      e[0] = p[0];
    else
      e[i] = p[i] * (e[i - 1] + 1);
    m += (2 * e[i - 1] + 1) * p[i];
  }
  printf("%.10lf\n", m);
  return 0;
}
