#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int maxn = 2e3 + 5;
long long Qpower(long long x, long long p, long long mod) {
  long long r = 1;
  while (p) {
    if (p & 1) r = r * x % mod;
    x = x * x % mod;
    p >>= 1;
  }
  return r;
}
long long gcd(long long a, long long b) {
  while (a) {
    long long t = b % a;
    b = a, a = t;
  }
  return b < 0 ? -b : b;
}
struct Node {
  int x, y;
  Node() {}
  Node(int x, int y) : x(x), y(y){};
  bool operator<(const Node &Vn) const {
    return x == Vn.x ? x < Vn.x : y < Vn.y;
  }
} node[maxn];
long long ans, C[maxn][maxn];
int n;
long long Calc(long long a, long long b) {
  return a * (a - 1) / 2 * b * (b - 1) / 2;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  C[0][0] = 1;
  for (int i = 1; i <= 2000; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  }
  for (int i = 1; i <= n; ++i) {
    int x, y;
    cin >> x >> y;
    node[i] = Node(x, y);
  }
  for (int i = 1; i <= n; ++i) {
    vector<double> v;
    for (int j = 1; j <= n; ++j)
      if (i != j) {
        int dx = node[j].x - node[i].x, dy = node[j].y - node[i].y;
        double angle = atan2(dy, dx);
        if (dx <= 0 && dy < 0) {
          angle += 2 * pi;
        }
        v.push_back(angle);
      }
    sort(v.begin(), v.end());
    int sz = v.size(),
        p = lower_bound(v.begin(), v.end(), v[0] + pi) - v.begin();
    for (int j = 0; j < sz; ++j) v.push_back(v[j] + 2 * pi);
    for (int j = 0; j < sz && v[j] <= pi / 2; ++j) {
      while (p < 2 * sz && v[p] < v[j] + pi) ++p;
      ans += Calc(p - 1 - j, n - 2 - (p - 1 - j));
    }
  }
  cout << ans << '\n';
  return 0;
}
