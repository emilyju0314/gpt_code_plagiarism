#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& o, const vector<T>& v) {
  int b = 0;
  for (const auto& a : v) o << (b++ ? " " : "") << a;
  return o;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long Y, B;
  cin >> Y >> B;
  long long x, y, z;
  cin >> x >> y >> z;
  cout << -min(0LL, Y - (2 * x) - y) - min(0LL, B - y - (3 * z)) << endl;
  return 0;
}
