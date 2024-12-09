#include <bits/stdc++.h>
using namespace std;
const double INF = 1e9 + 10;
const int MAXN = 1e3 + 10;
int n;
vector<pair<long long, long long> > coord;
double min(double a, double b) { return a < b ? a : b; }
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long xi, yi;
    cin >> xi >> yi;
    coord.push_back(make_pair(xi, yi));
  }
  coord.push_back(coord[0]);
  coord.push_back(coord[1]);
  double ans = INF;
  for (int i = 1; i <= n; i++) {
    long long A = coord[i - 1].second - coord[i + 1].second;
    long long B = coord[i + 1].first - coord[i - 1].first;
    long long C = coord[i - 1].first * coord[i + 1].second -
                  coord[i - 1].second * coord[i + 1].first;
    double cur = abs((double)A * coord[i].first + B * coord[i].second + C) /
                 (2 * sqrt((double)A * A + B * B));
    ans = min(ans, cur);
  }
  printf("%.8lf\n", ans);
  return 0;
}
