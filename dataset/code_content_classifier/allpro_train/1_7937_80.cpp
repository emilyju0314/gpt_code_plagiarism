#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const long long mod = 1e9 + 7;
const int N = 1e6 + 10;
pair<int, int> t[N];
int main() {
  int n, a, b, c, d, tot, len;
  scanf("%d%d%d%d%d%d%d", &n, &a, &b, &c, &d, &tot, &len);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &t[i].first, &t[i].second);
  }
  int now = 1;
  long long minn = inf;
  long long ltot = tot;
  long long ntot = 0;
  t[0].first = -1;
  for (int i = 1; i <= n; i++) {
    if (ltot < 0) {
      printf("-1");
      return 0;
    }
    while (now <= n && t[now].first - t[i - 1].first - 1 <= len) {
      ntot += t[now].second * c + (t[now++].second - 1) * d;
      minn = min(minn, ntot);
    }
    if (ltot + minn >= 0) {
      printf("%d", t[i - 1].first + 1);
      return 0;
    }
    ntot -= t[i].second * c + (t[i].second - 1) * d;
    minn -= t[i].second * c + (t[i].second - 1) * d;
    ltot += t[i].second * a + (t[i].second - 1) * b;
  }
  if (ltot < 0) {
    printf("-1");
    return 0;
  }
  printf("%d", t[n].first + 1);
  return 0;
}
