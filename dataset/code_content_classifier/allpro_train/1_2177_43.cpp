#include <bits/stdc++.h>
using namespace std;
const long long LLMAX = 2e18;
const int MOD = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 1e6 + 10;
const int hmod1 = 0x48E2DCE7;
const int hmod2 = 0x60000005;
inline long long sqr(long long x) { return x * x; }
inline int sqr(int x) { return x * x; }
inline double sqr(double x) { return x * x; }
long long __gcd(long long a, long long b) {
  return b == 0 ? a : __gcd(b, a % b);
}
long long qpow(long long a, long long n) {
  long long sum = 1;
  while (n) {
    if (n & 1) sum = sum * a % MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return sum;
}
inline int dcmp(double x) {
  if (fabs(x) < eps) return 0;
  return (x > 0 ? 1 : -1);
}
int use[MAXN];
vector<int> ans;
struct Point {
  long long x, y, id;
  Point() { x = y = 0; }
  Point(long long a, long long b) { x = a, y = b; }
  Point operator-(const Point &n) const { return Point(x - n.x, y - n.y); }
  bool operator<(const Point &n) const {
    if (x == n.x) return y < n.y;
    return x < n.x;
  }
} point[MAXN];
int dcmp(long long x) {
  if (x == 0) return 0;
  return x > 0 ? 1 : -1;
}
bool cmp(Point a, Point b) { return a.id < b.id; }
long long cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> point[i].x >> point[i].y, point[i].id = i;
  string s;
  cin >> s;
  sort(point + 1, point + n + 1);
  ans.push_back(point[1].id), use[point[1].id] = 1;
  sort(point + 1, point + n + 1, cmp);
  for (int i = 0; i < s.size(); i++) {
    int k = 0, flag = (s[i] == 'L' ? 1 : -1);
    for (int j = 1; j <= n; j++) {
      if (use[j]) continue;
      if (!k ||
          dcmp(cross(point[k] - point[ans[i]], point[j] - point[k])) != flag)
        k = j;
    }
    ans.push_back(k), use[k] = 1;
  }
  for (int i = 1; i <= n; i++)
    if (!use[i]) ans.push_back(i);
  for (auto i : ans) cout << i << ' ';
  return 0;
}
