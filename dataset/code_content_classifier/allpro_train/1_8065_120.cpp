#include <bits/stdc++.h>
using namespace std;
template <class T>
void pp(T v) {
  for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
    cout << *it << ' ';
  cout << endl;
}
template <class T>
void pp(T v, int n) {
  for (int i = 0; i < (int)n; i++) cout << v[i] << ' ';
  cout << endl;
}
const int INF = 1 << 28;
const double EPS = 1.0e-9;
static const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int main(void) {
  int a, b, x1, y1, x2, y2;
  cin >> a >> b >> x1 >> y1 >> x2 >> y2;
  int add1 = x1 + y1, add2 = x2 + y2;
  int sub1 = x1 - y1, sub2 = x2 - y2;
  int add1_i = add1 / (2 * a);
  if (add1 < 0) add1_i--;
  int add2_i = add2 / (2 * a);
  if (add2 < 0) add2_i--;
  int sub1_i = sub1 / (2 * b);
  if (sub1 < 0) sub1_i--;
  int sub2_i = sub2 / (2 * b);
  if (sub2 < 0) sub2_i--;
  int dx = abs(add1_i - add2_i);
  int dy = abs(sub1_i - sub2_i);
  int ans = max(dx, dy);
  cout << ans << endl;
  return 0;
}
