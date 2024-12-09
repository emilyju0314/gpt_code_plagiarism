#include <bits/stdc++.h>
using namespace std;
long double x;
long long int T(int a, long double n) {
  if (a == 1)
    return 1;
  else
    return pow(a, n) - pow(a - 1, n);
}
int main() {
  long double n, m;
  cin >> m >> n;
  x = m;
  float an = 0;
  for (int i = 1; i <= m; i++) {
    an += i * (pow(i / m, n) - pow((i - 1) / m, n));
  }
  printf("%.10f", an);
  return 0;
}
