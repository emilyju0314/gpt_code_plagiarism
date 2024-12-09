#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int maxn = 200009;
const int inf = 100000009;
const long long mod = 1e9 + 7;
int op[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    scanf("%d", &n);
    int a = 0, b = 0;
    for (int i = 1; i <= 2 * n; ++i) {
      scanf("%d", &op[i]);
      if (op[i] == 1)
        ++a;
      else
        ++b;
    }
    if (a == b) {
      puts("0");
      continue;
    }
    int ans = 2 * n;
    int ta = 0, tb = 0;
    for (int i = n; i >= 1; --i) {
      if (op[i] == 1)
        ++ta;
      else
        ++tb;
      if (a - ta == b - tb) {
        ans = min(ans, n - i + 1);
        break;
      }
    }
    ta = 0, tb = 0;
    for (int i = n + 1; i <= 2 * n; ++i) {
      if (op[i] == 1)
        ++ta;
      else
        ++tb;
      if (a - ta == b - tb) {
        ans = min(ans, i - n);
        break;
      }
    }
    map<int, int> yu;
    ta = 0;
    tb = 0;
    for (int i = n + 1; i <= 2 * n; ++i) {
      if (op[i] == 1)
        ++ta;
      else
        ++tb;
      if (!yu.count(ta - tb)) yu[ta - tb] = i - n;
    }
    ta = 0;
    tb = 0;
    for (int i = n; i >= 1; --i) {
      if (op[i] == 1)
        ++ta;
      else
        ++tb;
      int k = a - b - (ta - tb);
      if (yu.count(k)) {
        ans = min(ans, n + 1 - i + yu[k]);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
