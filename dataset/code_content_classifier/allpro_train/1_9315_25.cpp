#include <bits/stdc++.h>
using namespace std;
clock_t startTime;
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
template <typename T, typename U>
inline ostream &operator<<(ostream &_out, const pair<T, U> &_p) {
  _out << _p.first << " " << _p.second;
  return _out;
}
template <typename T, typename U>
inline istream &operator>>(istream &_in, pair<T, U> &_p) {
  _in >> _p.first >> _p.second;
  return _in;
}
template <typename T>
inline ostream &operator<<(ostream &_out, const vector<T> &_v) {
  if (_v.empty()) return _out;
  _out << _v.front();
  for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T>
inline istream &operator>>(istream &_in, vector<T> &_v) {
  for (auto &_i : _v) _in >> _i;
  return _in;
}
template <typename T>
inline ostream &operator<<(ostream &_out, const set<T> &_s) {
  if (_s.empty()) return _out;
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T>
inline ostream &operator<<(ostream &_out, const multiset<T> &_s) {
  if (_s.empty()) return _out;
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T>
inline ostream &operator<<(ostream &_out, const unordered_set<T> &_s) {
  if (_s.empty()) return _out;
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T>
inline ostream &operator<<(ostream &_out, const unordered_multiset<T> &_s) {
  if (_s.empty()) return _out;
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T, typename U>
inline ostream &operator<<(ostream &_out, const map<T, U> &_m) {
  if (_m.empty()) return _out;
  _out << "{\"" << _m.begin()->first << "\", \"" << _m.begin()->second << "\"}";
  for (auto _it = ++_m.begin(); _it != _m.end(); ++_it)
    _out << ", { \"" << _it->first << "\", \"" << _it->second << "\"}";
  return _out;
}
template <typename T, typename U>
inline ostream &operator<<(ostream &_out, const unordered_map<T, U> &_m) {
  if (_m.empty()) return _out;
  _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')';
  for (auto _it = ++_m.begin(); _it != _m.end(); ++_it)
    _out << ", (" << _it->first << ": " << _it->second << ')';
  return _out;
}
template <typename T>
void out(const vector<T> &a, int n) {
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << ' ';
  }
  cout << "\n";
}
template <typename T>
void out(const vector<vector<T>> &a, int n, int m) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
}
long double dist(long double x1, long double y1, long double x2,
                 long double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
void solve() {
  long double ax, ay, bx, by, tx, ty;
  cin >> ax >> ay >> bx >> by >> tx >> ty;
  int n;
  cin >> n;
  vector<long double> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  if (n == 1) {
    cout << dist(x[0], y[0], tx, ty) +
                min(dist(ax, ay, x[0], y[0]), dist(bx, by, x[0], y[0]));
    return;
  }
  long double ans, su = 0;
  vector<long double> drec(n), da(n), db(n);
  const long double c = 2;
  long double ma = -3e18, ma2 = -3e18;
  vector<long double> pre(n), suf(n);
  for (int i = 0; i < n; ++i) {
    drec[i] = dist(x[i], y[i], tx, ty);
    da[i] = drec[i] - dist(x[i], y[i], ax, ay);
    db[i] = drec[i] - dist(x[i], y[i], bx, by);
    su += c * drec[i];
    ma = max(ma, da[i]);
    ma2 = max(ma2, db[i]);
    pre[i] = i == 0 ? db[i] : max(db[i], pre[i - 1]);
  }
  assert(ma != -3e18 && ma2 != -3e18);
  ans = su - ma;
  ans = min(ans, su - ma2);
  for (int i = n - 1; i >= 0; --i) {
    suf[i] = i == n - 1 ? db[i] : max(suf[i + 1], db[i]);
  }
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      ans = min(ans, su - suf[i + 1] - da[i]);
    } else if (i == n - 1) {
      ans = min(ans, su - pre[i - 1] - da[i]);
    } else {
      ans = min(ans, su - max(pre[i - 1], suf[i + 1]) - da[i]);
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  startTime = clock();
  cout << fixed << setprecision(20);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
