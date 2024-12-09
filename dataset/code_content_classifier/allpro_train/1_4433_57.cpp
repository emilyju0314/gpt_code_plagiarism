#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;
using vld = vector<ld>;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    int gor = b - a;
    int ver = d - c;
    x += gor;
    y += ver;
    cout << ((x < x1 || x2 < x || y < y1 || y2 < y ||
              (!(x2 - x1) && (a || b)) || (!(y2 - y1) && (c || d)))
                 ? "NO"
                 : "YES")
         << '\n';
  }
  return 0;
}
