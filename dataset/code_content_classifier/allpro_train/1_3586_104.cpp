#include <bits/stdc++.h>
using namespace std;
int key[300005], pos[300005], pre[300005], nxt[300005], n;
const int maxj = 60;
bool cmp(int x, int y) { return key[x] < key[y]; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &key[i]);
    pos[i] = i;
    pre[i] = i - 1;
    nxt[i] = i + 1;
  }
  sort(pos + 1, pos + n + 1, cmp);
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    int pnt1 = pos[i], pnt2 = pos[i];
    double lsum = 0, rsum = 0, haha = 1;
    for (int j = 1; j <= maxj; j++) {
      if (pnt1) lsum += (pnt1 - pre[pnt1]) * haha, pnt1 = pre[pnt1];
      if (pnt2 <= n) rsum += (nxt[pnt2] - pnt2) * haha, pnt2 = nxt[pnt2];
      haha /= 2;
    }
    ans += lsum * rsum * key[pos[i]] / 2 / n / n;
    nxt[pre[pos[i]]] = nxt[pos[i]];
    pre[nxt[pos[i]]] = pre[pos[i]];
  }
  printf("%.15lf\n", ans);
  return 0;
}
