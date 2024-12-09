#include <bits/stdc++.h>


using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

#define X real()
#define Y imag()

typedef long double D;
typedef complex<D> P;

const D PI = acos(-1);

int n;
P p[100];

D solve(D theta) {
  vector<D> xx;
  D st = sin(theta), ct = cos(theta);
  rep (i, n) xx.push_back(p[i].X * st + p[i].Y * ct);
  sort(xx.begin(), xx.end());
  D res = 2;
  rep (i, xx.size() - 1) res += min((D)2, xx[i + 1] - xx[i]);
  return res;
}

pair<D, D> solve2(D theta) {
  vector<pair<D, pair<D, D> > > xx;
  D st = sin(theta), ct = cos(theta);
  rep (i, n) xx.push_back(make_pair(p[i].X * st + p[i].Y * ct, make_pair(p[i].X, p[i].Y)));
  sort(xx.begin(), xx.end());
  D sx = 0, sy = 0;
  rep (i, xx.size() - 1) if (xx[i + 1].first - xx[i].first < 2) {
    sx += xx[i].second.first;
    sy += xx[i].second.second;
    sx -= xx[i + 1].second.first;
    sy -= xx[i + 1].second.second;
  }
  return make_pair(solve(atan2(sx, sy)), atan2(sx, sy));
}

int main() {
  while (true) {
    cin >> n;
    if (n == 0) break;
    rep (i, n) {
      D x, y;
      cin >> x >> y;
      p[i] = P(x, y);
    }
    vector<D> t;
    t.push_back(PI);
    t.push_back(0);
    rep (i, n) rep (j, i) {
      D t1 = -arg(p[i] - p[j]);
      D dt = asin((D)2 / abs(p[i] - p[j]));
      t.push_back(t1);
      t.push_back(t1 + dt);
      t.push_back(t1 - dt);
    }
    rep (i, t.size()) while (t[i] < 0) t[i] += PI;
    rep (i, t.size()) while (t[i] > PI) t[i] -= PI;
    sort(t.begin(), t.end());
    D ans = 1e9, theta = -1;
    rep (i, t.size()) {
      D s = solve(t[i]);
      if (s < ans) {
	ans = s;
	theta = t[i];
      }
    }
    rep (i, t.size() - 1) {
      pair<D, D> s = solve2((t[i] + t[i + 1]) / 2);
      if (s.first < ans) {
	ans = s.first;
	theta = s.second;
      }
    }
    while (theta < 0) theta += PI;
    while (theta > PI) theta -= PI;
    cout << fixed << setprecision(15) << theta << endl;
    ans = 0, theta = -1;
    rep (i, t.size()) {
      D s = solve(t[i]);
      if (s > ans) {
	ans = s;
	theta = t[i];
      }
    }
    rep (i, t.size() - 1) {
      pair<D, D> s = solve2((t[i] + t[i + 1]) / 2);
      if (s.first > ans) {
	ans = s.first;
	theta = s.second;
      }
    }
    while (theta < 0) theta += PI;
    while (theta > PI) theta -= PI;
    cout << fixed << setprecision(15) << theta << endl;
  }
}