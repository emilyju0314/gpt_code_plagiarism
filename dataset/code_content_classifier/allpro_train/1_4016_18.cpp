#include <bits/stdc++.h>
using namespace std;
int N;
double dx[110], dy[110];
double d[110];
bool func(void) {
  int i, j;
  for ((i) = 0; (i) < (int)(N); (i)++) d[i] = rand();
  double x = 0.0, y = 0.0;
  for (i = 2; i < N; i++) {
    x += dx[i] * d[i];
    y += dy[i] * d[i];
  }
  x = -x;
  y = -y;
  d[0] = (x * dy[1] - y * dx[1]) / (dy[1] * dx[0] - dx[1] * dy[0]);
  d[1] = (x * dy[0] - y * dx[0]) / (dx[1] * dy[0] - dy[1] * dx[0]);
  double dmax = d[0], dmin = d[0];
  for ((i) = 0; (i) < (int)(N); (i)++) {
    dmax = max(dmax, d[i]);
    dmin = min(dmin, d[i]);
  }
  for ((i) = 0; (i) < (int)(N); (i)++)
    d[i] = 1.5 + (d[i] - dmin) / (dmax - dmin) * 998.0;
  double mindiff = 1.0;
  for ((i) = 0; (i) < (int)(N); (i)++)
    for ((j) = 0; (j) < (int)(N); (j)++)
      if (i != j && d[i] < d[j]) mindiff = min(mindiff, d[j] - d[i]);
  return (mindiff > 0.002);
}
int main(void) {
  int i;
  cin >> N;
  if (N <= 4) {
    cout << "No solution" << endl;
    return 0;
  }
  for ((i) = 0; (i) < (int)(N); (i)++) {
    double theta = acos(-1.0) * 2.0 / N * i;
    dx[i] = cos(theta);
    dy[i] = sin(theta);
  }
  while (1)
    if (func()) break;
  double x = 0.0, y = 0.0;
  for ((i) = 0; (i) < (int)(N); (i)++) {
    printf("%.12f %.12f\n", x, y);
    x += dx[i] * d[i];
    y += dy[i] * d[i];
  }
  return 0;
}
