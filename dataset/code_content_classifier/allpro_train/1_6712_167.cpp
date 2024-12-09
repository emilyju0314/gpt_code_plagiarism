#include <bits/stdc++.h>
using namespace std;
int n, R, C, k;
long long int ans = 0;
int pre[3000], nxt[3000];
int nxtk[3000], pos[3000];
struct point {
  int x, y, id;
} poi[3000];
inline bool compx(point p1, point p2) { return p1.x < p2.x; }
inline bool compy(point p1, point p2) { return p1.y < p2.y; }
inline int calc(int i) {
  if (i < 0 || i >= n) return 0;
  int a = pos[i] - (pre[i] < 0 ? 0 : pos[pre[i]]);
  int b = (nxtk[i] < n ? C - pos[nxtk[i]] + 1 : 0);
  return a * b;
}
int main(void) {
  scanf("%d%d%d%d", &R, &C, &n, &k);
  for (int i = 0; i < n; i++) scanf("%d%d", &poi[i].x, &poi[i].y);
  for (int j = R; j > 0; j--) {
    while (n > 0 && poi[n - 1].x > j) n--;
    sort(poi, poi + n, compy);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      pre[i] = i - 1;
      nxt[i] = i + 1;
      nxtk[i] = i + k - 1;
      pos[i] = poi[i].y;
      poi[i].id = i;
    }
    for (int i = 0; i < n; i++) sum += calc(i);
    sort(poi, poi + n, compx);
    for (int i = 1, p = 0; i <= j; i++) {
      for (; p < n && poi[p].x < i; p++) {
        int d = poi[p].id, t = d;
        for (int i = 0; i < k && t != -1; i++) {
          sum -= calc(t);
          if (nxtk[t] < n) nxtk[t] = nxt[nxtk[t]];
          sum += calc(t);
          t = pre[t];
        }
        if (pre[d] != -1) nxt[pre[d]] = nxt[d];
        if (nxt[d] < n) pre[nxt[d]] = pre[d];
      }
      ans += sum;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
