#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")\n";
}
template <class T>
ostream &operator<<(ostream &os, set<T> V) {
  os << "[";
  for (auto vv : V) os << vv << ", ";
  return os << "\b\b]\n";
}
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  for (auto vv : V) os << vv << ' ';
  return os << "\n";
}
template <class K, class X>
ostream &operator<<(ostream &os, map<K, X> V) {
  os << "[";
  for (auto vv : V) os << vv << ", ";
  return os << "\b\b]\n";
}
long long int ceildiv(long long int n, long long int f) {
  if (n % f) {
    return n / f + 1;
  } else
    return n / f;
}
int main() {
  long long int n, d, m, x, y;
  cin >> n >> d >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    long long int add = x + y, sub = y - x;
    if (add >= d && add <= (2 * n - d) && sub >= -d && sub <= d)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
