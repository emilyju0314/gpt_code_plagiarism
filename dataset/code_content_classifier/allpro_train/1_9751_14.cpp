#include <bits/stdc++.h>
using namespace std;
const int MAXN = 111111;
struct pt {
  long long x;
  long long y;
};
long long sq(long long x) { return (x * x); }
long double dis(pt c, pt d) { return (sqrt(sq(d.y - c.y) + sq(d.x - c.x))); }
pt ar[MAXN];
long double r[MAXN];
pair<long double, int> br[MAXN], cr[MAXN];
int main() {
  int i, n;
  pt a, b, t;
  cin >> a.x;
  cin >> a.y;
  cin >> b.x;
  cin >> b.y;
  cin >> t.x;
  cin >> t.y;
  scanf("%d", &n);
  for (i = 0; i <= n - 1; i++) {
    cin >> ar[i].x;
    cin >> ar[i].y;
  }
  for (i = 0; i <= n - 1; i++) {
    r[i] = dis(t, ar[i]);
  }
  long double ans = 0.0L;
  for (i = 0; i <= n - 1; i++) ans += 2.0L * r[i];
  for (i = 0; i <= n - 1; i++) {
    br[i].first = r[i] - dis(a, ar[i]);
    br[i].second = i;
  }
  sort(br, br + n);
  reverse(br, br + n);
  for (i = 0; i <= n - 1; i++) {
    cr[i].first = r[i] - dis(b, ar[i]);
    cr[i].second = i;
  }
  sort(cr, cr + n);
  reverse(cr, cr + n);
  long double val = max(cr[0].first, br[0].first);
  long double tval;
  if (n > 1) {
    if (cr[0].second != br[0].second) {
      tval = cr[0].first + br[0].first;
      val = max(val, tval);
    } else {
      if (cr[0].second != br[1].second) {
        tval = cr[0].first + br[1].first;
        val = max(val, tval);
      }
      if (cr[1].second != br[0].second) {
        tval = cr[1].first + br[0].first;
        val = max(val, tval);
      }
    }
  }
  ans -= val;
  cout << fixed << setprecision(15) << ans << "\n";
  return 0;
}
