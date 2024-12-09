#include <bits/stdc++.h>
using namespace std;
double u_distance(int, int, int, int);
bool eq(double, double);

int main() {
  int n;
  cin >> n;
  pair<double, double> maxpa(-1, -1); // distance, time
  pair<double, double> maxpb(-1, -1); // distance, time
  int f, lf, a, la, t, lt, x, lx, y, ly;
  for(int i = 0; i < n; ++i) {
    cin >> f >> a >> t >> x >> y;
    if(i > 0 && la != a && lt == t) {
      if(t && ((maxpb.first < u_distance(lx, x, ly, y)) || (eq(maxpb.first, u_distance(lx, x, ly, y)) && maxpb.second >= f - lf))) {
        maxpb.first = u_distance(lx, x, ly, y);
        maxpb.second = f - lf;
      } else if(!t && ((maxpa.first < u_distance(lx, x, ly, y)) || (eq(maxpa.first, u_distance(lx, x, ly, y)) && maxpa.second >= f - lf))) {
        maxpa.first = u_distance(lx, x, ly, y);
        maxpa.second = f - lf;
      }
    }
    lf = f; la = a; lt = t; lx = x; ly = y;
  }
  double maxpasecond = (maxpa.second == -1) ? -1.0 : (maxpa.second / 60.0);
  double maxpbsecond = (maxpb.second == -1) ? -1.0 : (maxpb.second / 60.0);
  // cout << maxpa.first << ' ' << maxpasecond << endl;
  // cout << maxpb.first << ' ' << maxpbsecond << endl;
  (eq(maxpa.first, -1)) ? printf("-1") : printf("%f", maxpa.first);
  printf(" ");
  (eq(maxpasecond, -1)) ? printf("-1") : printf("%f", maxpasecond);
  printf("\n");
  (eq(maxpb.first, -1)) ? printf("-1") : printf("%f", maxpb.first);
  printf(" ");
  (eq(maxpbsecond, -1)) ? printf("-1") : printf("%f", maxpbsecond);
  printf("\n");
  return 0;
}

double u_distance(int lx, int x, int ly, int y) {
  return sqrt(pow(x - lx, 2) + pow(y - ly, 2));
}

bool eq(double a, double b) {
  return abs(a - b) < 0.001;
}