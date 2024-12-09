#include <bits/stdc++.h>
using namespace std;
const int INF = 1000001000;
const long long INFll = 1ll * INF * INF;
const long double ldINF = 1e+018;
const long double EPS = 0.000000001;
const int sdx[4] = {-1, 0, 1, 0};
const int sdy[4] = {0, 1, 0, -1};
template <typename T>
ostream& operator<<(ostream& out, pair<T, T>& a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T>
istream& operator>>(istream& in, pair<T, T>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& a) {
  for (int i = 0; i < a.size(); ++i) in >> a[i];
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> a) {
  for (int i = 0; i < a.size(); ++i)
    if (i == a.size() - 1)
      out << a[i];
    else
      out << a[i] << " ";
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int> > a(k);
  cin >> a;
  map<pair<int, int>, pair<long long, char> > w;
  int dir = 0;
  w[make_pair(0, 0)] = make_pair(0, dir);
  int x = 0, y = 0;
  long long time = 0;
  set<pair<int, int> > s;
  s.insert(make_pair(0, 0));
  while (true) {
    if ((x == n && y == m) || (x == n && y == 0) || (x == 0 && y == m)) break;
    int cntx, cnty;
    if (dir == 0) {
      cntx = n - x;
      cnty = m - y;
    }
    if (dir == 1) {
      cntx = n - x;
      cnty = y;
    }
    if (dir == 2) {
      cntx = x;
      cnty = y;
    }
    if (dir == 3) {
      cntx = x;
      cnty = m - y;
    }
    int cnt = min(cntx, cnty);
    if (dir == 0) x += cnt, y += cnt;
    if (dir == 1) x += cnt, y -= cnt;
    if (dir == 2) x -= cnt, y -= cnt;
    if (dir == 3) x -= cnt, y += cnt;
    time += cnt;
    if (dir == 0) {
      if (y == m)
        dir = 1;
      else
        dir = 3;
    } else if (dir == 1) {
      if (x == n)
        dir = 2;
      else
        dir = 0;
    } else if (dir == 2) {
      if (x == 0)
        dir = 1;
      else
        dir = 3;
    } else if (dir == 3) {
      if (x == 0)
        dir = 0;
      else
        dir = 2;
    }
    w[make_pair(x, y)] = make_pair(time, dir);
    s.insert(make_pair(x, y));
  }
  vector<long long> ans(k, -1);
  for (int i = 0; i < k; i++) {
    int x = a[i].first, y = a[i].second;
    long long res = INFll;
    int cnt = min(x, y);
    int nx = x - cnt, ny = y - cnt;
    if (s.count(make_pair(nx, ny)) && w[make_pair(nx, ny)].second == 0)
      res = min(res, w[make_pair(nx, ny)].first + cnt);
    cnt = min(x, m - y);
    nx = x - cnt, ny = y + cnt;
    if (s.count(make_pair(nx, ny)) && w[make_pair(nx, ny)].second == 1)
      res = min(res, w[make_pair(nx, ny)].first + cnt);
    cnt = min(n - x, m - y);
    nx = x + cnt, ny = y + cnt;
    if (s.count(make_pair(nx, ny)) && w[make_pair(nx, ny)].second == 2)
      res = min(res, w[make_pair(nx, ny)].first + cnt);
    cnt = min(n - x, y);
    nx = x + cnt, ny = y - cnt;
    if (s.count(make_pair(nx, ny)) && w[make_pair(nx, ny)].second == 3)
      res = min(res, w[make_pair(nx, ny)].first + cnt);
    if (res != INFll) ans[i] = res;
  }
  for (int i = 0; i < k; i++) cout << ans[i] << endl;
  return 0;
}
