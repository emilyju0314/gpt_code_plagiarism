#include <bits/stdc++.h>
using namespace std;
int A, B;
bool d_ok(pair<int, int> a, pair<int, int> b) {
  long long q = (a.first - b.first) * (a.first - b.first) +
                (a.second - b.second) * (a.second - b.second);
  return (q <= A * A);
}
double d(pair<int, int> a, pair<int, int> b) {
  return sqrt(1.0 * (a.first - b.first) * (a.first - b.first) +
              1.0 * (a.second - b.second) * (a.second - b.second));
}
vector<pair<pair<int, int>, pair<int, int> > > R;
bool in(int x, int a, int b) {
  return ((x >= a && x <= b) || (x <= a && x >= b));
}
double dst_sgm(int i, int j) {
  if (R[i].first.first == R[i].second.first) {
    double res = d(R[i].first, R[j].first);
    res = min(res, d(R[i].first, R[j].second));
    res = min(res, d(R[i].second, R[j].first));
    res = min(res, d(R[i].second, R[j].second));
    if (R[j].first.first == R[j].second.first) {
      if (in(R[i].first.second, R[j].first.second, R[j].second.second) ||
          in(R[i].second.second, R[j].first.second, R[j].second.second))
        res = min(res, fabs(1.0 * R[i].first.first - R[j].first.first));
      if (in(R[j].first.second, R[i].first.second, R[i].second.second) ||
          in(R[j].second.second, R[i].first.second, R[i].second.second))
        res = min(res, fabs(1.0 * R[i].first.first - R[j].first.first));
    } else {
      if (in(R[j].first.second, R[i].first.second, R[i].second.second)) {
        res = min(
            res, d(make_pair(R[i].first.first, R[j].first.second), R[j].first));
        res = min(res, d(make_pair(R[i].first.first, R[j].first.second),
                         R[j].second));
      }
      if (in(R[i].first.first, R[j].first.first, R[j].second.first)) {
        res = min(
            res, d(make_pair(R[i].first.first, R[j].first.second), R[i].first));
        res = min(res, d(make_pair(R[i].first.first, R[j].first.second),
                         R[i].second));
      }
    }
    return res;
  }
  double res = d(R[i].first, R[j].first);
  res = min(res, d(R[i].first, R[j].second));
  res = min(res, d(R[i].second, R[j].first));
  res = min(res, d(R[i].second, R[j].second));
  if (R[j].first.second == R[j].second.second) {
    if (in(R[i].first.first, R[j].first.first, R[j].second.first) ||
        in(R[i].second.first, R[j].first.first, R[j].second.first))
      res = min(res, fabs(1.0 * R[i].first.second - R[j].first.second));
    if (in(R[j].first.first, R[i].first.first, R[i].second.first) ||
        in(R[j].second.first, R[i].first.first, R[i].second.first))
      res = min(res, fabs(1.0 * R[i].first.second - R[j].first.second));
  } else {
    if (in(R[j].first.first, R[i].first.first, R[i].second.first)) {
      res = min(res,
                d(make_pair(R[j].first.first, R[i].first.second), R[j].first));
      res = min(res,
                d(make_pair(R[j].first.first, R[i].first.second), R[j].second));
    }
    if (in(R[i].first.second, R[j].first.second, R[j].second.second)) {
      res = min(res,
                d(make_pair(R[j].first.first, R[i].first.second), R[i].first));
      res = min(res,
                d(make_pair(R[j].first.first, R[i].first.second), R[i].second));
    }
  }
  return res;
}
int main() {
  cin >> A >> B;
  int Ax, Ay, Bx, By;
  cin >> Ax >> Ay >> Bx >> By;
  int n;
  cin >> n;
  R.resize(n);
  for (int i = (0); i < (n); ++i) {
    cin >> R[i].first.first >> R[i].first.second >> R[i].second.first >>
        R[i].second.second;
  }
  R.push_back(make_pair(make_pair(Bx, By), make_pair(Bx, By)));
  if (d_ok(make_pair(Ax, Ay), make_pair(Bx, By))) {
    printf("%.5f\n", d(make_pair(Ax, Ay), make_pair(Bx, By)));
    return 0;
  }
  queue<int> q;
  vector<double> D(n, (2000000000));
  for (int i = (0); i < (n); ++i) {
    if (d_ok(make_pair(Ax, Ay), R[i].first) ||
        d_ok(make_pair(Ax, Ay), R[i].second)) {
      q.push(i);
      D[i] = A + B;
    }
  }
  double Ans = (2000000000);
  const double eps = 1e-7;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    double _r = dst_sgm(v, n);
    if (_r - eps <= A) Ans = min(Ans, D[v] + _r);
    for (int i = (0); i < (n); ++i) {
      double r = dst_sgm(v, i);
      if (r - eps <= A) {
        if (D[i] > D[v] + A + B) {
          D[i] = D[v] + A + B;
          q.push(i);
        }
      }
    }
  }
  if (Ans == (2000000000)) {
    cout << "-1\n";
    return 0;
  }
  printf("%.5f\n", Ans);
  return 0;
}
