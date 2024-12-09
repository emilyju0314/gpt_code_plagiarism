#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300005, INF = 1e9 + 2;
int a[MAXN][10];
int mark[305];
int n, m;
int ans1 = 1, ans2 = 1;
bool check(int x) {
  fill(mark, mark + 300, 0);
  for (int i = 0; i < n; i++) {
    int b = 0;
    for (int j = 0; j < m; j++)
      if (a[i][j] >= x)
        b = b * 2 + 1;
      else
        b *= 2;
    mark[b] = i + 1;
  }
  int pm = (1 << m);
  for (int i = 0; i < pm; i++)
    for (int j = i; j < pm; j++)
      if (mark[i] && mark[j] && (i | j) == pm - 1) {
        ans1 = mark[i];
        ans2 = mark[j];
        return true;
      }
  return false;
}
inline int in() {
  int x, y;
  y = scanf("%d", &x);
  return x;
}
int main() {
  n = in(), m = in();
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) a[i][j] = in();
  int lo = 0, hi = INF;
  while (hi - lo > 1) {
    int mid = (lo + hi) / 2;
    if (check(mid))
      lo = mid;
    else
      hi = mid;
  }
  cout << ans1 << ' ' << ans2 << endl;
  return 0;
}
