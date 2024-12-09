#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream& operator<<(ostream& cout, pair<A, B> const& p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream& operator<<(ostream& cout, vector<A> const& v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
void file_io(string taskname) {
  string fin = taskname + ".in";
  string fout = taskname + ".out";
  const char* FIN = fin.c_str();
  const char* FOUT = fout.c_str();
  freopen(FIN, "r", stdin);
  freopen(FOUT, "w", stdout);
  fast_io();
}
const long double EPS = 1e-12;
long double dist(long double a, long double b) { return sqrt(a * a + b * b); }
long double closest(long double a, long double b, long double c,
                    long double d) {
  if (dist(a - c, b - d) < EPS) return 0;
  if (dist(a, b) < EPS || dist(c, d) < EPS) return 0;
  long double d1 = dist(a, b);
  long double d2 = dist(c, d);
  long double len = abs(a * d - b * c) / dist(a - c, b - d);
  long double ca = dist(a - c, b - d);
  if (d1 * d1 <= d2 * d2 + ca * ca && d2 * d2 <= d1 * d1 + ca * ca) {
    return len;
  } else {
    return min(d1, d2);
  }
}
int main() {
  fast_io();
  int n;
  cin >> n;
  long long d1, d2;
  cin >> d1 >> d2;
  vector<pair<long long, long long> > coords;
  for (int i = 0; i < (n); i++) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    coords.push_back(make_pair(a - c, b - d));
  }
  bool ready = true;
  vector<long double> dists;
  dists.push_back(dist(coords[0].first, coords[0].second));
  for (int i = 0; i < (n - 1); i++) {
    dists.push_back(closest(coords[i].first, coords[i].second,
                            coords[i + 1].first, coords[i + 1].second));
    dists.push_back(dist(coords[i + 1].first, coords[i + 1].second));
  }
  int cnt = 0;
  for (int i = 0; i < (dists.size()); i++) {
    if (dists[i] <= d1) {
      if (ready) cnt++;
      ready = false;
    } else if (dists[i] > d2) {
      ready = true;
    }
  }
  cout << cnt << "\n";
}
