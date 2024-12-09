#include <bits/stdc++.h>
using namespace std;
int main() {
  long long m, h1, a1, x1, y1, h2, a2, x2, y2;
  cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;
  long long st1 = -1, len1 = -1, st2 = -1, len2 = -1;
  long long cnt = 0;
  while (cnt <= 2 * m) {
    if (h1 == a1) {
      if (st1 == -1)
        st1 = cnt;
      else if (len1 == -1)
        len1 = cnt - st1;
    }
    if (h2 == a2) {
      if (st2 == -1)
        st2 = cnt;
      else if (len2 == -1)
        len2 = cnt - st2;
    }
    cnt++;
    h1 = (x1 * h1 + y1) % m;
    h2 = (x2 * h2 + y2) % m;
  }
  if (st1 == -1 || st2 == -1) {
    printf("-1\n");
    return 0;
  } else {
    for (int i = 1; i <= 2 * m; i++) {
      if (st1 == st2) {
        printf("%lld\n", st1);
        return 0;
      }
      if (st1 < st2)
        st1 += len1;
      else
        st2 += len2;
    }
    printf("-1\n");
  }
  return 0;
}
