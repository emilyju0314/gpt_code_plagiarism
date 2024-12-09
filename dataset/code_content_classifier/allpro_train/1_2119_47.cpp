#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10010;
const double eps = 1e-8;
const double g = 9.8;
vector<pair<double, int> > alpha;
vector<pair<double, double> > wall;
pair<double, double> ans[MAXN];
int main() {
  int n, m;
  double speed;
  scanf("%d%lf", &n, &speed);
  for (int i = 0; i < n; i++) {
    double x;
    scanf("%lf", &x);
    alpha.push_back(make_pair(x, i));
  }
  sort(alpha.begin(), alpha.end());
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    double x, y;
    scanf("%lf%lf", &x, &y);
    wall.push_back(make_pair(x, y));
  }
  sort(wall.begin(), wall.end());
  int now = 0;
  for (int i = 0; i < n; i++) {
    double sina = sin(alpha[i].first), cosa = cos(alpha[i].first);
    double x = 2 * speed * speed * sina * cosa / g;
    while (now < m) {
      double t = wall[now].first / speed / cosa;
      double y = speed * sina * t - g * t * t / 2;
      if (y < eps) {
        ans[alpha[i].second] = make_pair(x, 0.0);
        break;
      }
      if (y < wall[now].second + eps) {
        ans[alpha[i].second] = make_pair(wall[now].first, y);
        break;
      }
      now++;
    }
    if (now == m) {
      ans[alpha[i].second] = make_pair(x, 0.0);
    }
  }
  for (int i = 0; i < n; i++)
    printf("%.9lf %.9lf\n", ans[i].first, ans[i].second);
  return 0;
}
