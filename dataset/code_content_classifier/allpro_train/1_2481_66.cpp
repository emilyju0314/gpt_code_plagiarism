#include <bits/stdc++.h>
using namespace std;
queue<pair<double, double> > sq;
vector<pair<double, double> > d;
int main() {
  int n, i;
  double p, m1, m2;
  scanf("%d%lf", &n, &p);
  for (i = 0; i < n; i++) {
    scanf("%lf%lf", &m1, &m2);
    d.push_back(make_pair(m2 / m1, m1));
  }
  sort(d.begin(), d.end());
  for (i = 0; i < n; i++) {
    sq.push(d[i]);
  }
  pair<double, double> sd;
  double k = p, now = 0, add;
  double time0 = 0, time1;
  while (!sq.empty()) {
    sd = sq.front();
    time1 = sd.first;
    add = sd.second;
    sq.pop();
    if (now + k * (time1 - time0) < 0) {
      printf("%f", now / (-k) + time0);
      return 0;
    }
    now = now + k * (time1 - time0);
    k -= add;
    time0 = time1;
  }
  if (k < 0 && abs(k) > 1e-8) {
    printf("%f", now / (-k) + time0);
    return 0;
  }
  printf("-1");
  return 0;
}
